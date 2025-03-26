
#include <iostream>
#include <map>
#include <vector>

#include "ent_row.h"
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

entity_row_type ECS::get_entity_components(int ID) {
	return ECS_map[ID];
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
	return std::size(ECS_map);
};

void ECS::destroy_entity(int ID) { // removes entity from ECS
	ECS_map.erase(ID);
};