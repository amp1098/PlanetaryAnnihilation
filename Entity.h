#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>
#include <vector>
#include <string>
#include "ECS.h"

class Entity { // Class for creating entities and storing them in ECS
public:
	bool m_show_on_screen;
	int m_ID{};
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

	Entity() {//default constructor
		m_ID = 0;
		m_show_on_screen = false;
		m_name = "";
		m_mass = 1.0f;
		m_color = PURPLE;

		m_position = { 0.0f, 0.0f };
		m_velocity = { 0.0f, 0.0f };
		m_acceleration = { 0.0f, 0.0f };
		m_force = { 0.0f, 0.0f };

		m_angle = 0.0f;
		m_angvel = 0.0f;
		m_angacc = 0.0f;
		m_torque = 0.0f;

		m_shape = { {30.0f, 0.0f}, {-30.0f, 0.0f}, {0.0f, 30.0f} };
		m_target_id = 0;
		m_is_targeted = false;
		m_has_gravity = false;
	};

	void set_components(
		int ID = 0, bool show_on_screen = false, std::string name = "empty", float mass = 0.0f, Color color = PURPLE,
		Vector2 position = { 0.0f, 0.0f }, Vector2 velocity = { 0.0f, 0.0f }, Vector2 acceleration = { 0.0f, 0.0f }, Vector2 force = { 0.0f, 0.0f },
		float angle = 0.0f, float angvel = 0.0f, float angacc = 0.0f, float torque = 0.0f,
		std::vector<Vector2> shape = { {0.0f, 0.0f} }, int target_id = 0, bool is_targeted = false, bool has_gravity = false
	)
	{ // set components of entity
		m_ID = ID;
		m_show_on_screen = show_on_screen;
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

		set_entity_components( // ECS gets updated upon object creation
			m_ID, m_show_on_screen, m_name, m_mass, m_color,
			m_position, m_velocity, m_acceleration, m_force,
			m_angle, m_angvel, m_angacc, m_torque,
			m_shape,
			m_target_id, m_is_targeted, m_has_gravity
		);
	};
};

#endif