#include "Ship.h"
#include "polygons.h"

Ship::Ship(
	int ID, std::string name, float mass, Color color, float health,
	bool is_spawned
)
{ // constructor, takes arguments

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

	m_parent_id = 0;
	m_target_id = 0;

	m_health = 100.0f;

	m_shape = Polygons::poly_ship();

	m_is_spawned = is_spawned;
	m_has_gravity = false;
	m_is_movable = true;
	m_is_targeted = false;

	ECS_obj.set_name(ID, name);

	ECS_obj.set_mass(ID, mass);

	ECS_obj.set_color(ID, color);

	ECS_obj.set_position(ID, { 0.0f, 0.0f });

	ECS_obj.set_shape(ID, Polygons::poly_ship());

	ECS_obj.set_is_spawned(ID, is_spawned);

	ECS_obj.set_is_movable(ID, true);

	ECS_obj.set_has_gravity(ID, false);

};