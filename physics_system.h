#ifndef PHYSICS_SYSTEM_H
#define PHYSICS_SYSTEM_H

#include "ECS.h"
#include <raymath.h>

float const G = 1000.0f; // for gravity scaling
float const dt = 0.1f; // for integration

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

	for (int i = 0; i < std::size(points); i++) {
		moment += mass_of_each_point * Vector2LengthSqr(points[i]);
	};

	return moment;
};

float angle_of_vec_diff(Vector2 vec1, Vector2 vec2) { // returns angle of vector difference of vec1 and vec2
	Vector2 vec_res{ vec1 - vec2 };

	return clamp_angle( atan2(vec_res.y, vec_res.x) );
};

float better_sign_function(float x) {
	x = 2 * std::signbit(x) - 1;
	return x;
};

float torque_to_angle(float target_angle, float current_angle, float moment) { // this will apply a torque to a rotating system such that its angle reaches a target angle
	float torque_aim{}; // torque needed to aim at target angle from current angle
	float fudge_factor{1000.0f}; // fudging coefficient, wont change for now
	
	float angle_diff{ current_angle - target_angle };

	//torque_aim = - better_sign_function(angle_diff) * fudge_factor; // crap aiming algorithm, maybe use for stupid enemies
	torque_aim = fudge_factor * angle_diff / (2 * PI);

	return torque_aim;

};

void physics_update(int ID) { // updates physics components when called
	// updating physics components via kinematic equations
	// this cascades changes in the force component to the accel, vel, and pos components
	// to move physics objects, just change the force component of a given entity ID
	// and call this system to move it around :)

	if (ECS_map[ID].m_name != "Planetoid") {
		// initializing variables
		float mass{ ECS_map[ID].m_mass };
		Vector2 position{ ECS_map[ID].m_position };
		Vector2 velocity{ ECS_map[ID].m_velocity };
		Vector2 acceleration{ ECS_map[ID].m_acceleration };
		Vector2 force{ ECS_map[ID].m_force };
		std::vector<Vector2> shape{ ECS_map[ID].m_shape };
		float angle{ ECS_map[ID].m_angle };
		float angvel{ ECS_map[ID].m_angvel };
		float angacc{ ECS_map[ID].m_angacc };
		float torque{ ECS_map[ID].m_torque };
		int target_ID{ ECS_map[ID].m_target_id };

		// == TARGETING ==
		if (target_ID != 0) { // if ID is 0, it's not targeting anything
			Vector2 target_position{ ECS_map[target_ID].m_position };

			// angle to target is the angle of the vector difference of targeting entity and targeted entity

			float target_angle{
				angle_of_vec_diff(position, target_position)
			};

			torque += torque_to_angle(angle, target_angle + PI, moment_of_inertia(mass, shape));

			std::cout << "\r" << "angle : " << angle << " | tar angle : " << target_angle << std::flush;
		};
		

		// == GRAVITY ==

		for (int i = 0; i < ECS_map.size(); i++) { // iterating through ID's
			//std::cout << ECS_map[i].m_name << std::endl;

			if (ECS_map[i].m_has_gravity) { // check if entity has gravity attraction enabled

				force += univ_grav(mass, ECS_map[i].m_mass, position, ECS_map[i].m_position); // add gravity to force vector

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

		update_entity_components(
			ID,
			ECS_map[ID].m_name,
			mass,
			ECS_map[ID].m_color,
			position, velocity, acceleration, force,
			angle, angvel, angacc, torque,
			shape,
			ECS_map[ID].m_target_id, ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity
		);
	};
};

#endif // !PHYSICS_SYSTEM_H

