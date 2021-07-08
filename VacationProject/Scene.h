#pragma once
#include "framework.h"
class Object;

class Scene
{

public:
	Scene();
	Scene(stack<Scene*>* scenes,RenderWindow* window);
	virtual ~Scene();

protected:


	vector<Object*> vObjects;
	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;
	bool quit = false;

	Vector2i mousePosition{ 0, 0 };

private:

	virtual void Init();

public:

	bool GetQuit() const;
	void EndScene();
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);

};
