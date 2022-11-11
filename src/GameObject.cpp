#include "GameObject.hpp"

GameObject::GameObject() {}
GameObject::GameObject(GameObject* parent) : m_parent(parent) {}

void GameObject::Update()
{
	for (auto& child : m_children) {
		child->Update();
	}
}

void GameObject::Render()
{
	for (auto& child : m_children) {
		child->Render();
	}
}
