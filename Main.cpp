#include "raylib.h"
#include "string"
#include <vector>
#include "ECS.h"
#include "ship.h"
#include "systems.h"

//======== entry point =========//

int main(void)
{
	const int sWidth = 2000;
	const int sHeight = 1600;

	// delete this later

	const float posx{ 0.0f };
	const float posy{ 0.0f };

	// delete this later

	InitWindow(sWidth, sHeight, "Planetary Annhilation");

	// === RAYLIB STUFF ===

	int spacing = 0;

	Camera2D camera = { 0 };

	camera.target = { 1.0f, 2.0f };

	camera.target = { posx + 20.0f, posx + 20.0f };
	camera.offset = { sWidth / 2.0f, sHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	SetTargetFPS(60);

	// adding a ship object

	ship playerShip (1, 1.0f, BLUE,
		{ 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f },
		{ {50.0f, 0.0f}, {-50.0f, 0.0f}, {0.0f, 86.0f} },
		12, false);

	while (!WindowShouldClose())
	{

		// camera target follows player
		camera.target = { posx + 20, posx + 20 };

		// zoom (and zoom limiter)
		camera.zoom += ((float)GetMouseWheelMove() * 0.05f);
		if (camera.zoom > 3.0f) camera.zoom = 3.0f;
		else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

		BeginDrawing();

		ClearBackground(BLACK);

		draw_entity(1);

		BeginMode2D(camera);

		EndMode2D();

		EndDrawing();

	}

	CloseWindow();

	return 0;

}

