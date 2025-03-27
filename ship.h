#ifndef SHIP_H
#define SHIP_H

#include <raylib.h>
#include "GeneralPolygon.h"
#include <iostream>
#include <vector>
#include "ECS_obj.h"
#include "Entity.h"

class Ship : public Entity { // spaceship class

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

public:

	Ship(
		int ID, std::string name, float mass, Color color,
		Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
		float angle, float angvel, float angacc, float torque,
		std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity, bool is_movable
	);

	//entity_row_type get_components();

	//~Ship();

	//void remove() const;
};

#endif