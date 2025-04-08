#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <map>
#include <vector>

#include "EntityRow.h"

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
			std::vector<Vector2> shape, int target_id, int parent_id, 
			bool is_targeted, bool has_gravity, bool is_movable, bool is_spawned
		);

		entity_row_type get_entity_components(int ID);

		void update_entity_components(
			int ID, std::string name, float mass, Color color,
			Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 force,
			float angle, float angvel, float angacc, float torque,
			std::vector<Vector2> shape, int target_id, int parent_id, 
			bool is_targeted, bool has_gravity, bool is_movable, bool is_spawned
		);

		/*Setters for all components*/

		void set_name(int ID, std::string name);

		void set_mass(int ID, float mass);

		void set_color(int ID, Color color);

		void set_position(int ID, Vector2 position);

		void set_velocity(int ID, Vector2 velocity);

		void set_acceleration(int ID, Vector2 acceleration);

		void set_force(int ID, Vector2 force);

		void set_angle(int ID, float angle);

		void set_angvel(int ID, float angvel);

		void set_angacc(int ID, float angacc);

		void set_torque(int ID, float torque);

		void set_shape(int ID, std::vector<Vector2> shape);

		void set_target_id(int ID, int target_id);

		void set_parent_id(int ID, int parent_id);

		void set_is_targeted(int ID, bool is_targeted);

		void set_has_gravity(int ID, bool has_gravity);

		void set_is_movable(int ID, bool is_movable);

		void set_is_spawned(int ID, bool is_spawned);

		std::map<int, entity_row_type>::iterator start_of_ECS();

		std::map<int, entity_row_type>::iterator end_of_ECS();

		int number_of_entities() const;

		void destroy_entity(int ID);

		std::vector<int> return_ids_with_name(std::string name);
	};
};


#endif