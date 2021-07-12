#include "LoginScene.h"
#include "login.h"
#include "framework.h"
#include "CharacterScene.h"
#include "EffectScene.h"
#include "BackgroundScene.h"

sf::Music music;

LoginScene::LoginScene()
{
	Init();
}

LoginScene::LoginScene(stack<Scene*>* scenes, RenderWindow* window):Scene(scenes,window)
{
	Init();
}

LoginScene::~LoginScene()
{

}

void LoginScene::Init()
{
		vObjects.push_back(new login);
		if (music.openFromFile("Sound/login.wav"))
		{
			music.play();
			
		}
}

void LoginScene::Update(const float& deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		music.stop();
		scenes->push(new BackgroundScene(scenes,window));
	
		
	}
	Scene::Update(deltaTime);
}

void LoginScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}

