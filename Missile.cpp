#include "Missile.h"
#include "polygons.h"

Missile::Missile(
	int ID, std::string name, float fuelmass, Color color, float health,
	bool is_spawned, bool uses_prop_nav
)
{ // constructor, takes arguments
	m_ID = ID;
	m_name = name;
	m_mass = 100.0f;
	m_fuelmass = fuelmass;
	m_color = color;

	m_position = {-500.0f, -300.0f};
	m_velocity = { 0.0f, 0.0f };
	m_acceleration = { 0.0f, 0.0f };
	m_force = { 0.0f, 0.0f };

	m_angle = 0.0f;
	m_angvel = 10.0f;
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

	m_uses_prop_nav = uses_prop_nav;

	ECS_obj.set_name(ID, name);

	ECS_obj.set_mass(ID, m_mass);

	ECS_obj.set_fuelmass(ID, fuelmass);

	ECS_obj.set_color(ID, color);

	ECS_obj.set_position(ID, m_position);

	ECS_obj.set_shape(ID, m_shape);

	ECS_obj.set_target_id(ID, m_target_id);

	ECS_obj.set_is_spawned(ID, is_spawned);

	ECS_obj.set_uses_prop_nav(ID, uses_prop_nav);

	ECS_obj.set_is_movable(ID, true);

	ECS_obj.set_has_gravity(ID, false);

	ECS_obj.set_buffer1(ID, { 0.0f, 0.0f, 0.0f });

};