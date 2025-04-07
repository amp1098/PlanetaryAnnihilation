#include "Planetoid.h"

Planetoid::Planetoid(
	int ID, float mass, Color color,
	Vector2 position,
	std::vector<Vector2> shape, bool is_targeted, bool has_gravity, bool is_spawned
)
{ // constructor, takes arguments
	m_ID = ID;
	m_name = "Planetoid";
	m_mass = mass;
	m_color = color;

	m_position = position;

	m_shape = shape;

	m_is_targeted = is_targeted;
	m_has_gravity = has_gravity;
	m_is_movable = false;
	m_is_spawned = is_spawned;

	ECS_obj.set_name(m_ID, "Planetoid");

	ECS_obj.set_mass(m_ID, mass);

	ECS_obj.set_color(m_ID, color);

	ECS_obj.set_position(m_ID, position);

	ECS_obj.set_shape(m_ID, shape);

	ECS_obj.set_is_targeted(m_ID, is_targeted);

	ECS_obj.set_has_gravity(m_ID, has_gravity);

	ECS_obj.set_is_movable(m_ID, false);

	ECS_obj.set_is_spawned(m_ID, is_spawned);
};