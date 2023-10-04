#include "Box.h"

Box::Box(GameObject* owningComponent, exVector2 dimensions, exVector2 secondDimension): RenderComponent(owningComponent)
{
	m_secondDimensions = secondDimension;
	m_dimensions = dimensions;
}

Box::~Box()
{
}

ComponentType Box::GetComponentType() const
{
	return ComponentType::BoxShape;
}

void Box::Render(exEngineInterface* renderInterface)
{
	renderInterface->DrawBox(m_dimensions, m_secondDimensions, m_Color, 1);
}

float Box::GetWidth()
{
	return m_secondDimensions.x - m_dimensions.x;
}

float Box::GetHeight()
{
	return m_secondDimensions.y - m_dimensions.y;
}

