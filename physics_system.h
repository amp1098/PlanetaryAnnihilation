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


void physics_update(int ID) { // see comments in physics_system.h
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

		// updating physics components via kinematic equations
		// this cascades changes in the force component to the accel, vel, and pos components
		// to move physics objects, just change the force component of a given entity ID
		// and call this system to move it around :)

		for (int i = 0; i < ECS_map.size(); i++) { // iterating through ID's
			//std::cout << ECS_map[i].m_name << std::endl;

			if (ECS_map[i].m_name == "Planetoid") { // check if entity is named "planet"

				force += univ_grav(mass, ECS_map[i].m_mass, position, ECS_map[i].m_position); // add gravity to force vector

			};

		};

		acceleration = force / mass;
		velocity += acceleration * dt;
		position += velocity * dt + acceleration * 0.5 * dt * dt;

		// angular kinematics (torques, angular velocity, etc)
		// same principle as previous stuff

		float moment{ moment_of_inertia(mass, shape) }; // moment of inertia used for torque stuff

		angacc = torque / moment;
		angvel += angacc * dt;
		angle += angvel * dt + angacc * 0 * dt * dt;

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

