#include "spawning_system.h"

void random_spawn_on_planetoid() { // find an entity and put it on a planetoid

	int planetoid_ID{ 4 }; //hardcoded for now

	std::vector<Vector2> planetoid_shape{ ECS_obj.get_entity_components(planetoid_ID).m_shape };

	int random_index{ static_cast<int>(std::rand() % std::size(planetoid_shape)) }; // rand. num. 0 -> # of shape points

	Vector2 translate{ planetoid_shape[random_index] }; // random point from shape, will be added to planet position for spawning

	Vector2 spawn_point{ ECS_obj.get_entity_components(planetoid_ID).m_position + translate };

	// creating new entity with new ID

	std::vector<int> ids{ ECS_obj.return_all_ids() }; // all current IDs

	int max_id{ 0 }; // initializing maximum ID

	int to_spawn_id{ 0 }; // this will be 1+max_id

	max_id = *std::max_element(ids.begin(), ids.end()); // stolen from stack exchange, pointer required for some reason

	to_spawn_id = max_id + 1;

	GroundLaser groundlaser(
		to_spawn_id, "groundlaser", 1.0f, WHITE, 50.0f, 
		spawn_point,
		true
	);

};

void spawn_explosion(int parent_id) { // spawn explosion entity at parent_id

	// creating new entity with new ID

	std::vector<int> ids{ ECS_obj.return_all_ids() }; // all current IDs

	int max_id{ 0 }; // initializing maximum ID

	int to_spawn_id{ 0 }; // this will be 1+max_id

	max_id = *std::max_element(ids.begin(), ids.end()); // stolen from stack exchange, pointer required for some reason

	to_spawn_id = max_id + 1;

	// getting parent id stuff 
	Vector2 position{ ECS_obj.get_entity_components(parent_id).m_position };

	Explosion explosion(
		to_spawn_id, "explosion", 1.0f, BLUE, 10.0f,
		position,
		true
	);

};