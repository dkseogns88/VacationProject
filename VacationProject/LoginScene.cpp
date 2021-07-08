#include "LoginScene.h"
#include "login.h"
#include "framework.h"
#include "CharacterScene.h"


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
	
		switch (scene_event.type)
		{
		

		case Event::KeyPressed: 
		{
			switch (scene_event.key.code)
			{

			case Keyboard::A:
			{
				scenes->push(new CharacterScene(scenes, window));
				cout << "now Character Scene";
				break;
			}

			}
		}
		}
	
	
	
}

void LoginScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void LoginScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}

