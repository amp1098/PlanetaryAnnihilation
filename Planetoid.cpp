#include "Planetoid.h"

Planetoid::Planetoid(
	int ID, float mass, Color color,
	Vector2 position,
	std::vector<Vector2> shape, bool is_targeted, bool has_gravity
)
{ // constructor, takes arguments
	m_ID = ID;
	m_name = "Planetoid";
	m_mass = mass;
	m_color = color;

	m_position = position;

	m_force = { 0.0f, 0.0f };
	m_torque = 0.0f;

	m_shape = shape;

	m_is_targeted = is_targeted;
	m_has_gravity = has_gravity;
	m_is_movable = false;

	ECS_obj.set_entity_components( // ECS gets updated upon object creation
		m_ID, m_name, m_mass, m_color,
		m_position, { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f },
		0.0f, 0.0f, 0.0f, 0.0f,
		m_shape,
		0, m_is_targeted, m_has_gravity, m_is_movable
	);
};

entity_row_type Planetoid::get_components() {
	return ECS_obj.get_entity_components(m_ID);
};

Planetoid::~Planetoid() { // destructor, object removal also  removes it from ECS
	ECS_obj.destroy_entity(m_ID);
};

void Planetoid::remove() const {
	ECS_obj.destroy_entity(m_ID);
};