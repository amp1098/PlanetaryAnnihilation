#ifndef PHYSICS_SYSTEM_H
#define PHYSICS_SYSTEM_H

#include "ECS_obj.h"
#include <raymath.h>
#include "useful_functions.h"

float const G = 1000.0f; // for gravity scaling
float const dt = 0.1f; // for integration

Vector2 univ_grav(float m1, float m2, Vector2 pos1, Vector2 pos2);
float moment_of_inertia(float mass_of_each_point, std::vector<Vector2> points);
float angle_of_vec_diff(Vector2 vec1, Vector2 vec2);

float better_sign_function(float x);

void physics_update(int ID);
#endif // !PHYSICS_SYSTEM_H

