#include "control_system.h"

void thrust_check(int ID) { // checks if KEY_UP/KEY_DOWN is pressed and updates force vector in ECS
	if (ECS_obj.get_entity_components(ID).m_name == "ship") { // maybe add "movable" component later and check for that
		// initializing local vars
		float angle{ ECS_obj.get_entity_components(ID).m_angle };
		Vector2 force{ ECS_obj.get_entity_components(ID).m_force };
		Vector2 thrust{ cos(ECS_obj.get_entity_components(ID).m_angle) * 10.0f, sin(ECS_obj.get_entity_components(ID).m_angle) * 10.0f };

		float torque{ ECS_obj.get_entity_components(ID).m_torque };
		float turn_force{ 1500.0f };

		if (IsKeyDown(KEY_UP)) force = thrust; // push up
		else if (IsKeyDown(KEY_DOWN)) force = Vector2Negate(thrust); // push down
		else force = Vector2Zero(); // force returns to zero otherwise

		if (IsKeyDown(KEY_RIGHT)) torque = turn_force; // twist right
		else if (IsKeyDown(KEY_LEFT)) torque = -turn_force; // twist left
		else torque = 0.0f; // torque returns to zero otherwise

		ECS_obj.set_force(ID, force);

		ECS_obj.set_torque(ID, torque);
	};
};

void missile_control(int ID) { // aims at target and thrusts
	if (ECS_obj.get_entity_components(ID).m_name == "missile") {
		// initializing local vars

		float fuelmass{ ECS_obj.get_entity_components(ID).m_fuelmass };

		float angle{ ECS_obj.get_entity_components(ID).m_angle };

		Vector2 force{ ECS_obj.get_entity_components(ID).m_force };

		Vector2 thrust{ cos(ECS_obj.get_entity_components(ID).m_angle) * 50.0f, sin(ECS_obj.get_entity_components(ID).m_angle) * 50.0f };

		float torque{ ECS_obj.get_entity_components(ID).m_torque };

		float turn_force{ 5000.0f };

		if (abs(ECS_obj.get_entity_components(ID).m_angvel) <= 0.1f && fuelmass > 0.0f) {

			force = thrust; // engines won't push if turning fast

			fuelmass = std::max(fuelmass - 0.005f, 0.0f); // subtract fuelmass while engines are on, stop when 0
		}
		else {

			force = { 0.0f, 0.0f };

		};

		torque = turn_force; // twist right

		ECS_obj.set_force(ID, force);

		ECS_obj.set_torque(ID, torque);

		ECS_obj.set_fuelmass(ID, fuelmass);

	};
};

void groundlaser_control(int ID) { // applies linear force until velocity relative to target reaches a certain value
	if (ECS_obj.get_entity_components(ID).m_name == "groundlaser") {
		// initializing local vars

		float angle{ ECS_obj.get_entity_components(ID).m_angle };

		Vector2 force{ ECS_obj.get_entity_components(ID).m_force };

		Vector2 thrust{ cos(ECS_obj.get_entity_components(ID).m_angle) * 30.0f, sin(ECS_obj.get_entity_components(ID).m_angle) * 30.0f };

		float torque{ ECS_obj.get_entity_components(ID).m_torque };

		float turn_force{ 1500.0f };

		if (abs(ECS_obj.get_entity_components(ID).m_angvel) <= 0.1f) force = thrust; // engines won't push if turning fast
		else force = { 0.0f, 0.0f };

		torque = turn_force; // twist right

		ECS_obj.set_force(ID, force);

		ECS_obj.set_torque(ID, torque);

	};
};
