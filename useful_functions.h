#ifndef USEFUL_FUNCTIONS_H
#define USEFUL_FUNCTIONS_H

#include <vector>
#include <raylib.h>

Vector2 center_of_points(std::vector<Vector2> points) { // finds vector average of Vector2 array
	Vector2 result{};

	for (int i = 0; i < std::size(points); i++) { // summing vectors
		result = result + points[i];
	};

	result = result / std::size(points); // scaling down according to size of array

	return result;
};

#endif