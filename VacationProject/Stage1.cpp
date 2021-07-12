#include "framework.h"
#include "Stage1.h"
Stage1::Stage1()
{
	Init();
}

Stage1::~Stage1()
{
}

void Stage1::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for (int i = 1; i < 2; ++i)
	{
		sprintf(filePath, "Texture/background/henesys back0%d.png", i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

	this->setOrigin(tx->getSize().x / 20.f, tx->getSize().y /20.f);
	setScale(Vector2f(1.9, 3.0));
	setPosition(Vector2f(0.f, 0.f));


}

void Stage1::Destroy()
{
	Effect::Destroy();
}
void Stage1::Update(const float& deltaTime)
{
	Effect::Update(deltaTime);
}