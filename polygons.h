#ifndef POLYGONS_H
#define POLYGONS_H

#include <vector>
#include <raylib.h>

class polygons { // used to easily call vectors of Vector2 objects for entity shapes
public:

	std::vector<Vector2> vertices{};

	polygons() {};

	static std::vector<Vector2> poly_ship() { // return ship polygon
		return { { -30.0f, -40.0f }, { -30.0f, 40.0f }, { 60.0f, 0.0f } };
	};

	static std::vector<Vector2> poly_missile() { // return ship polygon
		return { 
			{ 0.0f, 10.0f }, { -45.0f, 10.0f }, { -45.0f, -10.0f }, { 0.0f, -10.0f },
			{ 25.0f, 0.0f },
		};
	};

};

#endif