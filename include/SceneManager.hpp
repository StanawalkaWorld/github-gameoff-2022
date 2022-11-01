#pragma once
#include <array>
#include <memory>

#include "Scene.hpp"

template <int SCENE_N>
class SceneManager {
private:
	using SceneCollection = std::array<std::unique_ptr<Scene>, SCENE_N>;

	SceneCollection loaded_scenes;
};