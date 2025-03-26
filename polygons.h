#ifndef POLYGONS_H
#define POLYGONS_H

#include <vector>
#include <raylib.h>

class Polygons { // used to easily call vectors of Vector2 objects for entity shapes

	std::vector<Vector2> vertices{};

public:

	Polygons();

	static std::vector<Vector2> poly_ship();

	static std::vector<Vector2> poly_missile();

};

#endif