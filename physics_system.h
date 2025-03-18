#ifndef PHYSICS_SYSTEM_H
#define PHYSICS_SYSTEM_H

#include "ECS.h"
#include <raymath.h>

float const G = 1000.0f; // for gravity scaling
float const dt = 0.01f; // for integration

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

void physics_update(int ID) {

	// initializing local vars
	float mass{ ECS_map[ID].m_mass };
	Vector2 position{ ECS_map[ID].m_position };
	Vector2 velocity{ ECS_map[ID].m_velocity };
	Vector2 acceleration{ ECS_map[ID].m_acceleration };
	Vector2 force{ ECS_map[ID].m_force };
	
	// kinematics
	acceleration += acceleration + force / mass;
	velocity += velocity + acceleration * dt;
	position += position + velocity * dt + acceleration * 0.5 * dt * dt;

	// shoving components back into ECS
	ECS_map[ID].m_mass = mass;
	ECS_map[ID].m_position = position;
	ECS_map[ID].m_velocity = velocity;
	ECS_map[ID].m_acceleration = acceleration;
	ECS_map[ID].m_force = force;

};

#endif // !PHYSICS_SYSTEM_H

