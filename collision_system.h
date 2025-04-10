#ifndef COLLISION_SYSTEM_H
#define COLLISIONS_SYSTEM_H

#include "ECS_obj.h"
#include <raymath.h>
#include <iostream>
#include "Entity.h"

bool check_collision_planetoid(int ent_id, int planetoid_id);

int return_id_colliding_planetoid(int ent_id);

#endif