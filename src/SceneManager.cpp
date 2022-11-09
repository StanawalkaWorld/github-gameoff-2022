#include <raylib.h>

#include "SceneManager.hpp"

void SceneManager::LoadScene(Scene* scene, int id)
{
	if (id >= SCENE_N)
		return;

	m_loaded_scenes[id] = std::unique_ptr<Scene>(scene);
	scene->sceneChangeEvent.Listen([this](int id) {
		ChangeScene(id);
	});
}

void SceneManager::UpdateScene()
{
	if (!m_loaded_scenes[m_current_scene])
		return;

	m_loaded_scenes[m_current_scene]->Update();

	if (!m_scene_change_requested)
	{
		BeginDrawing();
			m_loaded_scenes[m_current_scene]->Render();
		EndDrawing();
	}
	else
	{
		m_scene_change_requested = false;
	}
}

void SceneManager::ChangeScene(int id)
{
	if (id < SCENE_N && m_loaded_scenes[id]) {
		m_loaded_scenes[m_current_scene]->Switch();

		m_current_scene = id;
		m_loaded_scenes[id]->Start();

		m_scene_change_requested = true;
	}
}

void SceneManager::UnloadScene(int id)
{
	m_loaded_scenes[id].reset();
}
