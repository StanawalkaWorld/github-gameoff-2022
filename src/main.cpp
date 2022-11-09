#include <raylib.h>
#include "Globals.hpp"

#include "SceneManager.hpp"
#include "TestScene.hpp"

int main() {
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Test Window");

	SceneManager sm;

	sm.LoadScene(new TestScene(), 0);

	while (!WindowShouldClose()) {

		sm.UpdateScene();
	}

	CloseWindow();
}