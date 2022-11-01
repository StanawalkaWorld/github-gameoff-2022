#pragma once

class Scene {
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Switch() = 0;
};