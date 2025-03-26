#ifndef GEN_POLYGON_H
#define GEN_POLYGON_H

#include <raylib.h>
#include <raymath.h>
#include <vector>

class GeneralPolygon { // used to draw unfilled polygons
	Color m_color;
	std::vector<Vector2> m_points;

public:

	GeneralPolygon(std::vector<Vector2> points, Color color);

	void translate(float dX, float dY);

	void rotate(float angle, Vector2 pivot);

	void draw();
};

#endif
