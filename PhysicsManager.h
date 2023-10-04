#pragma once
#include <vector>


#define PHYSICS_MANAGER PhysicsManager::GetInstance()

class PhysicsComponent;

class PhysicsManager
{
public:
	static PhysicsManager* GetInstance();
	~PhysicsManager();

	void AddPhysicsComponent(PhysicsComponent* component);
	void RemovePhysicsComponent(PhysicsComponent* componentToRemove);
	std::vector<PhysicsComponent*> GetAllPhysicsComponent() const;

	void CalculatePhysics();


private:
	PhysicsManager();
	static PhysicsManager* s_PhysicsManagerInstance;

	std::vector<PhysicsComponent*> m_AllPhysicsComponents;

};

