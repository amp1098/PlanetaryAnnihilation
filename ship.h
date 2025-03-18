#ifndef SHIP_H
#define SHIP_H

#include <raylib.h>
#include "gen_polyon.h"
#include <iostream>
#include <vector>
#include "ECS.h"

class ship { // spaceship class
public:
	int m_ID;
	float m_mass;
	Color m_color;
	Vector2 m_position;
	Vector2 m_velocity; 
	Vector2 m_acceleration; 
	std::vector<Vector2> m_shape;
	int m_target_id;
	bool m_is_targeted;
	bool m_has_gravity; // false for ship

	ship(
		int ID, float mass, Color color,
		Vector2 position, Vector2 velocity, Vector2 acceleration,
		std::vector<Vector2> shape, int target_id, bool is_targeted
	) {
		m_ID = ID;
		m_mass = mass;
		m_color = color;
		m_position = position;
		m_velocity = velocity;
		m_acceleration = acceleration;
		m_shape = shape;
		m_target_id = target_id;
		m_is_targeted = is_targeted;
		m_has_gravity = false;

		set_entity_components( // ECS gets updated upon object creation
			m_ID, m_mass, m_color,
			m_position, m_velocity, m_acceleration,
			m_shape,
			m_target_id, m_is_targeted, m_has_gravity
		);
	};

	
};

#endif