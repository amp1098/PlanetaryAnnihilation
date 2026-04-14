#ifndef USEFUL_FUNCTIONS_H
#define USEFUL_FUNCTIONS_H

#include <vector>
#include <raylib.h>
#include <raymath.h>

float const dt = 0.5f; // for integration, used by many systems

Vector2 center_of_points(std::vector<Vector2> points);

// helper function to clamp angles to [0,2pi)

float clamp_angle(float angle);

std::vector<Vector2> circle_maker(float radius, int vertices);

float mean(std::vector<float> input_vector);

Vector2 Vector2Mean(std::vector<Vector2> input_vectors);

float minimum_angle(float input_angle);

float num_deriv_backwards(float first_value, float second_value);

float num_deriv_array_backwards(std::vector<float> vals_to_diff);

float num_deriv_centered(float x_t_pls_1, float x_t_min_1);

float num_deriv_centered_angles(float x_t_pls_1, float x_t_min_1);

float num_deriv_array_centered(std::vector<float> vals_to_diff);

float angle_of_vec_diff(Vector2 vec1, Vector2 vec2);

float angle_of_vec_diff_unclamped(Vector2 vec1, Vector2 vec2);

float better_sign_function(float x);

#endif