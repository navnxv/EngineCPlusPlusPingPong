#pragma once
#include "Component.h"
#include "Engine/Public/EngineTypes.h"


class Transform : public Component
{
public: 
	Transform() = delete;
	Transform(GameObject* owingGameObject, exVector2 pos = {0.0f,0.0f}, exVector2 rot = {0.0f,0.0f}, exVector2 scale = { 0.0f,0.0f });
	~Transform();

	exVector2 GetPosition() const;
	exVector2 GetRotation() const;
	exVector2 ScaleRotation() const;

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentType GetComponentType() const;

	void SetPosition(exVector2 force);


private:
	exVector2 m_position;
	exVector2 m_rotation;
	exVector2 m_scale;
};

