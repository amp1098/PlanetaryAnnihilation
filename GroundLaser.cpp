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

	m_position = { 0.0f, 0.0f };
	m_velocity = { 0.0f, 0.0f };
	m_acceleration = { 0.0f, 0.0f };
	m_force = { 0.0f, 0.0f };

	m_angle = 0.0f;
	m_angvel = 0.0f;
	m_angacc = 0.0f;
	m_torque = 0.0f;

	m_shape = Polygons::poly_groundlaser();
	m_target_id = 1;  // player ID
	m_parent_id = 4;  // main planet ID
	m_is_targeted = false;
	m_has_gravity = false;
	m_is_movable = false;
	m_is_spawned = is_spawned;

	ECS_obj.set_entity_components( // ECS gets updated upon object creation
		m_ID, m_name, m_mass, m_color,
		m_position, m_velocity, m_acceleration, m_force,
		m_angle, m_angvel, m_angacc, m_torque,
		m_shape,
		m_target_id, m_parent_id,
		m_is_targeted, m_has_gravity, m_is_movable, m_is_spawned
	);


	
};