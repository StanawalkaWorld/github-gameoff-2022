#pragma once
#include <array>
#include <memory>

#include "Scene.hpp"

class SceneManager {
private:
	using SceneCollection = std::array<std::unique_ptr<Scene>, 8>;
	SceneCollection m_loaded_scenes;

	int m_current_scene = 0;
	bool m_scene_change_requested = false;
public:
	void LoadScene(Scene* scene, int id);
	void UpdateScene();
	void ChangeScene(int id);
	void UnloadScene(int id);
};