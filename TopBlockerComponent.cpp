#include "TopBlockerComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "BoxCollider.h"
#include "PhysicsComponent.h"

TopBlockerComponent::TopBlockerComponent(GameObject* owningGameObject) : RenderComponent(owningGameObject)
{
	BoxCollider* boxCollider = new BoxCollider(m_owningGameObject, false, 0.0f - 0.0f, 800.0f - 30.0f);
	PhysicsComponent* physicsComponent = new PhysicsComponent(m_owningGameObject, boxCollider, false);
	physicsComponent->GetCollisionEventListener();
	m_owningGameObject->AddComponent(physicsComponent);
}

TopBlockerComponent::~TopBlockerComponent()
{
}

void TopBlockerComponent::Initialize()
{
	RENDER_MANAGER->AddRenderComponent(this);
}

void TopBlockerComponent::OnHit(GameObject* hitGameObject)
{
}

void TopBlockerComponent::OnMove(GameObject* moveGameObject)
{
}

void TopBlockerComponent::Render(exEngineInterface* renderInterface)
{
	renderInterface->DrawBox({ 0.0f, 0.0f }, { 800.0f, 30.0f }, { 255, 255, 255, 255 }, 1);
}