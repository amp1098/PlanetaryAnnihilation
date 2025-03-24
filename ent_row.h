#ifndef ENT_ROW_H
#define ENT_ROW_H

#include <raylib.h>
#include <vector>
#include <string>
#include "useful_functions.h"

class entity_row { // contains components for physics objects
public:

	std::string m_name;
	float m_mass;
	Color m_color;

	// LINEAR COMPONENTS
	Vector2 m_position;
	Vector2 m_velocity; // 0 vector for planetoids
	Vector2 m_acceleration; // 0 vector for planetoids
	Vector2 m_force; // 0 vector for planetoids
	
	// ANGULAR COMPONENTS (not Vector2 because game is 2d, length and sign is enough)
	float m_angle; // 0 for planetoids
	float m_angvel; // 0 for planetoids
	float m_angacc; // 0 for planetoids
	float m_torque; // 0 for planetoids

	std::vector<Vector2> m_shape; // vector of Vector2 objects describing entity vertices
	int m_target_id; // missiles and lasers target objects, planetoids do not
	bool m_is_targeted; // anything can be targeted
	bool m_has_gravity; // Planetoids have gravity, ships and stuff do not
	bool m_is_movable; // physics objects are moveable, planetoids are not

	entity_row() { // default constructor, does not take arguments
		m_name = "default_construct_ignore";
		m_mass = 1.0f;
		m_color = BLANK;

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
		m_is_movable = false;
	};

	entity_row(
		std::string name, float mass, Color color,
		Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
		float angle, float angvel, float angacc, float torque,
		std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity, bool is_movable
	)
	{ // constructor, takes arguments
		m_name = name;
		m_mass = mass;
		m_color = color;

		m_position = position;
		m_velocity = velocity;
		m_acceleration = acceleration;
		m_force = force;

		m_angle = clamp_angle(angle); // must be 2pi periodic, floating point modulo restricts range to [0, 2pi)
		m_angvel = angvel;
		m_angacc = angacc;
		m_torque = torque;

		m_shape = shape;
		m_target_id = target_id;
		m_is_targeted = is_targeted;
		m_has_gravity = has_gravity;
		m_is_movable = is_movable;
	};
};

#endif