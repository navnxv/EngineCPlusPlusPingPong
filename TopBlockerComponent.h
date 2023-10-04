#pragma once
#include "GameObject.h"
#include "RenderComponent.h"
#include "RenderManager.h"


class TopBlockerComponent : public RenderComponent
{
public:
	TopBlockerComponent() = delete;
	TopBlockerComponent(GameObject* owningGameObject);
	~TopBlockerComponent();

	void Initialize() override;

	void OnHit(GameObject* hitGameObject);
	void OnMove(GameObject* moveGameObject);
	virtual void Render(exEngineInterface* renderInterface) override;

};

