#pragma once

class BoxCollider;
class CircleCollider;

class Colliders
{
public:
	Colliders() = delete;
	~Colliders();
	Colliders(bool trigger);
	
	virtual bool IsColliding(Colliders* other) = 0;

	BoxCollider* GetColliderBox(Colliders* other);
	CircleCollider* GetColliderCircle(Colliders* other);

	bool IsTrigger() const;

private:
	bool m_trigger;

protected:
	bool CheckCollision(BoxCollider* BoxCollider, CircleCollider* otherCircleCollider);
	bool CheckCollision(CircleCollider* circleCollider, CircleCollider* otherCircleCollider);
	bool CheckCollision(BoxCollider* boxCollider, BoxCollider* otherBoxCollider);
};

