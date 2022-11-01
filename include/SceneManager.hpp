#pragma once
#include <array>
#include <memory>

#include "Scene.hpp"

template <int SCENE_N>
class SceneManager {
private:
	using SceneCollection = std::array<std::unique_ptr<Scene>, SCENE_N>;
	SceneCollection m_loaded_scenes;

	int m_current_scene = 0;
	bool m_scene_change_requested = false;
public:
	void LoadScene(Scene* scene, int id);
	void UpdateScene();
	void ChangeScene(int id);
	void UnloadScene(int id);
};

template<int SCENE_N>
inline void SceneManager<SCENE_N>::LoadScene(Scene* scene, int id)
{
	if(id < SCENE_N)
		m_loaded_scenes[id] = std::unique_ptr<Scene>(scene);
}

template<int SCENE_N>
inline void SceneManager<SCENE_N>::UpdateScene()
{
	m_loaded_scenes[m_current_scene]->Update();
	m_loaded_scenes[m_current_scene]->Render();
}

template<int SCENE_N>
inline void SceneManager<SCENE_N>::ChangeScene(int id)
{
	if (id < SCENE_N && m_loaded_scenes[id]) {
		m_loaded_scenes[m_current_scene]->Switch();

		m_current_scene = id;
		m_loaded_scenes[id]->Start();
	}
}

template<int SCENE_N>
inline void SceneManager<SCENE_N>::UnloadScene(int id)
{
	m_loaded_scenes[id].reset();
}
