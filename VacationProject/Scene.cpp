#include "framework.h"
#include "Scene.h"
#include "Object.h"
#include "Character.h"
#include "login.h"
Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scenes,RenderWindow* window)
	:scenes(scenes)
{
	Init();
}
Scene::~Scene()
{
}

void Scene::Init()
{
	vObjects.push_back(new login);
	
}
bool Scene::GetQuit() const
{
	return quit;
}

void Scene::EndScene()
{
	quit = true;
}

void Scene::Update(const float& deltaTime)
{
	
	for (auto& obj : vObjects)
	{
		obj->Update(deltaTime);
	}
}

void Scene::Render(RenderWindow* window)
{
	for (auto& obj : vObjects)
	{
		window->draw(*obj);
	}
}
