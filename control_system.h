#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H

#include "ECS.h"
#include <raymath.h>
#include <iostream>

void thrust_check(int ID) { // checks if KEY_UP/KEY_DOWN is pressed and updates force vector in ECS
	
	// initializing local vars
	float angle{ ECS_map[ID].m_angle };
	Vector2 force{ ECS_map[ID].m_force};
	Vector2 thrust{ 30.0f, 50.0f };

	float torque{ ECS_map[ID].m_torque};
	float turn_force{ 150.0f };

	if (IsKeyDown(KEY_UP)) force = Vector2Rotate(thrust, angle); // push up
	else if (IsKeyDown(KEY_DOWN)) force = Vector2Rotate(Vector2Negate(thrust), angle); // push down
	else force = Vector2Zero(); // force returns to zero otherwise

	if (IsKeyDown(KEY_RIGHT)) torque = turn_force; // twist right
	else if (IsKeyDown(KEY_LEFT)) torque = -turn_force; // twist left
	else torque = 0.0f; // torque returns to zero otherwise


	set_entity_components(
		ID,
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, torque,
		ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity
	);

	std::cout << "torque : " << ECS_map[ID].m_torque << std::endl;
	std::cout << "force : " << ECS_map[ID].m_force.x << std::endl;
};

#endif
