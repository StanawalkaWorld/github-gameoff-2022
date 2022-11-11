#pragma once
#include "EventEmitter.hpp"

class Scene {
public:
	EventEmitter<int> sceneChangeEvent;

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Switch() = 0;
};