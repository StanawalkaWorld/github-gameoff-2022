#include "Scenes/GameScene.hpp"

GameScene::GameScene()
{
	m_level_bg = LoadTexture("assets/img/bg/level_01.png");
}

GameScene::~GameScene()
{
	UnloadTexture(m_level_bg);
}

void GameScene::Start()
{
	
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
