#ifndef PHYSICS_SYSTEM_H
#define PHYSICS_SYSTEM_H

#include "ECS.h"
#include <raymath.h>

float const G = 1000.0f;

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

	m_force = vector_math.vec2add(// works with first item in planetoids vector
		m_force,
		univ_grav(m_drymass + m_fuelmass, m_planetoids[0].m_mass, m_position, m_planetoids[0].m_position)
	);

	// updating acceleration via force / mass = acceleration
	m_acceleration = vector_math.vec2scale(m_force, 1 / (m_fuelmass + m_drymass));

	// updating velocity via kinematic equations
	m_velocity = vector_math.vec2add(m_velocity, vector_math.vec2scale(m_acceleration, dt));

	// updating position via kinetmatic equations
	m_position = vector_math.vec2add(m_position, vector_math.vec2add(vector_math.vec2scale(m_velocity, dt), vector_math.vec2scale(m_acceleration, dt * dt * 0.5)));
};

#endif // !PHYSICS_SYSTEM_H

