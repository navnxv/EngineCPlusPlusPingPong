#include "RenderComponent.h"
#include "RenderManager.h"
#include "Engine/Public/EngineInterface.h"
#include "GameObject.h"

//allows static linking for the members
std::vector<RenderComponent*>RenderComponent::mAllRenderingComponents;

RenderComponent::RenderComponent(GameObject* owningGameObject):Component(owningGameObject)
{
	m_Color = { 150,150,150,255 };
}

//void RenderComponent::Render(exEngineInterface* engine)
//{
//	engine->DrawBox({ 250,250 }, { 500,500 }, mColor, 1);
//}

ComponentType RenderComponent::GetComponentType() const
{
	return ComponentType::Rendering;
}

void RenderComponent::Initialize()
{
	//mAllRenderingComponents.push_back(this);
	RENDER_MANAGER->AddRenderComponent(this);
}

void RenderComponent::Destroy()
{
}

void RenderComponent::Update(float deltaTime)
{
	//GameObject::Update();

}
