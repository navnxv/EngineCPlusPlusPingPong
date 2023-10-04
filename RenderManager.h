#pragma once
#include <vector>
#include "Engine/Public/EngineInterface.h"

#define RENDER_MANAGER RenderManager::GetInstance()

class RenderComponent;

class RenderManager
{
public:
	static RenderManager* GetInstance();
	~RenderManager();

	void Update(float deltaTime);
	void AddRenderComponent(RenderComponent* component);
	void RemoveRenderComponent(RenderComponent* component);
	std::vector<RenderComponent*> GetAllRenderComponents() const;
	void RenderObjects(exEngineInterface* engine);

private:
	RenderManager();
	std::vector<RenderComponent*> m_allRenderComponents;
	static RenderManager* s_RenderManagerInstance;
};


