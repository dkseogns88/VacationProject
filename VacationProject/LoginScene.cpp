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
}

void LoginScene::Update(const float& deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		scenes->push(new CharacterScene(scenes,window));
	}
	Scene::Update(deltaTime);
}

void LoginScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}

