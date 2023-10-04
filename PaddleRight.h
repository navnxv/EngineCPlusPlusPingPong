#pragma once
#include "GameObject.h"
#include "RenderComponent.h"
#include "RenderManager.h"

class PaddleRight : public RenderComponent
{
public:
	PaddleRight() = delete;
	PaddleRight(exVector2 posTop, exVector2 posBottom, GameObject* owningGameObject);
	~PaddleRight();

	void Initialize() override;

	void OnHit(GameObject* hitGameObject);
	void OnMove(GameObject* moveGameObject);
	virtual void Render(exEngineInterface* renderInterface) override;
	exVector2 GetTransformTop();
	exVector2 GetTransformBottom();
	void SetTransform(exVector2 positionTop, exVector2 positionBottom);

private:
	exVector2 m_PosTop;
	exVector2 m_PosBottom;
	Transform* m_transform;

};

