#ifndef COLLISION_SYSTEM_H
#define COLLISIONS_SYSTEM_H

#include "ECS_obj.h"
#include <raymath.h>
#include <iostream>
#include "Entity.h"

bool static check_collision_planetoid(Entity entity, Entity planetoid);

int return_id_colliding_planetoid(Entity entity);

#endif