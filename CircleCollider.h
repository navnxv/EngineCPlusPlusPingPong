#pragma once
#include "Component.h"
#include "Colliders.h"
#include "BoxCollider.h"

class CircleCollider : public Component, public Colliders
{
public:
	CircleCollider() = delete;
	CircleCollider(GameObject* gameObject, bool isTrigger, float radius);
	~CircleCollider();

	bool IsColliding(Colliders* other) override;
	float GetRadius();

	//Abstraction, or abstract method that will be needed to be implemented in child classes.
	virtual ComponentType GetComponentType() const override ;


	//every component needs an initialize method and a destroy method
	virtual void Initialize() override;
	virtual void Destroy() override;

private:
	float m_radius;


};

