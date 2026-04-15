#include "useful_functions.h"

Vector2 center_of_points(std::vector<Vector2> points) { // finds vector average of Vector2 array
	Vector2 result{};

	for (int i = 0; i < std::size(points); i++) { // summing vectors
		result = result + points[i];
	};

	result = result / std::size(points); // scaling down according to size of array

	return result;
}


float clamp_angle(float angle) { // helper function to clamp angles to [0,2pi)
	angle = fmod(angle, 2 * PI);
	if (angle < 0) {
		angle += 2 * PI;
	};
	return angle;
}

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
}

float mean(std::vector<float> input_vector) { // iterates over elements of vector, finds arithmetic mean

	float total_of_elements{};

	for (int i = 0; i < std::size(input_vector); i++) {

		total_of_elements += input_vector[i];

	};

	float result = total_of_elements / std::size(input_vector);

	return result;

}

Vector2 Vector2Mean(std::vector<Vector2> input_vectors) { // iterates over vector of Vector2 objects, finds mean, custom :)

	Vector2 sum_vector{0.0f, 0.0f};

	for (int i = 0; i < std::size(input_vectors); i++) {

		sum_vector = Vector2Add(sum_vector, input_vectors[i]);

	};

	Vector2 result = sum_vector / std::size(input_vectors);

	return result;

}

float minimum_angle(float input_angle) { // returns abs_val minimum of input_angle and 2 * PI - input_angle

	if (abs(input_angle) <= 2 * PI - abs(input_angle)) {
		return input_angle;
	}
	else {
		return copysignf(input_angle, input_angle) * (2 * PI - abs(input_angle));
	};


}

float num_deriv_backwards(float first_value, float second_value) { // returns average rate of change over time interval dt
	// uses backwards derivative method, first order error
	return (second_value - first_value) / dt;

}

float num_deriv_array_backwards(std::vector<float> vals_to_diff) { // works like num_deriv but accepts std::vector<float> type
	float val1 = vals_to_diff.at(0);
	float val2 = vals_to_diff.at(1);

	return num_deriv_backwards(val1, val2);
}

float num_deriv_centered(float x_t_pls_1, float x_t_min_1) { // returns average rate of change over time interval dt 
	// uses centered derivative method, second order error, see ideas.txt
	return (x_t_pls_1 - x_t_min_1) / (2 * dt);

}

float num_deriv_centered_angles(float x_t_pls_1, float x_t_min_1) { // returns average ROC of angles, uses minumum angle function

	float angle_diff = x_t_min_1 - x_t_pls_1;

	float sign_of_difference = copysignf(1, angle_diff); // gets sign of the difference, needed to fix jump in derivative

	float numerator{};

	if (abs(angle_diff) >= PI) { numerator = sign_of_difference * (abs(angle_diff) - (2 * PI)); }
	else { numerator = angle_diff; }

	return numerator / (2 * dt);

}

float num_deriv_array_centered(std::vector<float> vals_to_diff) { // works like num_deriv but accepts std::vector<float> type
	// takes array with 3 elements
	float val1 = vals_to_diff.at(0); // t-1
	float val2 = vals_to_diff.at(2); // t+1

	return num_deriv_centered_angles(val2, val1);

}

float angle_of_vec_diff(Vector2 vec1, Vector2 vec2) { // returns angle of vector difference of vec1 and vec2
	Vector2 vec_res{ vec1 - vec2 };

	float angle_diff = clamp_angle(atan2(vec_res.y, vec_res.x) + PI); // the PI is needed due to left handed coordinate system

	return angle_diff;

}

float angle_of_vec_diff_unclamped(Vector2 vec1, Vector2 vec2) { // returns angle of vector difference of vec1 and vec2, does not use clamp
	// (see useful_functions.cpp)
	Vector2 vec_res{ vec2 - vec1 };

	float angle_output = atan2(vec_res.y, vec_res.x);

	if (angle_output < PI) {

		return angle_output;

	}
	else {

		return 2 * PI - angle_output;

	};
}

float better_sign_function(float x) {
	x = 2 * signbit(x) - 1;
	return x;
}

Vector3 Vector2_as_Vector3(Vector2 vec) { // projects 2D vector into 3D space with a third zero element

	Vector3 output_vec{};

	output_vec = { vec.x, vec.y, 0.0f };

	return output_vec;

};

float Vector2CrossProductLength(Vector2 vec1, Vector2 vec2) { // finds cross product of 2D vectors by projecting into 3D and back to 2D

	Vector3 proj_vec1{ Vector2_as_Vector3(vec1) };

	Vector3 proj_vec2{ Vector2_as_Vector3(vec2) };

	Vector3 cross_product{ Vector3CrossProduct(proj_vec1, proj_vec2) };

	float output{ Vector3Length(cross_product) };

	return output;

};

float moment_of_inertia(float mass_of_object, std::vector<Vector2> points) { // for uniform point masses, assuming points are relative to COM
	float moment{};

	float mass_of_each_point{ mass_of_object / std::size(points) };

	// TODO: shouldnt center of points be calculated?
	// just find mean
	// center_of_points = {mean(points.x), mean(points.y)}
	Vector2 center_of_points{ Vector2Mean(points) }; // we can subtract this from each element in points to move to {0,0}

	for (int i = 0; i < std::size(points); i++) { // for each index corresponding to each point
		moment += mass_of_each_point * Vector2LengthSqr(points[i] - center_of_points);
	};

	return moment;
};