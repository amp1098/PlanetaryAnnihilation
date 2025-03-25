
#include <iostream>
#include <map>
#include <vector>

#include "ent_row.h"
#include "ECS.h"

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
	int ID, std::string name, float mass, Color color,
	Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
	float angle, float angvel, float angacc, float torque,
	std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity, bool is_movable
) { // create new entity at ID
	ECS_update(
		ID,
		{
			name,
			mass,
			color,
			position, velocity, acceleration, force,
			angle, angvel, angacc, torque,
			shape,
			target_id, is_targeted, has_gravity, is_movable
		}
	);
};

void ECS::update_entity_components(
	int ID, std::string name, float mass, Color color,
	Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
	float angle, float angvel, float angacc, float torque,
	std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity, bool is_movable
) {

	ECS_map[ID] =
	{ // update components at known ID
		name,
		mass,
		color,
		position, velocity, acceleration, force,
		angle, angvel, angacc, torque,
		shape,
		target_id, is_targeted, has_gravity, is_movable
	};
};

void ECS::destroy_entity(int ID) { // removes entity from ECS
	ECS_map.erase(ID);
};