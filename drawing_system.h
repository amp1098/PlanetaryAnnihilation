#ifndef DRAWING_SYSTEM_H
#define DRAWING_SYSTEM_H

#include <raylib.h>
#include <raymath.h>
#include "GeneralPolygon.h"
#include "ECS_obj.h"
#include "useful_functions.h"

void draw_lines(std::vector<Vector2> points, Vector2 translate_distance, float rotate_angle, Color color);

float angle_of_vec_diff_dbug(Vector2 vec1, Vector2 vec2);

void draw_entity(int ID);

#endif

