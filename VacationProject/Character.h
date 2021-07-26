#pragma once
#include "AnimationObject.h"
class Character : public AnimationObject
{
public:
	Character();
	virtual ~Character();

private:

	virtual void Init();
	RenderWindow window;

	Vector2f position{ 400.f,370.f };
	Vector2f velocity{ 0.f,0.f };
	Vector2f acceleration{ 0.f,0.f };
	float gravity = 2.f;
public:

	virtual void MoveUpdate();
	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};

