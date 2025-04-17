#ifndef ENTITYROW_H
#define ENTITYROW_H

#include <raylib.h>
#include <vector>
#include <string>
#include "useful_functions.h"


class EntityRow { // contains components for physics objects
public:

	std::string m_name;
	float m_mass; // dry mass
	float m_fuelmass; // wet mass
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

	float m_health; // when this reaches 0, the object should be deleted
	std::vector<Vector2> m_shape; // vector of Vector2 objects describing entity vertices
	int m_target_id; // missiles and lasers target objects, planetoids do not
	int m_parent_id; // ID of parent entity (eg Planetoids are parents of GroundLasers)
	bool m_is_targeted; // anything can be targeted
	bool m_has_gravity; // Planetoids have gravity, ships and stuff do not
	bool m_is_movable; // physics objects are moveable, planetoids are not
	bool m_is_spawned; // objects are only updated if they're spawned

	EntityRow();

	EntityRow(
		std::string name, float mass, float fuelmass, Color color,
		Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
		float angle, float angvel, float angacc, float torque,
		float health, std::vector<Vector2> shape, int target_id, int parent_id,
		bool is_targeted, bool has_gravity, bool is_movable, bool is_spawned
	);
};

#endif