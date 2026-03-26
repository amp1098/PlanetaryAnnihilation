#ifndef ECS_OBJ_H
#define ECS_OBJ_H

#include "ECS.h"
using EntityComponentSystem::ECS;
extern ECS ECS_obj; // this object stores entity data, referenced throughout game files

float const dt = 0.01f; // for integration, used by many systems

#endif // !ECS_MAP_H
