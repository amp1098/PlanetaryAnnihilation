
#include <iostream>
#include <map>
#include <vector>

#include "EntityRow.h"
#include "ECS.h"

using EntityComponentSystem::ECS;

ECS::ECS() {
	ECS_map = {};
};

void ECS::ECS_update(int key, entity_row_type components) { // adds components to ECS, should be called when a new entity is made
	ECS_map.insert(
		std::pair<int, entity_row_type>(key,
			EntityRow(
				components
			)
		)
	);
};



void ECS::set_entity_components(
	int ID, std::string name, float mass, float fuelmass, Color color,
	Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
	float angle, float angvel, float angacc, float torque,
	float health, bool invincible, int invincible_counter,
	std::vector<Vector2> shape, int target_id, int parent_id, bool uses_prop_nav,
	bool is_targeted, bool has_gravity, bool is_movable, bool is_spawned,
	std::vector<float> buffer1
) { // create new entity at ID
	ECS_update(
		ID,
		{
			name,
			mass,
			fuelmass,
			color,
			position, velocity, acceleration, force,
			angle, angvel, angacc, torque,
			health, invincible, invincible_counter,
			shape,
			target_id, parent_id, uses_prop_nav,
			is_targeted, has_gravity, is_movable, is_spawned,
			buffer1
		}
	);
};

entity_row_type ECS::get_entity_components(int ID) {
	return ECS_map[ID];
};

void ECS::update_entity_components(
	int ID, std::string name, float mass, float fuelmass, Color color,
	Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
	float angle, float angvel, float angacc, float torque,
	float health, bool invincible, int invincible_counter,
	std::vector<Vector2> shape, int target_id, int parent_id, bool uses_prop_nav,
	bool is_targeted, bool has_gravity, bool is_movable, bool is_spawned,
	std::vector<float> buffer1
) { // Update components at known ID

	ECS_map[ID] =
	{ 
		name,
		fuelmass,
		mass,
		color,
		position, velocity, acceleration, force,
		angle, angvel, angacc, torque,
		health, invincible, invincible_counter,
		shape,
		target_id, parent_id, uses_prop_nav,
		is_targeted, has_gravity, is_movable, is_spawned,
		buffer1
	};
};

// TODO: figure out a better way to iterate through setter functions' arguments
// really I just need to update one part in each setter, but I have to tell the program to put back the stuff
// that was already there... it works but is just annoying to update when I have new ideas.

void ECS::set_name(int ID, std::string name) {
	ECS_map[ID] = {
		name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::ECS::set_mass(int ID, float mass) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::ECS::set_fuelmass(int ID, float fuelmass) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_color(int ID, Color color) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_position(int ID, Vector2 position) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_velocity(int ID, Vector2 velocity) {
	ECS_map[ID] = {
	ECS_map[ID].m_name,
	ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
	ECS_map[ID].m_color,
	ECS_map[ID].m_position, velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
	ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
	ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
	ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
	ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_acceleration(int ID, Vector2 acceleration) {
	ECS_map[ID] = {
	ECS_map[ID].m_name,
	ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
	ECS_map[ID].m_color,
	ECS_map[ID].m_position, ECS_map[ID].m_velocity, acceleration, ECS_map[ID].m_force,
	ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
	ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
	ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
	ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_force(int ID, Vector2 force) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_angle(int ID, float angle) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_angvel(int ID, float angvel) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_angacc(int ID, float angacc) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_torque(int ID, float torque) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_health(int ID, float health) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_invincible(int ID, bool invincible) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_invincible_counter(int ID, int invincible_counter) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};


void ECS::set_shape(int ID, std::vector<Vector2> shape) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_target_id(int ID, int target_id) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_parent_id(int ID, int parent_id) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_uses_prop_nav(int ID, bool uses_prop_nav) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};

};

void ECS::set_is_targeted(int ID, bool is_targeted) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_has_gravity(int ID, bool has_gravity) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_is_movable(int ID, bool is_movable) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, is_movable, ECS_map[ID].m_is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_is_spawned(int ID, bool is_spawned) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, is_spawned,
		ECS_map[ID].m_buffer1
	};
};

void ECS::set_buffer1(int ID, std::vector<float> buffer1) {
	ECS_map[ID] = {
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass, ECS_map[ID].m_fuelmass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, ECS_map[ID].m_force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, ECS_map[ID].m_torque,
		ECS_map[ID].m_health, ECS_map[ID].m_invincible, ECS_map[ID].m_invincible_counter, ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_parent_id, ECS_map[ID].m_uses_prop_nav,
		ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity, ECS_map[ID].m_is_movable, ECS_map[ID].m_is_spawned,
		buffer1
	};
};

std::map<int, entity_row_type>::iterator ECS::start_of_ECS() { // used to start iterators over ECS
	return ECS_map.begin();
};

std::map<int, entity_row_type>::iterator ECS::end_of_ECS() { // used to end iterators over ECS
	return ECS_map.end();
};

/*
NOTE: The reason why I'm not just iterating through the ECS with a simple counter
(i.e., for (int i=0;i<number_of_entities;i++)) is because I want to allow for
any IDs to be used. For example, if I only have two entities of ID 1 and 324, I should
be able to iterate over both of them despite how 1 and 324 are not consecutive integers.
*/

int ECS::number_of_entities() const { // returns number of entities stored in ECS
	return static_cast<int>(std::size(ECS_map));
};

void ECS::destroy_entity(int ID) { // removes entity from ECS, effectively deletes it
	static_cast<int>(ECS_map.erase(ID));
};

std::vector<int> ECS::return_all_ids() {
	std::vector<int> ids{};

	for ( // iterating through ECS
		std::map<int, entity_row_type>::iterator iter = ECS_map.begin();
		iter != ECS_map.end();
		++iter
		) { 

		int ID = iter->first;

		ids.push_back(ID); // appending ID to ids vector


	}

	return ids;
};

std::vector<int> ECS::return_ids_with_name(std::string name) {
	std::vector<int> ids{};

	for ( // iterating through ECS
		std::map<int, entity_row_type>::iterator iter = ECS_map.begin();
		iter != ECS_map.end();
		++iter
		) { // if entity has its name component equal to the name passed here, return true

		int ID = iter->first;

		if (ECS_map[ID].m_name == name) { 

			ids.push_back(ID); // appending ID to ids vector

		};

	}

	return ids;
};


