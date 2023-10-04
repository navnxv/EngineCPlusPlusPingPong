#include "Component.h"

Component::~Component()
{
}

Component::Component(GameObject* gameObject)
{
    m_owningGameObject = gameObject;
}

GameObject* Component::GetGameObject()
{
    return m_owningGameObject;
}


