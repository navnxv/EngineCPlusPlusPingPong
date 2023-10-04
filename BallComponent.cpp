#include "BallComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "RenderComponent.h"
#include "RenderManager.h"
#include "CircleCollider.h"

BallComponent::BallComponent(GameObject* owningGameObject, exVector2 pos) : RenderComponent(owningGameObject)
{
	m_radius = 20.0f;
	m_Pos = pos;
	m_Color = { 0,255,0,255 };
	//CircleCollider* circleCollider = new CircleCollider(owningGameObject, false, m_radius);
	//PhysicsComponent* physicsComponent = new PhysicsComponent(owningGameObject, circleCollider, true);
	//physicsComponent->SetCollisionEventListener(std::bind(&BallComponent::OnCollision, this, std::placeholders::_1, std::placeholders::_2));
	//owningGameObject->AddComponent(physicsComponent);
	SetTransform(pos);
}

BallComponent::~BallComponent()
{
	delete this;
}

void BallComponent::Initialize()
{
	RENDER_MANAGER->AddRenderComponent(this);
}

void BallComponent::OnHit(GameObject* hitGameObject)
{
}

void BallComponent::OnMove(GameObject* moveGameObject)
{

}
void BallComponent::Render(exEngineInterface* renderInterface)
{
	renderInterface->DrawCircle(m_Pos, m_radius, m_Color, 1);
}

float BallComponent::GetRadius()
{
	return m_radius;
}

exVector2 BallComponent::GetTranform()
{
	return m_Pos;
}

void BallComponent::SetTransform(exVector2 pos)
{
	m_Pos = pos;
}

void BallComponent::ChangeColor()
{
	m_Color = { 0,0,0,255 };
}

void BallComponent::OnCollision(GameObject* other, bool isTrigger)
{
	ChangeColor();
}