#pragma once
#include "Component.h"
#include <functional>
#include "PhysicsManager.h"
#include "GameObject.h"
#include "Colliders.h"


// Event signature
using CollisionEventDelegateType = std::function<void(GameObject* other , bool IsTrigger) > ;

class PhysicsComponent : public Component
{
public:
	PhysicsComponent() = delete;
	PhysicsComponent(GameObject* owningGameObject, Colliders* collider, bool isCollissionEnabled = false, float gravityScale = 1.0f, float mass = 1.0f, float velocity= 1.0f );
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentType GetComponentType() const override;

	CollisionEventDelegateType GetCollisionEventListener() const;

	Colliders* GetCollider();

	bool IsColliding(PhysicsComponent* other) const ;
	void Gravity();
	void SetCollisionEventListener(CollisionEventDelegateType function);



private:
	
	CollisionEventDelegateType m_collisionEvent;
	float m_gravityMultiplier;
	float m_mass;
	float m_velocity;
	unsigned int m_isCollissionEnabled : 1; // Use for optimization bool
	Colliders* m_collider;

};

