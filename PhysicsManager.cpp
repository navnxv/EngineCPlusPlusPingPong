#include "PhysicsManager.h"
#include "PhysicsComponent.h"


// Initializing the static variable
PhysicsManager* PhysicsManager::s_PhysicsManagerInstance = nullptr;
//std::vector<PhysicsComponent*> PhysicsManager::sAllPhysicsComponents;

PhysicsManager* PhysicsManager::GetInstance() 
{
	if (s_PhysicsManagerInstance == nullptr)
	{
		s_PhysicsManagerInstance = new PhysicsManager();
	}
	return s_PhysicsManagerInstance;
}

PhysicsManager::PhysicsManager()
{
	m_AllPhysicsComponents.empty();
} 

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::AddPhysicsComponent(PhysicsComponent* component)
{
	m_AllPhysicsComponents.push_back(component);
}

void PhysicsManager::RemovePhysicsComponent(PhysicsComponent* componentToRemove)
{
}

std::vector<PhysicsComponent*> PhysicsManager::GetAllPhysicsComponent() const
{
	return m_AllPhysicsComponents;
}

void PhysicsManager::CalculatePhysics()
{
    for (int i = 0; i < m_AllPhysicsComponents.size(); i++)
    {
        PhysicsComponent* currentComponent = m_AllPhysicsComponents[i];

        for (int j = i + 1; j < m_AllPhysicsComponents.size(); j++)
        {
            PhysicsComponent* other = m_AllPhysicsComponents[j];
            if (currentComponent->IsColliding(other))
            {
                currentComponent->GetCollisionEventListener()(other->GetGameObject(), other->GetCollider()->IsTrigger());
                other->GetCollisionEventListener()(currentComponent->GetGameObject(), currentComponent->GetCollider()->IsTrigger());
            }
        }
    }
}

