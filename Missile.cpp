#include "Missile.h"
#include "polygons.h"

Missile::Missile(
	int ID, std::string name, float mass, Color color, float health,
	bool is_spawned
)
{ // constructor, takes arguments
	m_ID = ID;
	m_name = name;
	m_mass = mass;
	m_color = color;

	m_position = {0.0f, 0.0f};
	m_velocity = { 0.0f, 0.0f };
	m_acceleration = { 0.0f, 0.0f };
	m_force = { 0.0f, 0.0f };

	m_angle = 0.0f;
	m_angvel = 0.0f;
	m_angacc = 0.0f;
	m_torque = 0.0f;

	m_health = health;
	m_shape = Polygons::poly_missile();
	m_target_id = 1;
	m_parent_id = 0;
	m_is_targeted = false;
	m_has_gravity = false;
	m_is_movable = true;
	m_is_spawned = is_spawned;

	ECS_obj.set_name(ID, name);

	ECS_obj.set_mass(ID, mass);

	ECS_obj.set_color(ID, color);

	ECS_obj.set_position(ID, { 0.0f, 0.0f });

	ECS_obj.set_shape(ID, Polygons::poly_missile());

	ECS_obj.set_target_id(ID, m_target_id);

	ECS_obj.set_is_spawned(ID, is_spawned);

	ECS_obj.set_is_movable(ID, true);

	ECS_obj.set_has_gravity(ID, false);

};