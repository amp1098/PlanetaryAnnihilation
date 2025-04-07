#include "spawning_system.h"

void random_spawn_on_planetoid(int ID) { // find an entity and put it on a planetoid

	int planetoid_ID{ ECS_obj.get_entity_components(ID).m_parent_id };

	std::vector<Vector2> planetoid_shape{ ECS_obj.get_entity_components(planetoid_ID).m_shape };

	int random_index{ static_cast<int>(std::rand() % std::size(planetoid_shape)) }; // rand. num. 0 -> # of shape points

	Vector2 translate{ planetoid_shape[random_index] }; // random point from shape, spawn location

	if (ECS_obj.get_entity_components(ID).m_name == "groundlaser") {  // if entity is called groundlaser, update it

		ECS_obj.set_is_spawned(ID, true);

		ECS_obj.set_position(ID, translate + ECS_obj.get_entity_components(planetoid_ID).m_position);

	};

};
