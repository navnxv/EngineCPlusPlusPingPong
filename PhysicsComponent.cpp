#include "PhysicsComponent.h"
#include <cmath>





PhysicsComponent::PhysicsComponent(GameObject* owningGameObject, Colliders* collider, bool isCollissionEnabled, float mass , float velocity, float gravityScale ):Component(owningGameObject)
{
    m_isCollissionEnabled = isCollissionEnabled;
    m_gravityMultiplier = gravityScale;
    m_mass = mass;
    m_velocity = velocity;
    m_collider = collider;
}

void PhysicsComponent::Initialize()
{
    PHYSICS_MANAGER->AddPhysicsComponent(this);
}

void PhysicsComponent::Destroy()
{
} 

ComponentType PhysicsComponent::GetComponentType() const
{
    return ComponentType::Physics;
}

//void PhysicsComponent::Update(float deltaTime)
//{
//    if (m_isCollissionEnabled == true) 
//    {
//        for (PhysicsComponent* componentIter : PHYSICS_MANAGER->GetAllPhysicsComponent())
//        {
//            if (componentIter == this)
//            {
//                continue;
//            }
//
//            // TODO collision event
//            if (IsColliding(componentIter)) 
//            {
//                m_collisionEvent(componentIter->m_owningGameObject, m_);
//            }
//        }
//    }
//    Gravity();
//}


void PhysicsComponent::SetCollisionEventListener(CollisionEventDelegateType function)
{
    m_collisionEvent = function;
}


CollisionEventDelegateType PhysicsComponent::GetCollisionEventListener() const
{
    return m_collisionEvent;

}

Colliders* PhysicsComponent::GetCollider()
{
    return m_collider;
}

bool PhysicsComponent::IsColliding(PhysicsComponent* other) const
{ 
    return m_collider->IsColliding(other->GetCollider());
}


void PhysicsComponent::Gravity() 
{
    float gForce = m_mass * m_gravityMultiplier;
    m_velocity += gForce;

    exVector2 gravityForceVector = { m_owningGameObject->GetTransform().x, m_velocity*100 };

    m_owningGameObject->SetTransform(gravityForceVector);
}
