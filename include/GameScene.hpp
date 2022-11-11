#pragma once
#include "Scene.hpp"

#include <raylib.h>

class GameScene : public Scene {
private:
	Texture2D m_level_bg;

public:
	void Start() override;
	void Update() override;
	void Render() override;
	void Switch() override;
};