#include "CircleCollider.h"



CircleCollider::CircleCollider(GameObject* gameObject, bool isTrigger, float radius):Component(gameObject), Colliders(isTrigger)
{
	m_radius = radius;
}

CircleCollider::~CircleCollider()
{
}

bool CircleCollider::IsColliding(Colliders* other) 
{
	BoxCollider* otherBoxComponent = other->GetColliderBox(other);
	CircleCollider* otherCircleComponent = other->GetColliderCircle(other);

	if (otherCircleComponent != nullptr)
	{
		return CheckCollision(this, otherCircleComponent);
	}
	else if (otherBoxComponent != nullptr)
	{
		return CheckCollision(otherBoxComponent, this);
	}
	return false;
}

float CircleCollider::GetRadius()
{
	return m_radius;
}

ComponentType CircleCollider::GetComponentType() const
{
	return ComponentType();
}



void CircleCollider::Initialize()
{
}

void CircleCollider::Destroy()
{
}
