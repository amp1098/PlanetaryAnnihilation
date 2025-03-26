#include "useful_functions.h"

Vector2 center_of_points(std::vector<Vector2> points) { // finds vector average of Vector2 array
	Vector2 result{};

	for (int i = 0; i < std::size(points); i++) { // summing vectors
		result = result + points[i];
	};

	result = result / std::size(points); // scaling down according to size of array

	return result;
};


float clamp_angle(float angle) { // helper function to clamp angles to [0,2pi)
	angle = fmod(angle, 2 * PI);
	if (angle < 0) {
		angle += 2 * PI;
	};
	return angle;
};

std::vector<Vector2> circle_maker(float radius, int vertices) { // returns a vector of Vector2s representing a circular polyon
	std::vector<Vector2> result{};

	for (float i = 0; i < vertices; i++) {
		result.push_back(
			{
				radius* static_cast<float>(cos((i / vertices) * (2 * PI))), // x component
				radius * static_cast<float>(sin((i / vertices) * (2 * PI))) // y component
			}
			);
	};

	return result;
};