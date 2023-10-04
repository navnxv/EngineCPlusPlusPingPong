#pragma once
#include "GameObject.h"
#include "RenderComponent.h"
#include "RenderManager.h"


class BottomBlockerComponent : public RenderComponent
{
public:
	BottomBlockerComponent() = delete;
	BottomBlockerComponent(GameObject* owningGameObject);
	~BottomBlockerComponent();

	void Initialize() override;

	void OnHit(GameObject* hitGameObject);
	void OnMove(GameObject* moveGameObject);
	virtual void Render(exEngineInterface* renderInterface) override;

};

