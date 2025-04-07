#include "GroundLaser.h"
#include "polygons.h"

GroundLaser::GroundLaser(
	int ID, std::string name, float mass, Color color, 
	bool is_spawned
)
{
	m_ID = ID;
	m_name = name;
	m_mass = mass;
	m_color = color;

	m_angle = 0.0f;
	m_angvel = 0.0f;
	m_angacc = 0.0f;
	m_torque = 0.0f;

	m_parent_id = 0;
	m_target_id = 0;

	m_shape = Polygons::poly_groundlaser();

	m_is_spawned = is_spawned;

	ECS_obj.set_name(ID, name);

	ECS_obj.set_mass(ID, mass);

	ECS_obj.set_color(ID, color);

	ECS_obj.set_shape(ID, Polygons::poly_groundlaser());

	ECS_obj.set_target_id(ID, 1); // temp, should find player entity

	ECS_obj.set_parent_id(ID, 4); // also temp, should be more dynamic, currently uses big planet ID

	ECS_obj.set_is_spawned(ID, is_spawned);
	
};