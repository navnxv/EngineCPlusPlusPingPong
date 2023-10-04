#include "Colliders.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "GameObject.h"


Colliders::~Colliders()
{
}

Colliders::Colliders(bool trigger)
{
    m_trigger = trigger;
}

bool Colliders::CheckCollision(CircleCollider* circleCollider, CircleCollider* otherCircleCollider)
{             
    exVector2 position1 = circleCollider->GetGameObject()->GetTransform();
    exVector2 position2 = otherCircleCollider->GetGameObject()->GetTransform();
    
    float disX = position1.x - position2.x;
    float disY = position1.y - position2.y;
    float distance = sqrt((disX * disX) + (disY * disY));
    
    if (distance <= circleCollider->GetRadius() + otherCircleCollider->GetRadius())
    {
        return true;
    }
    return false;
}


bool Colliders::CheckCollision(BoxCollider* boxCollider, CircleCollider* circleCollider)
{
    exVector2 positionBox = boxCollider->GetGameObject()->GetTransform();
    exVector2 positionCircle = circleCollider->GetGameObject()->GetTransform();
    
    float tempX = circleCollider->GetRadius();
    float tempY = circleCollider->GetRadius();
    
    
    if (positionCircle.x < positionBox.x)
    {
        tempX = positionBox.x;
    }
    else if (positionCircle.x > positionBox.x + boxCollider->GetWidth())
    {
        tempX = positionBox.x + boxCollider->GetWidth();
    }
    
    if (positionCircle.y < positionBox.y)
    {
        tempY = positionBox.y;
    }
    else if (positionCircle.y > positionBox.y + boxCollider->GetHeight())
    {
        tempY = positionBox.y + boxCollider->GetHeight();
    }
    
    float disX = positionCircle.x - tempX;
    float disY = positionCircle.y - tempY;
    float distance = sqrt((disX * disY) + (disY * disY));

    if (distance <= circleCollider->GetRadius())
    {
        return true;
    }
    
    return false;
}

bool Colliders::CheckCollision(BoxCollider* boxCollider, BoxCollider* otherBoxCollider)
{
    exVector2 position = boxCollider->GetGameObject()->GetTransform();
    exVector2 otherPosition = otherBoxCollider->GetGameObject()->GetTransform();
    
    if ((position.x + boxCollider->GetWidth() >= otherPosition.x) &&
        (position.x <= otherPosition.x + otherBoxCollider->GetWidth()) &&
        (position.y + boxCollider->GetHeight() >= otherPosition.y) &&
        (position.y <= otherPosition.y + otherBoxCollider->GetHeight()))
    {
        return true;
    }
    return false;
}

BoxCollider* Colliders::GetColliderBox(Colliders* other)
{
    if (dynamic_cast<BoxCollider*>(other) != nullptr)
    {
        return dynamic_cast<BoxCollider*>(other);
    }
}

CircleCollider* Colliders::GetColliderCircle(Colliders* other)
{
    if (dynamic_cast<CircleCollider*>(other) != nullptr)
    {
        return dynamic_cast<CircleCollider*>(other);
    }
    return nullptr;
}

bool Colliders::IsTrigger() const
{
    return m_trigger;
}




