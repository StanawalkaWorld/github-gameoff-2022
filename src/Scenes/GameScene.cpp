#include "Scenes/GameScene.hpp"

void GameScene::Start()
{
	m_level_bg = LoadTexture("assets/img/bg/level_01.png");
}

void GameScene::Update()
{
}

void GameScene::Render()
{
	DrawTexture(m_level_bg, 0, 0, WHITE);
}

void GameScene::Switch()
{
}
