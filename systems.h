#ifndef SYSTEMS_H
#define SYSTEMS_H
// include all the systems here and maybe add some comments describing what they do

#include "drawing_system.h" // draws entities to screen via draw_entity(ID)

#include "physics_system.h" // updates positions of entities based on physical models (kinematics, etc)

#include "control_system.h" // updates forces/torques of entities based on keyboard inputs

#include "health_system.h"  // handles damage to entities

#include "collision_system.h" // checks for collisions

#include "spawning_system.h"  // spawns entities

void use_initializer_systems();

void use_systems();

#endif

