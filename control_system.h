#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H

#include "ECS.h"
#include <raymath.h>
#include <iostream>

void thrust_check(int ID) { // checks if KEY_UP/KEY_DOWN is pressed and updates force vector in ECS
	
	// initializing local vars
	float angle{ ECS_map[ID].m_angle };
	Vector2 force{ ECS_map[ID].m_force};
	Vector2 thrust{ cos(ECS_map[ID].m_angle) * 10.0f, sin(ECS_map[ID].m_angle) * 10.0f };

	float torque{ ECS_map[ID].m_torque};
	float turn_force{ 1500.0f };

	//std::cout << "\r" << "Control angle: " << angle << std::flush;
	std::cout << "\r" << "Control angvel: " << ECS_map[ID].m_torque << std::flush;

	if (IsKeyDown(KEY_UP)) force = thrust; // push up
	else if (IsKeyDown(KEY_DOWN)) force = Vector2Negate(thrust); // push down
	else force = Vector2Zero(); // force returns to zero otherwise

	if (IsKeyDown(KEY_RIGHT)) torque = turn_force; // twist right
	else if (IsKeyDown(KEY_LEFT)) torque = -turn_force; // twist left
	else torque = 0.0f; // torque returns to zero otherwise

	update_entity_components(
		ID,
		ECS_map[ID].m_name,
		ECS_map[ID].m_mass,
		ECS_map[ID].m_color,
		ECS_map[ID].m_position, ECS_map[ID].m_velocity, ECS_map[ID].m_acceleration, force,
		ECS_map[ID].m_angle, ECS_map[ID].m_angvel, ECS_map[ID].m_angacc, torque,
		ECS_map[ID].m_shape,
		ECS_map[ID].m_target_id, ECS_map[ID].m_is_targeted, ECS_map[ID].m_has_gravity
	);
};

#endif
