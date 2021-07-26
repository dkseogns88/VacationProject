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
	Vertex vertice[5];

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
	Sprite sp;
	sp.setPosition(0.f, 320.f);
	sp.setTexture(*tx);
	sp.setOrigin(sp.getGlobalBounds().width / 4.f, sp.getGlobalBounds().height / 4.f);
	/*맵을 오브젝트화 시켜서 캐릭터랑 충돌체크 할것*/

	vertice[0] = Vertex(Vector2f(sp.getGlobalBounds().left,sp.getGlobalBounds().top), Color::Black);
	vertice[1] = Vertex(Vector2f(sp.getGlobalBounds().left + sp.getGlobalBounds().width,sp.getGlobalBounds().top), Color::Black);
	vertice[2] = Vertex(Vector2f(sp.getGlobalBounds().left + sp.getGlobalBounds().width,sp.getGlobalBounds().top +sp.getGlobalBounds().height), Color::Black);
	vertice[3] = Vertex(Vector2f(sp.getGlobalBounds().left,sp.getGlobalBounds().top + sp.getGlobalBounds().height), Color::Black);
	vertice[4] = vertice[0];
	cout << sp.getGlobalBounds().width << "/" << sp.getGlobalBounds().height << endl;
	
	
	
}

void Stage1Map::Destroy()
{
	Effect::Destroy();
}
void Stage1Map::Update(const float& deltaTime)
{
	
	
	Effect::Update(deltaTime);
}