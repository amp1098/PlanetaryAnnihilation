#ifndef PLANETOID_H
#define PLANETOID_H

#include <raylib.h>
#include "GeneralPolygon.h"
#include <iostream>
#include <vector>
#include "ECS_obj.h"
#include "Entity.h"

class Planetoid : public Entity { // Planetoid class

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

public:
	Planetoid(
		int ID, float mass, Color color,
		Vector2 position,
		std::vector<Vector2> shape, bool is_targeted, bool has_gravity
	);
};

#endif
