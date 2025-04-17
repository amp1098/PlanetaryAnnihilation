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
		playerID, "ship", 1.0f, WHITE, 100.0f, true
	);

	Missile testMissile1(
		3, "missile", 1.0f, GREEN, 10.0f, true
	);

	Planetoid planet2(
		4, 10000.0f, WHITE,
		{ 5000.0f, 5000.0f },
		circle_maker(5000.0f, 500), false, true, true
	);

	for (int i = 0; i < 20; i++) {
		GroundLaser laser(
			i + 6, "groundlaser", 1.0f, WHITE, 10.0f, false
		);
	};
	

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

