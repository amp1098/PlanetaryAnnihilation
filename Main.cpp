#include "raylib.h"
#include "string"
#include <vector>
#include "ECS_obj.h"
#include "entities.h"
#include "systems.h"
#include <iostream>
#include "polygons.h"

//======== entry point =========//

int main(void)
{

	const int sWidth = 2000;
	const int sHeight = 1600;

	InitWindow(sWidth, sHeight, "Planetary Annhilation");

	// === RAYLIB STUFF ===

	int spacing = 0;

	// adding a ship object
	
	int playerID = 1;

	Ship playerShip(
		playerID, "ship", 1.0f, WHITE,
		{ 100.0f, 600.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f }, {0.0f, 0.0f},
		0.0f, 0.0f, 0.0f, 0.0f,
		Polygons::poly_groundlaser(),
		0, 0,
		false, false, true, true);

	Missile testMissile1(
		3, "missile", 1.0f, YELLOW,
		{ 300.0f, 800.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f },
		0.0f, 0.0f, 0.0f, 0.0f,
		Polygons::poly_missile(),
		playerID, 0,
		false, false, true, true);

	Missile testMissile2(
		5, "missile", 1.0f, YELLOW,
		{ 1000.0f, 1200.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f },
		0.0f, 0.0f, 0.0f, 0.0f,
		Polygons::poly_missile(),
		playerID, 0,
		false, false, true, true);

	Planetoid planet1(
		2, 1000.0f, WHITE,
		{300.0f, 0.0f},
		circle_maker(100.0f, 30), false, false, true
	);

	Planetoid planet2(
		4, 10000.0f, WHITE,
		{ 5000.0f, 5000.0f },
		circle_maker(5000.0f, 500), false, true, true
	);

	GroundLaser laser1(
		6, "laser1", 100.0f, WHITE
	);

	Camera2D camera = { 0 };

	camera.target = { 1.0f, 2.0f };

	camera.target = { playerShip.get_components().m_position.x, playerShip.get_components().m_position.y};
	camera.offset = { sWidth / 2.0f, sHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	SetTargetFPS(60);

	while (!WindowShouldClose())

	{
		// camera target follows player
		camera.target = { ECS_obj.get_entity_components(1).m_position.x, ECS_obj.get_entity_components(1).m_position.y};

		// zoom (and zoom limiter)
		camera.zoom += ((float)GetMouseWheelMove() * 0.05f);
		if (camera.zoom > 3.0f) camera.zoom = 3.0f;
		else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

		BeginDrawing();

		ClearBackground(BLACK);

		BeginMode2D(camera);

		use_systems(); // entitiy's components are updated through systems

		EndMode2D();

		EndDrawing();

	}

	CloseWindow();

	return 0;

}

