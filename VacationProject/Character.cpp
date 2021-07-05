#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "Character.h"

Character::Character()
{
	Init();
}

Character::~Character()
{
}

void Character::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for (int i = 1; i < 7; ++i)
	{
		sprintf(filePath, "Texture/kingslime/move0%d.png", i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

	setPosition(Vector2f(100.f, 100.f));
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
}