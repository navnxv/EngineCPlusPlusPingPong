#include "Transform.h"
#include <iostream>

Transform::Transform(GameObject* owingGameObject, exVector2 pos, exVector2 rot, exVector2 scale):Component(owingGameObject)
{
    std::cout << m_position.x;
    m_position = pos;
    m_rotation = rot;
    m_scale = scale;
}

Transform::~Transform()
{
}

exVector2 Transform::GetPosition() const
{
    return m_position;
}

exVector2 Transform::GetRotation() const
{
    return m_rotation;
}

exVector2 Transform::ScaleRotation() const
{
    return m_scale;
}

void Transform::Initialize()
{
}

void Transform::Destroy()
{
}

ComponentType Transform::GetComponentType() const
{
    return ComponentType::Transform;
}

void Transform::SetPosition(exVector2 force)
{
    m_position = force;
}
