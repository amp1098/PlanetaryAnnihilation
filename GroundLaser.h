#ifndef GROUNDLASER_H
#define GROUNDLASER_H

#include "Entity.h"
#include <raylib.h>
#include <raymath.h>

class GroundLaser : public Entity { // Is on radius of Planetoid, aims at Ships, emits Laserbeam
	int m_ID;
	std::string m_name;
	float m_mass{};
	Color m_color{};

	// ANGULAR COMPONENTS
	float m_angle{};
	float m_angvel{};
	float m_angacc{};
	float m_torque{};

	std::vector<Vector2> m_shape; // vector of Vector2 objects describing entity vertices
	int m_target_id{}; // missiles and lasers target objects, planetoids do not
	int m_parent_id{}; // ID of parent entity (eg Planetoids are parents of GroundLasers)
	bool m_is_spawned;

public:

	GroundLaser(
		int ID, std::string name, float mass, Color color,
		bool is_spawned
	);
};

#endif