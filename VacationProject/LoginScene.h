#pragma once
#include "Scene.h"

class Button;

class LoginScene : public Scene
	

{
public:
	LoginScene();
	LoginScene(stack<Scene*>* scenes, RenderWindow* window, SoundEffect* soundEffect);
	virtual ~LoginScene();

private:
	virtual void Init();
	Event scene_event;
	map<string, Button*> bts;

public:
	virtual void Update(const float& deltaTime,const Vector2f& mousePosition, stack<Scene*>* scenes, RenderWindow* window, SoundEffect* soundEffect);
	virtual void Render(RenderWindow* window);
	
};


