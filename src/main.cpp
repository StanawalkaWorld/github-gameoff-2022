#include <raylib.h>

int main() {
	InitWindow(800, 600, "Test Window");

	while (!WindowShouldClose()) {

		BeginDrawing();
			ClearBackground({ 10, 10, 10, 255 });
			DrawText("Hello World!", 20, 20, 32, RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
}