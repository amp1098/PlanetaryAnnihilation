#ifndef HEALTH_SYSTEM_H
#define HEALTH_SYSTEM_H

#include "ECS_obj.h"
#include <raymath.h>
#include <iostream>

// Collisions and damage in general should cause the player entity to be invincible for a few frames

void take_damage(int ent_id, float damage);

void make_invincible(int ent_id);

#endif