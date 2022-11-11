#pragma once
#include "Scene.hpp"

#include <raylib.h>

#include "GameObjects/GameObject.hpp"

class GameScene : public Scene {
private:
	Texture2D m_level_bg;
	GameObject player;

public:
	GameScene();
	~GameScene();

	void Start() override;
	void Update() override;
	void Render() override;
	void Switch() override;
};