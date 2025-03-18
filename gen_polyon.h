#ifndef GEN_POLYGON_H
#define GEN_POLYGON_H

#include <raylib.h>
#include <vector>

class gen_polygon { // used to draw unfilled polygons
public:
	Color m_color;
	std::vector<Vector2> m_points;

	gen_polygon(std::vector<Vector2> points, Color color) {
		m_points = points;
		m_color = color;
	};

	void translate(float dX, float dY) {
		for (int i = 0; i < std::size(m_points); i++) {
			m_points[i].x += dX;
			m_points[i].y += dY;
		};
	};

	void rotate(float angle, Vector2 pivot) { // rotate one point about another point
		for (int i = 0; i < std::size(m_points); i++) {
			// moving to pivot
			m_points[i].x = m_points[i].x - pivot.x;
			m_points[i].y = m_points[i].y - pivot.y;

			// rotating about origin
			m_points[i].x = cos(angle) * m_points[i].x + sin(angle) * m_points[i].y;
			m_points[i].y = sin(angle) * m_points[i].x - cos(angle) * m_points[i].y;

			// moving back
			m_points[i].x = m_points[i].x + pivot.x;
			m_points[i].y = m_points[i].y + pivot.y;
		};
	};

	void draw() const { // must be called in BeginDrawing() --> EndDrawing() loop
		for (int i = 0; i < std::size(m_points); i++) { // count from 0 to m_numPoints - 1
			int j = (i + 1) % std::size(m_points); // modulo makes sure j never goes over number of points in shape
			DrawLineV(m_points[i], m_points[j], m_color); // draw line between Vector2 objects in points container
		}
	};

	
};

#endif
