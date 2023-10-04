#include "GameObject.h"
#include "Component.h"


GameObject::GameObject()
{
	m_transform = { 0.0f, 0.0f };
}

GameObject::~GameObject()
{
	for (Component* ComponentIterator : m_componentList)
	{
		ComponentIterator->Destroy();
	}
}

void GameObject::Initialize()
{
	for (Component* ComponentIterator : m_componentList)
	{
		ComponentIterator->Initialize();
	}
}

void GameObject::AddComponent(Component* componentToAdd)
{
	m_componentList.push_back(componentToAdd);
}

void GameObject::Update()
{
}

exVector2 GameObject::GetTransform()
{
	return m_transform;
}

void GameObject::SetTransform(exVector2 position)
{
	m_transform = position;
}


template <typename T>
T* GameObject::FindComponent(ComponentType eType)
{
	for (Component* ComponentIterator : m_componentList)
	{
		if (ComponentIterator->GetComponentType() == eType);
		{
			//this will make sure if the component is found, return the correct type
			return (T*)ComponentIterator;
		}
	}
	return nullptr;
}

void GameObject::SetActive(unsigned int newState)
{
}