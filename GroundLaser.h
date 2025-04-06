#ifndef GROUNDLASER_H
#define GROUNDLASER_H

#include "Entity.h"
#include <raylib.h>
#include <raymath.h>

class GroundLaser : public Entity { // Is on radius of Planetoid, aims at Ships, emits Laserbeam
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
	int m_parent_id; // ID of parent entity (eg Planetoids are parents of GroundLasers)
	bool m_is_targeted; // anything can be targeted
	bool m_has_gravity; // Planetoids have gravity, ships and stuff do not
	bool m_is_movable;
	bool m_is_spawned;

public:

	GroundLaser(
		int ID, std::string name, float mass, Color color,
		Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
		float angle, float angvel, float angacc, float torque,
		std::vector<Vector2> shape, 
		int target_id, int parent_id,
		bool is_targeted, bool has_gravity, bool is_movable, bool is_spawned
	);
};

#endif