#pragma once
#include "GameObject.h"
#include "RenderComponent.h"
#include "RenderManager.h"

class PaddleLeft : public RenderComponent
{
public: 
	PaddleLeft() = delete;
	PaddleLeft(exVector2 posTop, exVector2 posBottom, GameObject* owningGameObject);
	~PaddleLeft();

	void Initialize() override;
	void SetTransform(exVector2 positionTop, exVector2 positionBottom);

	void OnHit(GameObject* hitGameObject);
	void OnMove(GameObject* moveGameObject);
	virtual void Render(exEngineInterface* renderInterface) override;

	exVector2 GetTransformTop();
	exVector2 GetTransformBottom();

private:
	exVector2 m_PosTop;
	exVector2 m_PosBottom;
	Transform* m_transform;
	GameObject* m_owning;
	void OnCollision(GameObject* other, bool isTrigger);
};

