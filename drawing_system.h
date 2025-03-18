#ifndef DRAWING_SYSTEM_H
#define DRAWING_SYSTEM_H

#include <raylib.h>
#include "gen_polyon.h"
#include "ECS.h"

void draw_lines(std::vector<Vector2> points, Vector2 translate, Color color) {
	gen_polygon vertices(
		points, color
	);

	vertices.translate(translate.x, translate.y);

	vertices.draw();
};

void draw_entity(int ID) { // render entity with ID <int>(ID) on screen
	std::vector<Vector2> points = ECS_map[ID].m_shape;
	Vector2 translate = ECS_map[ID].m_position;
	Color color = ECS_map[ID].m_color;

	draw_lines(points, translate, color);
};

//std::cout << m_position.x << std::endl;

#endif

