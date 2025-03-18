#ifndef ENT_ROW_H
#define ENT_ROW_H

#include <raylib.h>
#include <vector>

class entity_row { // contains components for physics objects
public:

	float m_mass;
	Vector2 m_position;
	Vector2 m_velocity; // 0 vector for planetoids
	Vector2 m_acceleration; // 0 vector for planetoids
	// TODO: add shape component? (may not be needed)
	int m_target_id; // missiles and lasers target objects, planetoids do not
	bool m_is_targeted; // anything can be targeted
	bool m_has_gravity; // Planetoids have gravity, ships and stuff do not

	entity_row(
		float mass, Vector2 position, Vector2 velocity, Vector2 acceleration,
		int target_id, bool is_targeted, bool has_gravity
		) {
		m_mass = mass;
		m_position = position;
		m_velocity = velocity;
		m_acceleration = acceleration;
		m_target_id = target_id;
		m_is_targeted = is_targeted;
		m_has_gravity = has_gravity;
	};
};

#endif