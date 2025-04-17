#include "Polygons.h"
Polygons::Polygons() {};

std::vector<Vector2> Polygons::poly_ship() { // return ship polygon
	return { { -30.0f, -40.0f }, { -30.0f, 40.0f }, { 60.0f, 0.0f } };
};

std::vector<Vector2> Polygons::poly_missile() { // return missile polygon
	return {
		{ 0.0f, 10.0f }, { -45.0f, 10.0f }, { -45.0f, -10.0f }, { 0.0f, -10.0f },
		{ 25.0f, 0.0f },
	};
};

std::vector<Vector2> Polygons::poly_groundlaser() { // return missile polygon
	return {
		{ 0.0f, 10.0f }, { -45.0f, 10.0f }, { -45.0f, -10.0f }, { 0.0f, -10.0f },
		{ 0, 5.0f }, { 45.0f, 5.0f }, { 45.0f, -5.0f }, { 0, -5.0f },
	};
};

std::vector<Vector2> Polygons::poly_explosion() { // return explosion polygon 
	return {
		circle_maker(150.0f, 15)
	};
}