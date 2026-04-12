#ifndef USEFUL_FUNCTIONS_H
#define USEFUL_FUNCTIONS_H

#include <vector>
#include <raylib.h>
#include <raymath.h>

Vector2 center_of_points(std::vector<Vector2> points);

// helper function to clamp angles to [0,2pi)

float clamp_angle(float angle);

std::vector<Vector2> circle_maker(float radius, int vertices);

float mean(std::vector<float> input_vector);

Vector2 Vector2Mean(std::vector<Vector2> input_vectors);

#endif