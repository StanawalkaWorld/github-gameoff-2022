#include "SceneManager.hpp"

void SceneManager::LoadScene(Scene* scene, int id)
{
	if (id < 8)
		m_loaded_scenes[id] = std::unique_ptr<Scene>(scene);
}

void SceneManager::UpdateScene()
{
	m_loaded_scenes[m_current_scene]->Update();
	m_loaded_scenes[m_current_scene]->Render();
}

void SceneManager::ChangeScene(int id)
{
	if (id < 8 && m_loaded_scenes[id]) {
		m_loaded_scenes[m_current_scene]->Switch();

		m_current_scene = id;
		m_loaded_scenes[id]->Start();
	}
}

void SceneManager::UnloadScene(int id)
{
	m_loaded_scenes[id].reset();
}
