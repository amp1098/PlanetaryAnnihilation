#include "useful_functions.h"

static Vector2 center_of_points(std::vector<Vector2> points) { // finds vector average of Vector2 array
	Vector2 result{};

	for (int i = 0; i < std::size(points); i++) { // summing vectors
		result = result + points[i];
	};

	result = result / std::size(points); // scaling down according to size of array

	return result;
};

// helper function to clamp angles to [0,2pi)

static float clamp_angle(float angle) {
	angle = fmod(angle, 2 * PI);
	if (angle < 0) {
		angle += 2 * PI;
	};
	return angle;
};