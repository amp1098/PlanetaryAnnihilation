#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H

#include "ECS.h"
#include <raymath.h>
#include <iostream>

void thrust_check(int ID) { // checks if KEY_UP/KEY_DOWN is pressed and updates force vector in ECS
	
	// initializing local vars
	Vector2 force{ ECS_map[ID].m_force };
	Vector2 thrust{ 0.0f, 50.0f };

	if (IsKeyDown(KEY_UP)) force += thrust; // push up
	else if (IsKeyDown(KEY_DOWN)) force -= thrust; // push down
	else force == Vector2Zero(); // force returns to zero otherwise


	set_entity_components(
		ID,
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, force,
		ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity
	);

	std::cout << ECS_map[ID].m_force.y << std::endl;

};

#endif
