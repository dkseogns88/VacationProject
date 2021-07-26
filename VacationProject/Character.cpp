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
	Vertex vertice[5];
	setPosition(Vector2f(400.f, 370.f));
	setScale(Vector2f(0.6f, 0.6f));
	Sprite sp;
	sp.setPosition(400.f, 370.f);
	sp.setTexture(*tx);
	sp.setOrigin(sp.getGlobalBounds().width / 2.f, sp.getGlobalBounds().height / 2.f);
	vertice[0] = Vertex(Vector2f(sp.getGlobalBounds().left, sp.getGlobalBounds().top), Color::Black);
	vertice[1] = Vertex(Vector2f(sp.getGlobalBounds().left + sp.getGlobalBounds().width, sp.getGlobalBounds().top), Color::Black);
	vertice[2] = Vertex(Vector2f(sp.getGlobalBounds().left + sp.getGlobalBounds().width, sp.getGlobalBounds().top + sp.getGlobalBounds().height), Color::Black);
	vertice[3] = Vertex(Vector2f(sp.getGlobalBounds().left, sp.getGlobalBounds().top + sp.getGlobalBounds().height), Color::Black);
	vertice[4] = vertice[0];
	cout << sp.getGlobalBounds().width << "/" << sp.getGlobalBounds().height << endl;
	
}

void Character::MoveUpdate()
{
	if (position.y < 370.f)
	{
		velocity.y += gravity;
		if (position.y < 200.f)
		{
			position.y = 370.f;
		}
	}
	else if (position.y > 370.f)
	{
		position.y = 370.f;
	}
	
	velocity += acceleration;
	position += velocity;
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::Update(const float& deltaTime)
{
	
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		velocity.y = -2.1;
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		velocity.x = -0.05f;
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		velocity.x = +0.05f;
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		velocity.x = 0.f;
	}
	MoveUpdate();
	setPosition(position);
	
	AnimationObject::Update(deltaTime);
}
