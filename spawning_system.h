#ifndef SPAWNING_SYSTEM_H
#define SPAWNING_SYSTEM_H

#include "ECS_obj.h"
#include <raymath.h>
#include "useful_functions.h"
#include "polygons.h"
#include <algorithm> // for max_element
#include "entities.h"

int return_unused_id();

void random_spawn_on_planetoid();

void spawn_explosion(int parent_id);

void despawn_dead_entity(int ent_id);

void spawn_missile_at_position(Vector2 position);

#endif
