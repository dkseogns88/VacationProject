#include "BackgroundScene.h"
#include "Stage1.h"
#include "Character.h"
#include "Stage1Map.h"
sf::Music backmusic;
BackgroundScene::BackgroundScene()
{
	Init();
}

BackgroundScene::BackgroundScene(stack<Scene*>* scenes, RenderWindow* window, SoundEffect* soundEffect)
{
	Init();
}

BackgroundScene::~BackgroundScene()
{
}

void BackgroundScene::Init()
{
	if (backmusic.openFromFile("Sound/henesys.wav"))
	{
		backmusic.play();
	}
	/*삭제했던 공격이펙트 추가하기*/
	vObjects.push_back(new Stage1);
	vObjects.push_back(new Character);
    
	
	vObjects.push_back(new Stage1Map);
	
	
}

void BackgroundScene::Update(const float& deltaTime)
{
	
	
	
	
	
	
	Scene::Update(deltaTime);
}

void BackgroundScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
