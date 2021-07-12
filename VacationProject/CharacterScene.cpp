#include "CharacterScene.h"
#include "Character.h"

CharacterScene::CharacterScene()
{
	Init();
}

CharacterScene::CharacterScene(stack<Scene*>* scenes, RenderWindow* window, SoundEffect* soundEffect) :Scene(scenes, window,soundEffect)
{
	Init();
}

CharacterScene::~CharacterScene()
{
}

void CharacterScene::Init()
{
	vObjects.push_back(new Character);
}

void CharacterScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void CharacterScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
