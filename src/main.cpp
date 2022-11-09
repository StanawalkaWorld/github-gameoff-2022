#include <raylib.h>
#include "SceneManager.hpp"

int main() {
	InitWindow(800, 600, "Test Window");

	SceneManager sm;

	while (!WindowShouldClose()) {

		BeginDrawing();
			ClearBackground({ 10, 10, 10, 255 });
			DrawText("Hello World!", 20, 20, 32, RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
}