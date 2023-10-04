#include "PaddleRight.h"
#include "Engine/Public/EngineInterface.h"
#include "BoxCollider.h"
#include "PhysicsComponent.h"

PaddleRight::PaddleRight(exVector2 posTop, exVector2 posBottom, GameObject* owningGameObject) : RenderComponent(owningGameObject)
{
	m_PosTop = posTop;
	m_PosBottom = posBottom;
	BoxCollider* boxCollider = new BoxCollider(m_owningGameObject, false, m_PosBottom.x - m_PosTop.x, m_PosBottom.y - m_PosTop.y);
	PhysicsComponent* physicsComponent = new PhysicsComponent(m_owningGameObject, boxCollider, false);
	m_owningGameObject->AddComponent(physicsComponent);
	physicsComponent->GetCollisionEventListener();
	SetTransform(posTop, posBottom);
}

void PaddleRight::SetTransform(exVector2 positionTop, exVector2 positionBottom)
{
	m_PosTop = positionTop;
	m_PosBottom = positionBottom;
}

exVector2 PaddleRight::GetTransformTop()
{
	return m_PosTop;
}

exVector2 PaddleRight::GetTransformBottom()
{
	return m_PosBottom;
}

PaddleRight::~PaddleRight()
{
}

void PaddleRight::Initialize()
{
	RENDER_MANAGER->AddRenderComponent(this);
}

void PaddleRight::OnHit(GameObject* hitGameObject)
{
}

void PaddleRight::OnMove(GameObject* moveGameObject)
{
}

void PaddleRight::Render(exEngineInterface* renderInterface)
{
	renderInterface->DrawBox(m_PosTop, m_PosBottom, { 255, 0, 0, 255 }, 1);

}