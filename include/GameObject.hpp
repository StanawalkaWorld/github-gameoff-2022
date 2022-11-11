#pragma once
#include <raylib.h>
#include <vector>
#include <memory>

class GameObject {
protected:
	using ChildrenCollection = std::vector<std::unique_ptr<GameObject>>;
	ChildrenCollection m_children;

	GameObject* m_parent = nullptr;
public:
	GameObject();
	GameObject(GameObject* parent);

	virtual void Update();
	virtual void Render();

	template <typename T, typename ...Args>
	void AddChild(Args ...args);
};

template<typename T, typename ...Args>
inline void GameObject::AddChild(Args ...args)
{
	m_children.push_back(std::make_unique<T>(this, std::forward(args)));
}
