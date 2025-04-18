#include "explosion.h"

Explosion::Explosion(
	int ID, std::string name, float fuelmass, Color color, float health,
	Vector2 position,
	bool is_spawned
)
{ // constructor, takes arguments
	m_ID = ID;
	m_name = name;
	m_mass = 3.0f;
	m_fuelmass = fuelmass;
	m_color = color;

	m_position = position;
	m_velocity = { 0.0f, 0.0f };
	m_acceleration = { 0.0f, 0.0f };
	m_force = { 0.0f, 0.0f };

	m_angle = 0.0f;
	m_angvel = 0.0f;
	m_angacc = 0.0f;
	m_torque = 0.0f;

	m_health = health;
	m_shape = Polygons::poly_explosion();
	m_target_id = 0;
	m_parent_id = 0;
	m_is_targeted = false;
	m_has_gravity = false;
	m_is_movable = false;
	m_is_spawned = is_spawned;

	ECS_obj.set_name(ID, name);

	ECS_obj.set_mass(ID, m_mass);

	ECS_obj.set_fuelmass(ID, fuelmass);

	ECS_obj.set_color(ID, color);

	ECS_obj.set_position(ID, m_position);

	ECS_obj.set_shape(ID, m_shape);

	ECS_obj.set_target_id(ID, m_target_id);

	ECS_obj.set_is_spawned(ID, is_spawned);

	ECS_obj.set_is_movable(ID, m_is_movable);

	ECS_obj.set_has_gravity(ID, m_has_gravity);

};