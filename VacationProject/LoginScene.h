#pragma once
#include "Scene.h"


class LoginScene : public Scene
	

{
public:
	LoginScene();
	LoginScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~LoginScene();

private:
	virtual void Init();
	Event scene_event;

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
	
};


