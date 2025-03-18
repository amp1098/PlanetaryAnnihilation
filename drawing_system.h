#ifndef DRAWING_SYSTEM_H
#define DRAWING_SYSTEM_H

#include <raylib.h>
#include <raymath.h>
#include "gen_polyon.h"
#include "ECS.h"

Vector2 center_of_points(std::vector<Vector2> points) { // finds vector average of Vector2 array
	Vector2 result{};

	for (int i = 0; i < std::size(points); i++) { // summing vectors
		result = result + points[i];
	};
	
	result = result / std::size(points); // scaling down according to size of array

	return result;
};

void draw_lines(std::vector<Vector2> points, Vector2 translate_distance, float rotate_angle, Color color) {
	gen_polygon vertices(
		points, color
	);

	vertices.translate(translate_distance.x, translate_distance.y); // translates points

	vertices.rotate(rotate_angle, center_of_points(points)); // rotates about center of points

	vertices.draw();
};

void draw_entity(int ID) { // render entity with ID <int>(ID) on screen
	std::vector<Vector2> points{ ECS_map[ID].m_shape };
	Vector2 translate{ ECS_map[ID].m_position };
	float rotate_angle{ ECS_map[ID].m_angle };
	Color color{ ECS_map[ID].m_color };

	draw_lines(points, translate, rotate_angle, color);
};

//std::cout << m_position.x << std::endl;

#endif

