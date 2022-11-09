#pragma once
#include <array>
#include <memory>

#include "Scene.hpp"

constexpr int SCENE_N = 8;

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