#pragma once
#include"Component.h"
#include "Colliders.h"
#include "CircleCollider.h"

class BoxCollider : public Component, public Colliders
{
public: 
	BoxCollider() = delete;
	BoxCollider(GameObject* gameObject, bool isTrigger, float width, float height);
	~BoxCollider();

	float GetWidth() const;
	float GetHeight() const;
	bool IsColliding(Colliders* other) override;

	virtual ComponentType GetComponentType() const override;

	  
	//every component needs an initialize method and a destroy method
	virtual void Initialize() override;
	virtual void Destroy() override;

private:
	float m_width;
	float m_height;

};

