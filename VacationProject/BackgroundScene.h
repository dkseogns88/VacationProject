#pragma once
#include "Scene.h"

class BackgroundScene : public Scene

{
public:
	BackgroundScene();
	BackgroundScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~BackgroundScene();

private:
	virtual void Init();
	Event evt;

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};
