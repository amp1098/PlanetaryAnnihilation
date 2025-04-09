#include "collision_system.h"

bool check_collision_planetoid(int ent_id, int planetoid_id) { // Returns true if entity's shape component is within a planetoid's shape component
	
	std::vector<Vector2> entity_shape{ ECS_obj.get_entity_components(ent_id).m_shape };
	Vector2 entity_position{ ECS_obj.get_entity_components(ent_id).m_position};

	std::vector<Vector2> planetoid_shape{ ECS_obj.get_entity_components(planetoid_id).m_shape };
	Vector2 planetoid_position{ ECS_obj.get_entity_components(planetoid_id).m_position };

	const Vector2* test_vec{};

	// maybe iterate through each point on entity shape and check for collisions?
	// the (Vector2*)planetoid_shape.data() is a typecast, I think

	for (int i = 0; i < std::size(entity_shape); i++) { // iterating through indices in entity_shape

		if (CheckCollisionPointPoly(entity_shape[i] + entity_position, (Vector2*)planetoid_shape.data(), std::size(planetoid_shape))) {
			
			std::cout << "collision: " << entity_shape[i].x << std::endl;
			
			return true;

		};

	};

};

int return_id_colliding_planetoid(int ent_id) { // returns of ID of planetoid entity that is colliding with entity
	
	std::vector<int> ids{};

	int result{ 0 };

	ids = ECS_obj.return_ids_with_name("planetoids");

	for (int id = 0; id < std::size(ids); id++) {

		if (check_collision_planetoid(ent_id, id)) {

			result = id;

			std::cout << result << std::endl;

		};

	};

	return result;

};
