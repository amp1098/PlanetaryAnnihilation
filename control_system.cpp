#include "control_system.h"

void thrust_check(int ID) { // checks if KEY_UP/KEY_DOWN is pressed and updates force vector in ECS
	if (ECS_obj.get_entity_components(ID).m_name == "ship") { // maybe add "movable" component later and check for that
		// initializing local vars
		float angle{ ECS_obj.get_entity_components(ID).m_angle };
		Vector2 force{ ECS_obj.get_entity_components(ID).m_force };
		Vector2 thrust{ cos(ECS_obj.get_entity_components(ID).m_angle) * 600.0f, sin(ECS_obj.get_entity_components(ID).m_angle) * 600.0f };

		float torque{ ECS_obj.get_entity_components(ID).m_torque };
		float turn_force{ 100000.0f };

		if (IsKeyDown(KEY_UP)) force = thrust; // push up
		else if (IsKeyDown(KEY_DOWN)) force = Vector2Negate(thrust); // push down
		else force = Vector2Zero(); // force returns to zero otherwise

		if (IsKeyDown(KEY_RIGHT)) torque = turn_force; // twist right
		else if (IsKeyDown(KEY_LEFT)) torque = -turn_force; // twist left
		else torque = 0.0f; // torque returns to zero otherwise

		if (IsKeyDown(KEY_SPACE)) {  // brake
			ECS_obj.set_velocity(ID, { 0.0f, 0.0f });
			ECS_obj.set_force(ID, { 0.0f, 0.0f });
			ECS_obj.set_torque(ID, 0);
			ECS_obj.set_angvel(ID, 0);
			ECS_obj.set_angacc(ID, 0);
		};

		ECS_obj.set_force(ID, force);

		ECS_obj.set_torque(ID, torque);
	};
};

void missile_control(int ID) { // trys to fly into player's ship, turns into explosion when fuel is out
	if (ECS_obj.get_entity_components(ID).m_name == "missile") {
		// initializing local vars

		float thrust_magnitude = 0.0f;

		float fuelmass{ ECS_obj.get_entity_components(ID).m_fuelmass };

		float angle{ ECS_obj.get_entity_components(ID).m_angle };

		Vector2 force{ ECS_obj.get_entity_components(ID).m_force };

		Vector2 thrust{ cos(ECS_obj.get_entity_components(ID).m_angle) * thrust_magnitude, sin(ECS_obj.get_entity_components(ID).m_angle) * thrust_magnitude };

		//float torque{ ECS_obj.get_entity_components(ID).m_torque };

		//float turn_force{ 500.0f };

		if ( fuelmass > 0.0f) {

			force = thrust;

			fuelmass = std::max(fuelmass - 0 * 1.0f * dt, 0.0f); // subtract fuelmass while engines are on, stop when 0, based on dt
		}
		else {

			force = { 0.0f, 0.0f };

		};

		//torque = turn_force; // twist right

		ECS_obj.set_force(ID, force);

		//ECS_obj.set_torque(ID, torque);

		ECS_obj.set_fuelmass(ID, fuelmass);

	};
};

void groundlaser_control(int ID) { // rotates groundlaser entity to point at player ship
	if (ECS_obj.get_entity_components(ID).m_name == "groundlaser") {
		// initializing local vars

		float angle{ ECS_obj.get_entity_components(ID).m_angle };

		float torque{ ECS_obj.get_entity_components(ID).m_torque };

		float turn_force{ 10.0f };

		torque = turn_force; // twist right

		ECS_obj.set_torque(ID, torque);

	};
};
