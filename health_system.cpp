#include "health_system.h"

void take_damage(int ent_id, float damage) {

	float current_health{ ECS_obj.get_entity_components(ent_id).m_health };

	float damaged_health{current_health - damage};

	ECS_obj.set_health(ent_id, damaged_health);

};

void make_invincible(int ent_id, int frames) { // when called, should make an entity invincible for # of frames

	int iframes_counter{ ECS_obj.get_entity_components(ent_id).m_invincible_counter };

	bool invincible{ ECS_obj.get_entity_components(ent_id).m_invincible };

	if (iframes_counter == 0 && !invincible) { // if counter is at 0

		ECS_obj.set_invincible_counter(ent_id, frames);

	}
	else if (iframes_counter > 0 && !invincible) { // if counter not 0 and ent not invincible

		ECS_obj.set_invincible_counter(ent_id, iframes_counter - 1);

		ECS_obj.set_invincible(ent_id, true);

	}
	else if (iframes_counter > 0 && invincible) {// if counter not 0 and ent invincible

		ECS_obj.set_invincible_counter(ent_id, iframes_counter - 1);

	}
	else { // if counter at 0 and ent invincible

		ECS_obj.set_invincible(ent_id, false);

	};



};