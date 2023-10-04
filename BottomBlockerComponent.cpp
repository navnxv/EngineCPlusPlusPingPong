#include "BottomBlockerComponent.h"
#include "Engine/Public/EngineInterface.h"


BottomBlockerComponent::BottomBlockerComponent(GameObject* owningGameObject) : RenderComponent(owningGameObject)
{
}

BottomBlockerComponent::~BottomBlockerComponent()
{
}

void BottomBlockerComponent::Initialize()
{
	RENDER_MANAGER->AddRenderComponent(this);
}

void BottomBlockerComponent::OnHit(GameObject* hitGameObject)
{
}

void BottomBlockerComponent::OnMove(GameObject* moveGameObject)
{
}

void BottomBlockerComponent::Render(exEngineInterface* renderInterface)
{
	renderInterface->DrawBox({ 0.0f, 550.0f }, { 800.0f, 770.0f }, { 255, 255, 255, 255 }, 1);
}