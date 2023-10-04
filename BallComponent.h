#pragma once
#include "GameObject.h"
#include "RenderComponent.h"
#include "RenderManager.h"
#include "PhysicsComponent.h"


class BallComponent : public RenderComponent
{
public:
	BallComponent() = delete;
	BallComponent(GameObject* owningGameObject, exVector2 pos);
	~BallComponent();

	void Initialize() override;

	void OnHit(GameObject* hitGameObject);
	void OnMove(GameObject* moveGameObject);
	virtual void Render(exEngineInterface* renderInterface) override;
	float GetRadius();
	exVector2 GetTranform();
	void SetTransform(exVector2 pos) ;
	void Collide();

	void ChangeColor();
protected:
	float m_radius;
	exVector2 m_Pos;
	GameObject* m_owning;
	void OnCollision(GameObject* other, bool isTrigger);
};

