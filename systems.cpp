// include all the systems here and maybe add some comments describing what they do

#include "drawing_system.h" // draws entities to screen via draw_entity(ID)

#include "physics_system.h" // updates positions of entities based on physical models (kinematics, etc)

#include "control_system.h" // updates forces/torques of entities based on keyboard inputs

#include "spawning_system.h" // moves entities to spawned locaitons

#include "collision_system.h" // checks for collisiosn 

void use_systems() {
	//for each entity in the ECS, update the components with the available systems
	for (
		std::map<int, entity_row_type>::iterator iter = ECS_obj.start_of_ECS();
		iter != ECS_obj.end_of_ECS();
		++iter
		) { // iterating through key-value pairs in ECS_map
		int ID = iter->first; // dereferencing iterator pointer, unsure how this works
		// ignoring the values

		if (ID != 0) { // 0 ID is a garbage spot, used to trash entities by overwriting them

			if (!ECS_obj.get_entity_components(ID).m_is_spawned) { // spawns entity if is_spawned is false
				std::cout << "ID : " << ID << " spawned? : " << ECS_obj.get_entity_components(ID).m_is_spawned << std::endl;
				random_spawn_on_planetoid(ID); // spawns objects on planetoids
				std::cout << "ID : " << ID << " spawned? : " << ECS_obj.get_entity_components(ID).m_is_spawned << std::endl;

			};

			draw_entity(ID); // drawing to screen
			thrust_check(ID); // checking for keyboard inputs
			missile_control(ID); // makes missiles move
			groundlaser_control(ID); // makes groundlasers aim
			physics_update(ID); // updating physics components

			
		};

		
	};
};