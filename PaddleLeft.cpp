#include "PaddleLeft.h"
#include "Engine/Public/EngineInterface.h"
#include "BoxCollider.h"
#include "PhysicsComponent.h"


PaddleLeft::PaddleLeft( exVector2 posTop, exVector2 posBottom, GameObject* owningGameObject): RenderComponent(owningGameObject)
{
	m_PosTop = posTop;
	m_PosBottom = posBottom;
	m_Color = { 255, 0, 0,255 };
	BoxCollider* boxCollider = new BoxCollider(m_owningGameObject, false, m_PosBottom.x - m_PosTop.x, m_PosBottom.y - m_PosTop.y);
	PhysicsComponent* physicsComponent = new PhysicsComponent(m_owningGameObject, boxCollider, false);
	//m_owningGameObject->AddComponent(physicsComponent);
	physicsComponent->GetCollisionEventListener();
	physicsComponent->SetCollisionEventListener(std::bind(&PaddleLeft::OnCollision, this, std::placeholders::_1, std::placeholders::_2));

	SetTransform(posTop, posBottom);
}

void PaddleLeft::SetTransform(exVector2 positionTop, exVector2 positionBottom)
{
	m_PosTop = positionTop;
	m_PosBottom = positionBottom;
}                     

exVector2 PaddleLeft::GetTransformTop() 
{
	return m_PosTop;
}

exVector2 PaddleLeft::GetTransformBottom()
{
	return m_PosBottom;
}

PaddleLeft::~PaddleLeft()
{
}

void PaddleLeft::Initialize()
{
	RENDER_MANAGER->AddRenderComponent(this);
}

void PaddleLeft::OnHit(GameObject* hitGameObject)
{
}

void PaddleLeft::OnMove(GameObject* moveGameObject)
{
}

void PaddleLeft::Render(exEngineInterface* renderInterface)
{
	renderInterface->DrawBox(m_PosTop, m_PosBottom, m_Color , 1);
}


void PaddleLeft::OnCollision(GameObject* other, bool isTrigger)
{
	m_Color = { 0,0,255,255 };
}

