#include "framework.h"
#include "Stage1Map.h"
Stage1Map::Stage1Map()
{
	Init();
}

Stage1Map::~Stage1Map()
{
}

void Stage1Map::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for (int i = 1; i < 2; ++i)
	{
		sprintf(filePath, "Texture/map/blockmapex0%d.png", i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

	this->setOrigin(tx->getSize().x / 4.f, tx->getSize().y / 4.f);
	setScale(Vector2f(0.5, 0.5));
	setPosition(Vector2f(0.f, 320.f));


}

void Stage1Map::Destroy()
{
	Effect::Destroy();
}
void Stage1Map::Update(const float& deltaTime)
{
	Effect::Update(deltaTime);
}