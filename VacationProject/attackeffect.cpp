#include "framework.h"
#include "attackeffect.h"

attackeffect::attackeffect()
{
	Init();
}

attackeffect::~attackeffect()
{
}

void attackeffect::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for (int i = 1; i < 7; ++i)
	{
	
	    sprintf(filePath, "Texture/slimeattack/attack0%d.png", i);
	
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

	this->setOrigin(tx->getSize().x / 2.f, tx->getSize().y / 2.f);
	setPosition(Vector2f(180.f, 250.f));
}

void attackeffect::Destroy()
{
	AnimationObject::Destroy();
}

void attackeffect::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
}
