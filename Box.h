#pragma once
#include "RenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "RenderManager.h"


class Box : public RenderComponent
{
public:
	Box() = delete;
	Box(GameObject* owningComponent, exVector2 dimensions, exVector2 secondDimesions);
	~Box();

	virtual ComponentType GetComponentType() const;
	virtual void Render(exEngineInterface* renderInterface) override;

	float GetWidth();
	float GetHeight();


private:
	exVector2 m_dimensions;
	exVector2 m_secondDimensions;
};

