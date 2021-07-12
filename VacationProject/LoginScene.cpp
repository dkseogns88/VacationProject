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

		
}

void LoginScene::Update(const float& deltaTime)
{
	while (window->pollEvent(scene_event))
	{
		switch (scene_event.type)
		{
		case Event::MouseButtonPressed: 
		{
			soundEffect->EffectPlay("Click");
			break;
		}
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		music.stop();
		scenes->push(new BackgroundScene(scenes,window,soundEffect));
	
		
	}
	
	Scene::Update(deltaTime);
}

void LoginScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}

