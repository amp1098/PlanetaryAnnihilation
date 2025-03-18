#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <map>
#include "ent_row.h"
#include <vector>

// this is going to be a map from int keys to entity_row_type values
/*
example for object that is targeting another an object with ID == 1
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

void set_entity_components(int ID, float mass, Color color,
	Vector2 position, Vector2 velocity, Vector2 acceleration,
	std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity) {
	ECS_update(
		ID,
		{ mass, color, position, velocity, acceleration, shape, target_id, is_targeted, has_gravity }
	);
};

#endif