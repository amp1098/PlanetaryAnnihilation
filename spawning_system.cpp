#include "spawning_system.h"

void random_spawn_on_planetoid(int ID) { // find an entity and put it on a planetoid

	int planetoid_ID{ ECS_obj.get_entity_components(ID).m_parent_id };

	std::vector<Vector2> planetoid_shape{ ECS_obj.get_entity_components(planetoid_ID).m_shape };

	int random_index{ static_cast<int>(std::rand() % std::size(planetoid_shape)) }; // rand. num. 0 -> # of shape points

	Vector2 translate{ planetoid_shape[random_index] }; // random point from shape, spawn location

	if (ECS_obj.get_entity_components(ID).m_name == "groundlaser") {  // if entity is called groundlaser, update it

		ECS_obj.set_is_spawned(ID, true);

		ECS_obj.set_position(ID, translate + ECS_obj.get_entity_components(planetoid_ID).m_position);  // move it to point on planetoid shape

	};

};

void spawn_explosion(int parent_id) { // spawn explosion entity at parent_id
	std::vector<int> ids{ ECS_obj.return_all_ids() }; // all current IDs

	int max_id{ 0 }; // initializing maximum ID

	int to_spawn_id{ 0 }; // this will be 1+max_id

	max_id = *std::max_element(ids.begin(), ids.end()); // stolen from stack exchange, pointer required for some reason

	to_spawn_id = max_id + 1;

	// getting parent id stuff 
	Vector2 position{ ECS_obj.get_entity_components(parent_id).m_position };

	ECS_obj.set_entity_components(
		to_spawn_id,
		"explosion",
		1.0f,
		1.0f,
		BLUE,
		position,
		Vector2Zero(),
		Vector2Zero(),
		Vector2Zero(),
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		1.0f,
		Polygons::poly_explosion(),
		0,
		parent_id,
		false,
		false,
		false,
		true
	);

};