#ifndef SYSTEMS_H
#define SYSTEMS_H

// include ECS here to get IDs and to update components


// include all the systems here and maybe add some comments describing what they do

#include "drawing_system.h" // draws entities to screen via draw_entity(ID)

#include "physics_system.h" // updates positions of entities based on physical models (kinematics, etc)

#include "control_system.h" // updates forces/torques of entities based on keyboard inputs

void use_systems() {
//for each entity in the ECS, update the components with the available systems
	for (
		std::map<int, entity_row_type>::iterator iter = ECS_map.begin();
		iter != ECS_map.end();
		++iter
		) { // iterating through key-value pairs in ECS_map
		int ID = iter->first; // dereferencing iterator pointer, unsure how this works
		// ignoring the values

		draw_entity(ID); // drawing to screen
		thrust_check(ID); // checking for keyboard inputs
		physics_update(ID); // updating physics components
	};
};

#endif

