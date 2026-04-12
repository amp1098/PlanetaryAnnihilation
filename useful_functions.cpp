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

float mean(std::vector<float> input_vector) { // iterates over elements of vector, finds arithmetic mean

	float total_of_elements{};

	for (int i = 0; i < std::size(input_vector); i++) {

		total_of_elements += input_vector[i];

	};

	float result = total_of_elements / std::size(input_vector);

	return result;

};

Vector2 Vector2Mean(std::vector<Vector2> input_vectors) { // iterates over vector of Vector2 objects, finds mean, custom :)

	Vector2 sum_vector{0.0f, 0.0f};

	for (int i = 0; i < std::size(input_vectors); i++) {

		sum_vector = Vector2Add(sum_vector, input_vectors[i]);

	};

	Vector2 result = sum_vector / std::size(input_vectors);

	return result;

};