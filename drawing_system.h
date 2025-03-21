#ifndef DRAWING_SYSTEM_H
#define DRAWING_SYSTEM_H

#include <raylib.h>
#include <raymath.h>
#include "gen_polygon.h"
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

	vertices.rotate(rotate_angle, Vector2Zero()); // rotates about origin

	vertices.translate(translate_distance.x, translate_distance.y); // translates points

	vertices.draw();
};

std::vector<Vector2> circle_maker(float radius, int vertices) { // returns a vector of Vector2s representing a circular polyon
	std::vector<Vector2> result{};

	for (float i = 0; i < vertices; i++) {
		result.push_back(
			{ 
				radius * cos( (i / vertices) * (2 * PI) ), // x component
				radius* sin( (i / vertices) * (2 * PI)), // y component
			}
		);
	};

	return result;
};

void draw_entity(int ID) { // render entity with ID <int>(ID) on screen
	std::vector<Vector2> points{ ECS_map[ID].m_shape };
	Vector2 translate{ ECS_map[ID].m_position };
	Vector2 force{ ECS_map[ID].m_force };
	float rotate_angle{ ECS_map[ID].m_angle };
	Color color{ ECS_map[ID].m_color };
	
	/*for (int i = 0; i < std::size(points); i++) {
		DrawCircleV(points[i] + translate, 5.0f, RED);
	};*/

	//if (ECS_map[ID].m_name == "Planetoid") {

	//	for (int i = 0; i < 9; i++) {

	//		std::cout << i << ": {" << points[i].x << "," << points[i].y << "}" << std::endl;

	//	};

	//};

	draw_lines(points, translate, rotate_angle, color);

	DrawLineV(translate, force * 10 + translate, color);
};

#endif

