#include "health_system.h"

void take_damage(int ent_id, float damage) {

	float current_health{ ECS_obj.get_entity_components(ent_id).m_health };

	float damaged_health{current_health - damage};

	ECS_obj.set_health(ent_id, damaged_health);

};

void make_invincible(int ent_id) { // when called, should make an entity invincible for ~60 frames (~1s)

	double init_time{ GetTime() }; // gets time in seconds since InitWindow called

	if (init_time < init_time + GetFrameTime() * 60.0f) {

		init_time += GetFrameTime();

		ECS_obj.set_invincible(ent_id, true);

	};

	ECS_obj.set_invincible(ent_id, false);

};