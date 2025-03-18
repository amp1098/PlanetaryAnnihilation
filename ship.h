#ifndef SHIP_H
#define SHIP_H

#include <raylib.h>
#include "gen_polyon.h"
#include <iostream>

class ship { // spaceship class
public:
	int m_ID;
	float m_mass;
	Vector2 m_position;
	Vector2 m_velocity; 
	Vector2 m_acceleration; 
	// TODO: add shape component? (may not be needed)
	int m_target_id;
	bool m_is_targeted;
	bool m_has_gravity; // false for ship

	ship(
		int ID, float mass, 
		Vector2 position, Vector2 velocity, Vector2 acceleration,
		int target_id, bool is_targeted
	) {
		m_ID = ID;
		m_mass = mass;
		m_position = position;
		m_velocity = velocity;
		m_acceleration = acceleration;
		m_target_id = target_id;
		m_is_targeted = is_targeted;
		m_has_gravity = false;

		gen_polygon shape(
			{ {50.0f, 0.0f}, {-50.0f, 0.0f}, {0.0f, 86.0f} }, BLUE
		);

		shape.translate(m_position.x, m_position.y);

		shape.draw();

		std::cout << m_position.x << std::endl;
	};
};

#endif