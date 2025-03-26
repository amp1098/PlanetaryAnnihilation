#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <map>
#include <vector>

#include "ent_row.h"

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

typedef EntityRow entity_row_type;

namespace EntityComponentSystem {

	class ECS { // contains ECS map variable and methods for storing/manipulating entity components
	
		std::map<int, entity_row_type> ECS_map; // ECS map variable, int -> EntityRow obj
	public:
		ECS();

		void ECS_update(int key, entity_row_type components);

		void set_entity_components(
			int ID, std::string name, float mass, Color color,
			Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
			float angle, float angvel, float angacc, float torque,
			std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity, bool is_movable
		);

		entity_row_type get_entity_components(int ID);

		void update_entity_components(
			int ID, std::string name, float mass, Color color,
			Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
			float angle, float angvel, float angacc, float torque,
			std::vector<Vector2> shape, int target_id, bool is_targeted, bool has_gravity, bool is_movable
		);

		std::map<int, entity_row_type>::iterator start_of_ECS();

		std::map<int, entity_row_type>::iterator end_of_ECS();

		int number_of_entities() const;

		void destroy_entity(int ID);

	};
};


#endif