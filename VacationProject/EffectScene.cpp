#include "framework.h"
#include "EffectScene.h"
#include "attackeffect.h"
EffectScene::EffectScene()
{
	Init();
}

EffectScene::EffectScene(stack<Scene*>* scenes, RenderWindow* window, SoundEffect* soundEffect) :Scene(scenes, window,soundEffect)
{
	Init();
}

EffectScene::~EffectScene()
{

}

void EffectScene::Init()
{
	vObjects.push_back(new attackeffect);
}

void EffectScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void EffectScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
