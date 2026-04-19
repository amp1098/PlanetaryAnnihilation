#include "control_system.h"

void thrust_check(int ID) { // checks if KEY_UP/KEY_DOWN is pressed and updates force vector in ECS
	if (ECS_obj.get_entity_components(ID).m_name == "ship") { // maybe add "movable" component later and check for that
		// initializing local vars
		float angle{ ECS_obj.get_entity_components(ID).m_angle };
		Vector2 force{ ECS_obj.get_entity_components(ID).m_force };
		Vector2 thrust{ cos(ECS_obj.get_entity_components(ID).m_angle) * 2.0f, sin(ECS_obj.get_entity_components(ID).m_angle) * 2.0f };

		float torque{ ECS_obj.get_entity_components(ID).m_torque };
		float turn_force{ 50.0f };

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

		int target_ID = ECS_obj.get_entity_components(ID).m_target_id;

		float mass{ ECS_obj.get_entity_components(target_ID).m_mass};

		Vector2 position = ECS_obj.get_entity_components(ID).m_position;

		Vector2 velocity = ECS_obj.get_entity_components(ID).m_velocity;

		Vector2 tar_position = ECS_obj.get_entity_components(target_ID).m_position;

		Vector2 tar_velocity = ECS_obj.get_entity_components(target_ID).m_velocity;

		float thrust_magnitude = 50.0f;

		float fuelmass{ ECS_obj.get_entity_components(ID).m_fuelmass };

		float angle{ ECS_obj.get_entity_components(ID).m_angle };

		Vector2 force{ ECS_obj.get_entity_components(ID).m_force };

		Vector2 thrust{ cos(ECS_obj.get_entity_components(ID).m_angle) * thrust_magnitude, sin(ECS_obj.get_entity_components(ID).m_angle) * thrust_magnitude };

		// === PROPORTIONAL NAVIGATION V2 === //

		// Going to use 3D prop nav equation. All 2D systems are planar cases of 3D systems.

		Vector3 acc{}; // linear acceleration, used to turn velocity vector of missile

		float N{ 5.0f }; // scaling factor, usually between 3 and 5

		Vector3 relative_vel3{

			Vector2_as_Vector3(tar_velocity - velocity)

		};

		Vector3 rotation_LOS_vec{}; // rotation vector for line of site

		Vector3 relative_pos3{

			Vector2_as_Vector3(ECS_obj.get_entity_components(target_ID).m_position - ECS_obj.get_entity_components(ID).m_position)

		};

		rotation_LOS_vec = Vector3CrossProduct(relative_pos3, relative_vel3) / Vector3LengthSqr(relative_pos3); // from wikipedia

		float rotation_LOS_rate{ rotation_LOS_vec.z };

		acc = Vector3CrossProduct(Vector3Scale(Vector3Normalize(relative_pos3), Vector3Length(relative_vel3) * -N), rotation_LOS_vec);

		float moment{

			moment_of_inertia(ECS_obj.get_entity_components(ID).m_mass, ECS_obj.get_entity_components(ID).m_shape)

		};

		Vector2 vel_perp_norm{ Vector2Normalize({ -velocity.y, velocity.x}) };

		
		if (fuelmass > 0.0f) {

			force = thrust + Vector2Scale(vel_perp_norm, acc.y * mass);

			fuelmass = std::max(fuelmass - 0.1f * dt, 0.0f); // subtract fuelmass while engines are on, stop when 0, based on dt
		}
		else {

			force = { 0.0f, 0.0f };

		};

		ECS_obj.set_angle(ID, atan2f(force.y, force.x)); // hacky, forces  angle of missile to match current force vector, very jittery
		// real solution involve PID stuff lol

		// === PROPORTIONAL NAVIGATION V2 === //

		ECS_obj.set_force(ID, force);

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