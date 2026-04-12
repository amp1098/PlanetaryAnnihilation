// include all the systems here and maybe add some comments describing what they do

#include "systems.h"

// include all the systems here and maybe add some comments describing what they do

#include "drawing_system.h" // draws entities to screen via draw_entity(ID)

#include "physics_system.h" // updates positions of entities based on physical models (kinematics, etc)

#include "control_system.h" // updates forces/torques of entities based on keyboard inputs

#include "health_system.h"  // handles damage to entities

#include "collision_system.h" // checks for collisions


void use_initializer_systems() { // these systems should only be run at the start of the game

	/*for (int i = 0; i < 20; i++) {
		random_spawn_on_planetoid();
	};*/

};

void use_systems() {

	//for each entity in the ECS, update the components with the available systems
	for (
		std::map<int, entity_row_type>::iterator iter = ECS_obj.start_of_ECS();
		iter != ECS_obj.end_of_ECS();
		++iter
		) { // iterating through key-value pairs in ECS_map
		int ID = iter->first; // dereferencing iterator pointer, unsure how this works
		// ignoring the values

		if ( ID != 0 ) { // 0 is default ID, ignorable

			if (ECS_obj.get_entity_components(ID).m_name == "missile" &&
				FloatEquals(ECS_obj.get_entity_components(ID).m_fuelmass, 0.0f) &&
				ECS_obj.get_entity_components(ID).m_is_spawned
				) {
				// if missile fuel is zero, it spawns an explosion at its position

				spawn_explosion(ID);

				ECS_obj.set_is_spawned(ID, false); // despawn missile
			};

			if (ECS_obj.get_entity_components(ID).m_name == "explosion") {

				float current_health{ ECS_obj.get_entity_components(ID).m_health };

				ECS_obj.set_health(ID, current_health - 5.0f);
			};

			draw_entity(ID); // drawing to screen
			thrust_check(ID); // checking for keyboard inputs
			missile_control(ID); // makes missiles move
			groundlaser_control(ID); // makes groundlasers aim

			if (IsKeyDown(KEY_BACKSPACE)) {// updating physics components
				physics_update(ID);
			} 
			

			despawn_dead_entity(ID);

		};
		collision_health_response(1);  // static for now, just handling playerID collisions

		if (return_id_colliding_explosion(1) != 0) { // explosion colliding with player ship

			if (!ECS_obj.get_entity_components(1).m_invincible) { 

				take_damage(1, 15.0f);

			};

			make_invincible(1, 2000);

		};

	};
};