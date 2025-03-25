#ifndef PLANETOID_H
#define PLANETOID_H

#include <raylib.h>
#include "gen_polygon.h"
#include <iostream>
#include <vector>
#include "ECS_obj.h"

class Planetoid { // Planetoid class
public:
	int m_ID;
	std::string m_name;
	float m_mass;
	Color m_color;

	// LINEAR COMPONENTS
	Vector2 m_position;

	// PHYSICS STUFF (KEEP SET TO ZERO)
	Vector2 m_force{};
	float m_torque{};

	std::vector<Vector2> m_shape; // vector of Vector2 objects describing entity vertices
	bool m_is_targeted; // anything can be targeted
	bool m_has_gravity; // Planetoids have gravity, ships and stuff do not
	bool m_is_movable;
	Planetoid(
		int ID, std::string name, float mass, Color color,
		Vector2 position,
		std::vector<Vector2> shape, bool is_targeted, bool has_gravity
	)
	{ // constructor, takes arguments
		m_ID = ID;
		m_name = "Planetoid";
		m_mass = mass;
		m_color = color;

		m_position = position;

		m_force = { 0.0f, 0.0f };
		m_torque = 0.0f;

		m_shape = shape;

		m_is_targeted = is_targeted;
		m_has_gravity = has_gravity;
		m_is_movable = false;

		ECS_obj.set_entity_components( // ECS gets updated upon object creation
			m_ID, m_name, m_mass, m_color,
			m_position, {0.0f, 0.0f}, { 0.0f, 0.0f }, { 0.0f, 0.0f },
			0.0f, 0.0f, 0.0f, 0.0f,
			m_shape,
			0, m_is_targeted, m_has_gravity, m_is_movable
		);
	};



};

#endif
