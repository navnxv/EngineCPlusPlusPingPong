#include"BoxCollider.h"
#include "GameObject.h"


BoxCollider::BoxCollider(GameObject* gameObject, bool isTrigger, float width, float height) : Component(gameObject), Colliders(isTrigger)
{
	m_height = height;
	m_width = width;
}

BoxCollider::~BoxCollider()
{
}

float BoxCollider::GetWidth() const
{
	return m_width;
}

float BoxCollider::GetHeight() const
{
	return m_height;
}

bool BoxCollider::IsColliding(Colliders* other) 
{
	BoxCollider* otherBoxComponent = other->GetColliderBox(other);
	CircleCollider* otherCircleComponent = other->GetColliderCircle(other);

	if (otherCircleComponent != nullptr)
	{
		CheckCollision(this, otherBoxComponent);
	}
	else if (otherBoxComponent != nullptr)
	{
		CheckCollision(this, otherBoxComponent);
	}
	return false;
}

ComponentType BoxCollider::GetComponentType() const
{ 
	return ComponentType();
}

void BoxCollider::Initialize()
{
}

void BoxCollider::Destroy()
{
}

