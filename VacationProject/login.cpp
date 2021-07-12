#include "framework.h"
#include "login.h"


login::login()
{
	Init();
}

login::~login()
{
}

void login::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for(int i=1;i<3;++i)
	{
		sprintf(filePath, "Texture/login/login0%d.png",i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}
	
	this->setOrigin(tx->getSize().x/4.f , tx->getSize().y/4.f);
	setPosition(Vector2f(90.f, 120.f));
	setScale(Vector2f(1.0, 1.2));

}

void login::Destroy()
{
	Effect::Destroy();
}
void login::Update(const float& deltaTime)
{
	Effect::Update(deltaTime);
}