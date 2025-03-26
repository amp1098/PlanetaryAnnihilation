#include "ECS_obj.h"
#include <raymath.h>
#include "useful_functions.h"
#include "physics_system.h"

Vector2 univ_grav(float m1, float m2, Vector2 pos1, Vector2 pos2) { // returns gravity force vector from m1 to m2
	float gravity_scalar;
	Vector2 relative_position;
	float distance;
	Vector2 norm_rel_position; // unit vector pointing from m1 to m2
	Vector2 gravity_force_vector;


	relative_position = pos1 - pos2;
	distance = Vector2Length(relative_position) + 50.0f; // +50.0f prevents div by 0 singularity since magnitudes are positive
	norm_rel_position = relative_position / distance; // initialized unit vector from m1 to m2

	gravity_scalar = -1 * G * m1 * m2;

	gravity_force_vector = norm_rel_position * gravity_scalar / (distance * distance);

	return gravity_force_vector;

};

float moment_of_inertia(float mass_of_each_point, std::vector<Vector2> points) { // for uniform point masses, assuming points are relative to COM
	float moment{};

	Vector2 center_of_points{}; // we can subtract this from each element in points to move to {0,0}

	for (int i = 0; i < std::size(points); i++) {
		moment += mass_of_each_point * Vector2LengthSqr(points[i] - center_of_points);
	};

	return moment;
};

float angle_of_vec_diff(Vector2 vec1, Vector2 vec2) { // returns angle of vector difference of vec1 and vec2
	Vector2 vec_res{ vec1 - vec2 };

	return clamp_angle(atan2(vec_res.y, vec_res.x) + PI); // the PI is needed due to left handed coordinate system
};

float better_sign_function(float x) {
	x = 2 * std::signbit(x) - 1;
	return x;
};

void physics_update(int ID) { // updates physics components when called
	// updating physics components via kinematic equations
	// this cascades changes in the force component to the accel, vel, and pos components
	// to move physics objects, just change the force component of a given entity ID
	// and call this system to move it around :)

	ECS_obj.get_entity_components(ID);

	if (ECS_obj.get_entity_components(ID).m_name != "Planetoid") {
		// initializing variables

		float mass{ ECS_obj.get_entity_components(ID).m_mass };
		Vector2 position{ ECS_obj.get_entity_components(ID).m_position };
		Vector2 velocity{ ECS_obj.get_entity_components(ID).m_velocity };
		Vector2 acceleration{ ECS_obj.get_entity_components(ID).m_acceleration };
		Vector2 force{ ECS_obj.get_entity_components(ID).m_force };
		std::vector<Vector2> shape{ ECS_obj.get_entity_components(ID).m_shape };
		float angle{ ECS_obj.get_entity_components(ID).m_angle };
		float angvel{ ECS_obj.get_entity_components(ID).m_angvel };
		float angacc{ ECS_obj.get_entity_components(ID).m_angacc };
		float torque{ ECS_obj.get_entity_components(ID).m_torque };
		int target_ID{ ECS_obj.get_entity_components(ID).m_target_id };

		// == TARGETING ==
		if (target_ID != 0) { // if ID is 0, it's not targeting anything

			float spring_constant{ 10000.0f }; // spring constant for damped rotations

			float damping{ 2 * sqrt(spring_constant * moment_of_inertia(mass, shape)) }; // see ideas.txt

			Vector2 target_position{ ECS_obj.get_entity_components(target_ID).m_position };

			// angle to target is the angle of the vector difference of targeting entity and targeted entity

			float target_angle{
				angle_of_vec_diff(position, target_position)
			};

			torque += -spring_constant * (angle - target_angle) - damping * angvel; // see ideas.txt

			std::cout << "\r" << "angle : " << angle << " | tar angle : " << target_angle << std::flush;
		};


		// == GRAVITY ==

		for (int i = 0; i < ECS_obj.number_of_entities(); i++) { // iterating through ID's
			//std::cout << ECS_map[i].m_name << std::endl;

			if (ECS_obj.get_entity_components(i).m_has_gravity) { // check if entity has gravity attraction enabled

				force += univ_grav(mass, ECS_obj.get_entity_components(i).m_mass, position, ECS_obj.get_entity_components(i).m_position); // add gravity to force vector

			};
		};

		// == KINEMATICS ==

		acceleration = force / mass;
		velocity += acceleration * dt;
		position += velocity * dt + acceleration * 0.5 * dt * dt;

		// angular kinematics (torques, angular velocity, etc)
		// same principle as previous stuff

		float moment{ moment_of_inertia(mass, shape) }; // moment of inertia used for torque stuff

		angacc = torque / moment;
		angvel += angacc * dt;
		angle += angvel * dt + angacc * 0 * dt * dt;

		// == UPDATING ECS ==

		ECS_obj.update_entity_components(
			ID,
			ECS_obj.get_entity_components(ID).m_name,
			mass,
			ECS_obj.get_entity_components(ID).m_color,
			position, velocity, acceleration, force,
			angle, angvel, angacc, torque,
			shape,
			ECS_obj.get_entity_components(ID).m_target_id, ECS_obj.get_entity_components(ID).m_is_targeted, ECS_obj.get_entity_components(ID).m_has_gravity, ECS_obj.get_entity_components(ID).m_is_movable
		);
	};
};