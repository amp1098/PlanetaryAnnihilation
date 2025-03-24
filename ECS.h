#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <map>
#include "ent_row.h"
#include <vector>

/*
TODO: Throw exception if ID arg in set_entity_component already exists in ECS
need to iterate through keys efficiently in map
*/

// this is going to be a map from int keys to entity_row_type values
/*
example for object that is targeting another an object with ID == 1 (doesnt show all components)
ID | MASS |  POSITION  |  VELOCITY  |  ACCELERATION  |  TAR_OBJ_ID  | IS_TAR_BOOL | HAS_GRAVITY |
24 | 1.0f | {0.0, 0.0} | {0.2, 1.0} |  {2.5, -3.1}   |       1      |   false     |   false     |
*/

typedef entity_row entity_row_type;

std::map<int, entity_row_type> ECS_map;

void ECS_update(int key, entity_row_type components) { // adds components to ECS, should be called when a new entity is made
	ECS_map.insert(
		std::pair<int, entity_row_type>(key,
			entity_row(
				components
			)
		)
	);
};

void set_entity_components(
	int ID, std::string name, float mass, Color color,
	Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
	float angle, float angvel, float angacc, float torque,
	std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity
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
			target_id, is_targeted, has_gravity
		}
	);
};

void update_entity_components(
	int ID, std::string name, float mass, Color color,
	Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
	float angle, float angvel, float angacc, float torque,
	std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity
) {

	ECS_map[ID] =
	{ // update components at known ID
		name,
		mass,
		color,
		position, velocity, acceleration, force,
		angle, angvel, angacc, torque,
		shape,
		target_id, is_targeted, has_gravity
	};
	
};

void destroy_entity(int ID) { // removes entity from ECS
	ECS_map.erase(ID);
};

#endif