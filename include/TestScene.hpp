#pragma once
#include <iostream>
#include <raylib.h>

#include "Scene.hpp"

using std::cout, std::endl;

class TestScene : public Scene {
private:
	Font pixeltype_font;
	float m_text_width = 0;

	Vector2 m_text_pos{ 0, 0 };

public:
	TestScene() {
		pixeltype_font = LoadFont("assets/fonts/Pixeltype.ttf");
	}

	~TestScene() {
		UnloadFont(pixeltype_font);
	}

	void Start() override {
		cout << "Test scene initialized." << endl;

		m_text_width = MeasureTextEx(pixeltype_font, "Test text", 26, 5).x;
	}
	void Update() override {
		m_text_pos = {
			static_cast<float>(std::sin(GetTime() * 5) * 50 + WINDOW_WIDTH / 2 - m_text_width / 2),
			static_cast<float>(std::cos(GetTime() * 5) * 50 + WINDOW_HEIGHT / 2)
		};
	}
	void Render() override {
		ClearBackground(BLACK);
		DrawTextEx(pixeltype_font, "Test text", m_text_pos, 26, 5, RAYWHITE);
	}
	void Switch() override {

	}
};