#include <raylib.h>
#include <vector>
#include <string>
#include "useful_functions.h"
#include "EntityRow.h"


EntityRow::EntityRow() { // default constructor, does not take arguments
	m_name = "default_construct_ignore";
	m_mass = 1.0f;
	m_fuelmass = 1.0f;
	m_color = BLANK;

	m_position = { 0.0f, 0.0f };
	m_velocity = { 0.0f, 0.0f };
	m_acceleration = { 0.0f, 0.0f };
	m_force = { 0.0f, 0.0f };

	m_angle = 0.0f;
	m_angvel = 0.0f;
	m_angacc = 0.0f;
	m_torque = 0.0f;

	m_health = 100.0f;
	m_invincible = false;
	m_invincible_counter = 0;

	m_shape = { {30.0f, 0.0f}, {-30.0f, 0.0f}, {0.0f, 30.0f} };
	m_target_id = 0;
	m_parent_id = 0;
	m_is_targeted = false;
	m_has_gravity = false;
	m_is_movable = false;
	m_is_spawned = false;
};

EntityRow::EntityRow(
	std::string name, float mass, float fuelmass, Color color,
	Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
	float angle, float angvel, float angacc, float torque,
	float health, bool invincible, int invincible_counter,
	std::vector<Vector2> shape, int target_id, int parent_id, 
	bool is_targeted, bool has_gravity, bool is_movable, bool is_spawned
)
{ // constructor, takes arguments
	m_name = name;
	m_mass = mass;
	m_fuelmass = fuelmass;
	m_color = color;

	m_position = position;
	m_velocity = velocity;
	m_acceleration = acceleration;
	m_force = force;

	m_angle = clamp_angle(angle); // must be 2pi periodic, floating point modulo restricts range to [0, 2pi)
	m_angvel = angvel;
	m_angacc = angacc;
	m_torque = torque;

	m_health = health;
	m_invincible = invincible;
	m_invincible_counter = invincible_counter;

	m_shape = shape;
	m_target_id = target_id;
	m_parent_id = parent_id;
	m_is_targeted = is_targeted;
	m_has_gravity = has_gravity;
	m_is_movable = is_movable;
	m_is_spawned = is_spawned;
};