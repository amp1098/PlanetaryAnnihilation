#include "collision_system.h"

bool check_collision_planetoid(int ent_id, int planetoid_id) { // Returns true if entity's shape component is within a planetoid's shape component
	
	std::vector<Vector2> entity_shape{ ECS_obj.get_entity_components(ent_id).m_shape };
	Vector2 entity_position{ ECS_obj.get_entity_components(ent_id).m_position};

	std::vector<Vector2> planetoid_shape{ ECS_obj.get_entity_components(planetoid_id).m_shape };
	Vector2 planetoid_position{ ECS_obj.get_entity_components(planetoid_id).m_position };

	std::vector<Vector2> translated_planetoid_shape{};

	for (int i = 0; i < std::size(planetoid_shape); i++) { // translating planetoid_shape so collisions match where planetoid is
		translated_planetoid_shape.push_back(planetoid_shape[i] + planetoid_position);
	};

	// maybe iterate through each point on entity shape and check for collisions?
	// the (Vector2*)planetoid_shape.data() is a typecast, I think

	for (int i = 0; i < std::size(entity_shape); i++) { // iterating through indices in entity_shape

		if (CheckCollisionPointPoly(entity_shape[i] + entity_position, (Vector2*)translated_planetoid_shape.data(), std::size(planetoid_shape))) {

			return true;

		}

		else {

			return false;

		};

	};

};

int return_id_colliding_planetoid(int ent_id) { // returns of ID of planetoid entity that is colliding with entity
	
	std::vector<int> ids{};

	int result{ 0 };

	ids = ECS_obj.return_ids_with_name("Planetoid");

	for (int index = 0; index < std::size(ids); index++) {

		if (check_collision_planetoid(ent_id, ids[index])) {

			result = ids[index];

			//std::cout << "ID: " << ids[0] << std::endl;

			//std::cout << "Result: " << result << std::endl;

		};

	};

	return result;

};

void collision_health_response(int ent_id) { // if entity is colliding with planetoid, make its health 0
	
	if ( return_id_colliding_planetoid(ent_id) != 0) { // if returned ID is 0, no collision is occuring

		std::cout << "health subtracted" << std::endl;

		ECS_obj.set_health(ent_id, 0.0f);

	};

};
