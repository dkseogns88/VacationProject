#include "BackgroundScene.h"
#include "Stage1.h"
#include "Character.h"
sf::Music backmusic;
BackgroundScene::BackgroundScene()
{
	Init();
}

BackgroundScene::BackgroundScene(stack<Scene*>* scenes, RenderWindow* window)
{
	Init();
}

BackgroundScene::~BackgroundScene()
{
}

void BackgroundScene::Init()
{
    vObjects.push_back(new Stage1);
	if (backmusic.openFromFile("Sound/henesys.wav"))
	{
		backmusic.play();
	}
}

void BackgroundScene::Update(const float& deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		vObjects.push_back(new Character);
	}
	
	
	Scene::Update(deltaTime);
}

void BackgroundScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
