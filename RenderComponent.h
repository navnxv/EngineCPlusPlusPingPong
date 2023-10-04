#pragma once
#include <vector>
#include "Engine/Public/EngineTypes.h"
#include "Component.h"


class exEngineInterface;

class RenderComponent : public Component
{
public:
	RenderComponent() = delete;
	RenderComponent(GameObject* owningGameObject);

	virtual void Render(exEngineInterface* engine) = 0;

	ComponentType GetComponentType() const override;
	void Initialize() override;
	void Destroy() override;

	void Update(float deltaTime);
	static std::vector<RenderComponent*> mAllRenderingComponents;

protected:
	exColor m_Color;
};

