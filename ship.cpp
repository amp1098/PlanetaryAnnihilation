#include "Ship.h"

Ship::Ship(
	int ID, std::string name, float mass, Color color,
	Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
	float angle, float angvel, float angacc, float torque,
	std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity, bool is_movable
)
{ // constructor, takes arguments
	m_ID = ID;
	m_name = name;
	m_mass = mass;
	m_color = color;

	m_position = position;
	m_velocity = velocity;
	m_acceleration = acceleration;
	m_force = force;

	m_angle = angle;
	m_angvel = angvel;
	m_angacc = angacc;
	m_torque = torque;

	m_shape = shape;
	m_target_id = target_id;
	m_is_targeted = is_targeted;
	m_has_gravity = has_gravity;
	m_is_movable = is_movable;

	ECS_obj.set_entity_components( // ECS gets updated upon object creation
		m_ID, m_name, m_mass, m_color,
		m_position, m_velocity, m_acceleration, m_force,
		m_angle, m_angvel, m_angacc, m_torque,
		m_shape,
		m_target_id, m_is_targeted, m_has_gravity, m_is_movable
	);
};

entity_row_type Ship::get_components() {
	return ECS_obj.get_entity_components(m_ID);
};

Ship::~Ship() { // destructor, object removal also  removes it from ECS
	ECS_obj.destroy_entity(m_ID);
};

void Ship::remove() const {
	ECS_obj.destroy_entity(m_ID);
};