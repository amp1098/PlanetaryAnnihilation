#include "spawning_system.h"

void random_spawn_on_planetoid(int ID) { // find an entity and put it on a planetoid

	if (ECS_obj.get_entity_components(ID).m_is_spawned) {

		int planetoid_ID{ ECS_obj.get_entity_components(ID).m_parent_id };
		std::vector<Vector2> planetoid_shape{ ECS_obj.get_entity_components(ID).m_shape };

		int random_index{ static_cast<int>(std::rand() % std::size(planetoid_shape)) }; // rand. num. 0 -> # of shape points

		Vector2 translate{ planetoid_shape[random_index] }; // random point from shape, spawn location

		if (ECS_obj.get_entity_components(ID).m_name == "groundlaser") {  // if entity is called groundlaser, update it
			ECS_obj.update_entity_components(
				ID,
				ECS_obj.get_entity_components(ID).m_name,
				ECS_obj.get_entity_components(ID).m_mass,
				ECS_obj.get_entity_components(ID).m_color,
				ECS_obj.get_entity_components(planetoid_ID).m_position + translate,
				ECS_obj.get_entity_components(ID).m_velocity, ECS_obj.get_entity_components(ID).m_acceleration, ECS_obj.get_entity_components(ID).m_force,
				ECS_obj.get_entity_components(ID).m_angle, ECS_obj.get_entity_components(ID).m_angvel, ECS_obj.get_entity_components(ID).m_angacc, ECS_obj.get_entity_components(ID).m_torque,
				ECS_obj.get_entity_components(ID).m_shape,
				ECS_obj.get_entity_components(ID).m_target_id, ECS_obj.get_entity_components(ID).m_parent_id,
				ECS_obj.get_entity_components(ID).m_is_targeted, ECS_obj.get_entity_components(ID).m_has_gravity, ECS_obj.get_entity_components(ID).m_is_movable, true
			);

		};

		std::cout << "spawned? : " << ECS_obj.get_entity_components(ID).m_is_spawned << std::endl;

	};

};
