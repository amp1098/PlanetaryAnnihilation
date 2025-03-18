#include "raylib.h"
#include "string"
#include <vector>
#include "ECS.h"
#include "ship.h"
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

	ship playerShip(1, 1.0f, WHITE,
		{ 100.0f, 100.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f },
		{ {50.0f, 0.0f}, {-50.0f, 0.0f}, {0.0f, 95.0f} },
		12, false);

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
		camera.target = { playerShip.m_position.x, playerShip.m_position.y };

		// zoom (and zoom limiter)
		camera.zoom += ((float)GetMouseWheelMove() * 0.05f);
		if (camera.zoom > 3.0f) camera.zoom = 3.0f;
		else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

		BeginDrawing();

		ClearBackground(BLACK);

		BeginMode2D(camera);

		draw_entity(1);

		EndMode2D();

		EndDrawing();

	}

	CloseWindow();

	return 0;

}

