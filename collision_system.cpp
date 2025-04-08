#include "collision_system.h"

bool static check_collision_planetoid(Entity entity, Entity planetoid) { // Returns true if entity's shape component is within a planetoid's shape component
	
	std::vector<Vector2> entity_shape{ entity.get_components().m_shape };
	std::vector<Vector2> planetoid_shape{ planetoid.get_components().m_shape };
	std::vector<Vector2> planetoid_center{ planetoid.get_components().m_position };

	const Vector2* test_vec{};

	// maybe iterate through each point on entity shape and check for collisions?
	// the (Vector2*)planetoid_shape.data() is a typecast, I think

	for (int i = 0; i < std::size(entity_shape); i++) { // iterating through indices in entity_shape

		if (CheckCollisionPointPoly(entity_shape[i], (Vector2*)planetoid_shape.data(), std::size(planetoid_shape))) {

			return true;

		};

	};

};

int return_id_colliding_planetoid(Entity entity) { // returns of ID of planetoid entity that is colliding with entity
	
	std::vector<int> ids{};

	ids = ECS_obj.return_ids_with_name("planetoids");

};
