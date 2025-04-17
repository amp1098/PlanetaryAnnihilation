#ifndef SPAWNING_SYSTEM_H
#define SPAWNING_SYSTEM_H

#include "ECS_obj.h"
#include <raymath.h>
#include "useful_functions.h"
#include "polygons.h"
#include <algorithm> // for max_element

void random_spawn_on_planetoid();

void spawn_explosion(int parent_id);

#endif
