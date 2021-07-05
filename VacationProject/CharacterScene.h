#pragma once
#include "framework.h"
#include "Scene.h"

class CharacterScene :
	public Scene
{
public:
	CharacterScene();
	CharacterScene(stack<Scene*>* scenes);
	virtual ~CharacterScene();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

