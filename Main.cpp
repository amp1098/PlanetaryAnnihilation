#include "raylib.h"
#include "string"
#include <vector>
#include "ECS.h"
#include "ship.h"
#include "Planetoid.h"
#include "systems.h"
#include <iostream>

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

	ship playerShip(
		playerID, "ship", 1.0f, WHITE,
		{ 100.0f, 600.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f }, {0.0f, 0.0f},
		0.0f, 0.0f, 0.0f, 0.0f,
		{ {-30.0f, -40.0f}, {-30.0f, 40.0f}, {60.0f, 0.0f} },
		12, false, false);

	Planetoid planet1(
		2, "planet", 1000.0f, WHITE,
		{0.0f, 0.0f},
		circle_maker(500.0f, 30), false, false
	);

	Planetoid planet2(
		4, "planet", 10000.0f, WHITE,
		{ 5000.0f, 5000.0f },
		circle_maker(2000.0f, 500), false, true
	);

	Camera2D camera = { 0 };

	camera.target = { 1.0f, 2.0f };

	camera.target = { playerShip.m_position.x, playerShip.m_position.y };
	camera.offset = { sWidth / 2.0f, sHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// camera target follows player
		camera.target = { ECS_map[1].m_position.x, ECS_map[1].m_position.y};

		// zoom (and zoom limiter)
		camera.zoom += ((float)GetMouseWheelMove() * 0.05f);
		if (camera.zoom > 3.0f) camera.zoom = 3.0f;
		else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

		BeginDrawing();

		ClearBackground(BLACK);

		BeginMode2D(camera);

		use_systems();

		EndMode2D();

		EndDrawing();

	}

	CloseWindow();

	return 0;

}

