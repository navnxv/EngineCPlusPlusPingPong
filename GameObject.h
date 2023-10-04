#pragma once
#include "Engine/Public/EngineTypes.h"
#include <vector>
#include "RenderManager.h"
#include "Transform.h"

class Component;

class GameObject
{
public:
	GameObject();
	~GameObject();
	virtual void Initialize();


	void AddComponent(Component* componentToAdd);

	//TODO remove component

	template <typename T>
	T* FindComponent(ComponentType eType);

	virtual void Update();

	exVector2 GetTransform();
	void SetTransform(exVector2 position);
	void SetActive(unsigned int newState);

private:
	//stores all the components for the current Game Object
	std::vector<Component*> m_componentList;
	exVector2 m_transform;

};


