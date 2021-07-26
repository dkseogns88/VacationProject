#include "LoginScene.h"
#include "login.h"
#include "framework.h"
#include "CharacterScene.h"
#include "EffectScene.h"
#include "BackgroundScene.h"
#include "Button.h"
sf::Music music;

LoginScene::LoginScene()
{
	Init();
}

LoginScene::LoginScene(stack<Scene*>* scenes, RenderWindow* window, SoundEffect* soundEffect):Scene(scenes,window,soundEffect)
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
		bts["Button!"] = new Button("Texture/login/loginbutton2.png", "Texture/login/loginbutton2.png", { 450.f,350.f });
		
		
}

void LoginScene::Update(const float& deltaTime,const Vector2f& mousePosition, stack<Scene*>* scenes, RenderWindow* window, SoundEffect* soundEffect)
{
	for (auto& b1 : bts)
	{
		b1.second->Update(mousePosition,scenes,window,soundEffect);
	}

	
	
	Scene::Update(deltaTime);
}

void LoginScene::Render(RenderWindow* window)
{

	Scene::Render(window);
	for (auto& b1 : bts)
	{
		b1.second->Render(window);
	}

	
	
}

