#ifndef SHIP_H
#define SHIP_H

#include <raylib.h>
#include "gen_polygon.h"
#include <iostream>
#include <vector>
#include "ECS.h"

class ship { // spaceship class
public:
	int m_ID;
	std::string m_name;
	float m_mass;
	Color m_color;

	// LINEAR COMPONENTS
	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	Vector2 m_force;

	// ANGULAR COMPONENTS
	float m_angle;
	float m_angvel;
	float m_angacc;
	float m_torque;

	std::vector<Vector2> m_shape; // vector of Vector2 objects describing entity vertices
	int m_target_id; // missiles and lasers target objects, planetoids do not
	bool m_is_targeted; // anything can be targeted
	bool m_has_gravity; // Planetoids have gravity, ships and stuff do not
	bool m_is_movable;

	ship(
		int ID, std::string name, float mass, Color color,
		Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
		float angle, float angvel, float angacc, float torque,
		std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity, bool is_movable
	)
	{ // constructor, takes arguments
		m_ID = ID;
		m_name = name;
		m_mass = mass;
		m_color = color;

		m_position = position;
		m_velocity = velocity;
		m_acceleration = acceleration;
		m_force = force;

		m_angle = angle;
		m_angvel = angvel;
		m_angacc = angacc;
		m_torque = torque;

		m_shape = shape;
		m_target_id = target_id;
		m_is_targeted = is_targeted;
		m_has_gravity = has_gravity;
		m_is_movable = is_movable;

		set_entity_components( // ECS gets updated upon object creation
			m_ID, m_name, m_mass, m_color,
			m_position, m_velocity, m_acceleration, m_force,
			m_angle, m_angvel, m_angacc, m_torque,
			m_shape,
			m_target_id, m_is_targeted, m_has_gravity, m_is_movable
		);
	};

	~ship() { // destructor, object removal also  removes it from ECS
		destroy_entity(m_ID);
	};

};

#endif