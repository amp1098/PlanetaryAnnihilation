#ifndef DRAWING_SYSTEM_H
#define DRAWING_SYSTEM_H

#include <raylib.h>
#include <raymath.h>
#include "gen_polygon.h"
#include "ECS_obj.h"
#include "useful_functions.h"

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

float angle_of_vec_diff_dbug(Vector2 vec1, Vector2 vec2) { // remove later, already in physics system, for debugging
	Vector2 vec_res{ vec1 - vec2 };

	return clamp_angle(atan2(vec_res.y, vec_res.x));
};

void draw_entity(int ID) { // render entity with ID <int>(ID) on screen
	std::vector<Vector2> points{ ECS_obj.ECS_map[ID].m_shape };
	Vector2 translate{ ECS_obj.ECS_map[ID].m_position };
	Vector2 force{ ECS_obj.ECS_map[ID].m_force };
	float rotate_angle{ ECS_obj.ECS_map[ID].m_angle };
	Color color{ ECS_obj.ECS_map[ID].m_color };
	int target_ID{ ECS_obj.ECS_map[ID].m_target_id};

	draw_lines(points, translate, rotate_angle, color);

	DrawLineV(translate, force * 10 + translate, color);

	if (ECS_obj.ECS_map[ID].m_name == "ship" && target_ID != 0) {
		DrawLineV(translate, Vector2Rotate(Vector2UnitX * 100, rotate_angle) + translate, BLUE); // ship angle
		DrawLineV(translate, Vector2Rotate(Vector2UnitX * 100, angle_of_vec_diff_dbug(ECS_obj.ECS_map[target_ID].m_position, translate)) + translate, BLUE); // target angle
	};
};

#endif

