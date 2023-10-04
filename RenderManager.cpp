#include "RenderManager.h"
#include "RenderComponent.h"


RenderManager* RenderManager::s_RenderManagerInstance = nullptr;

RenderManager* RenderManager::GetInstance()
{
	if (s_RenderManagerInstance == nullptr)
	{
		s_RenderManagerInstance = new RenderManager();
	}
	return s_RenderManagerInstance;
}

RenderManager::~RenderManager()
{
}

void RenderManager::Update(float deltaTime)
{
	
}

void RenderManager::AddRenderComponent(RenderComponent* component)
{
	m_allRenderComponents.push_back(component);
}

void RenderManager::RemoveRenderComponent(RenderComponent* component)
{
}

std::vector<RenderComponent*> RenderManager::GetAllRenderComponents() const
{
    return m_allRenderComponents;
}

void RenderManager::RenderObjects(exEngineInterface* engine)
{
	for (RenderComponent* iter : GetAllRenderComponents()) 
	{
		iter->Render(engine);
	}
}

RenderManager::RenderManager() 
{
	m_allRenderComponents.empty();
}


