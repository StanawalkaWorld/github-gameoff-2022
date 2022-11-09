#pragma once
#include <iostream>
#include <raylib.h>

#include "Scene.hpp"

using std::cout, std::endl;

class TestScene : public Scene {
private:
	Font pixeltype_font;
	
	int frames_elapsed = 0;
	Vector2 text_pos{ 0, 0 };


public:
	TestScene() {
		pixeltype_font = LoadFont("assets/fonts/pixeltype.ttf");
	}

	~TestScene() {
		UnloadFont(pixeltype_font);
	}

	void Start() override {
		cout << "Test scene initialized." << endl;
	}
	void Update() override {
		frames_elapsed++;

		text_pos = { 
			static_cast<float>(std::sin(frames_elapsed) * 50 + WINDOW_WIDTH / 2),
			static_cast<float>(std::cos(frames_elapsed) * 50 + WINDOW_HEIGHT / 2)
		};
	}
	void Render() override {
		ClearBackground(BLACK);
		DrawTextEx(pixeltype_font, "Test text", text_pos, 26, 5, RAYWHITE);
	}
	void Switch() override {

	}
};