#pragma once
#include "Engine/Public/EngineTypes.h"

class GameObject;


class Component
{
public:
	Component() = delete;
	~Component();
	
	//custom consructor initializaction.
	Component(GameObject* gameObject);

	//Abstraction, or abstract method that will be needed to be implemented in child classes.
	virtual ComponentType GetComponentType() const = 0;


	//every component needs an initialize method and a destroy method
	virtual void Initialize() = 0;
	virtual void Destroy() = 0;

	GameObject* GetGameObject();

protected:
	GameObject* m_owningGameObject;

};

