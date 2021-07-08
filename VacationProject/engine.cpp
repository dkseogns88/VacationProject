#include "framework.h"
#include "engine.h"
#include "EffectScene.h"
#include "CharacterScene.h"
#include "LoginScene.h"
Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
}

void Engine::Init()
{
	//현재 window변수는 포인터로 존재
	this->window = new RenderWindow(VideoMode(500, 500), "Window");// 엔진의윈도우
	//window.set뭐시기 기능 잘활용할것
	window->setMouseCursorVisible(true);
	Image icon;
	icon.loadFromFile("Texture/icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	this->scenes.push(new LoginScene(&scenes,window));
	
	
}

void Engine::Destroy()
{
	if (window)
	{
		delete window;
	}
	
}



void Engine::Input()
{
	
	while (window->pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}
	
		case Event::KeyPressed: //키보드입력시 한번만입력을받음
		{
			switch (evt.key.code)
			{
		
			case Keyboard::Escape:
			{
				scenes.top()->EndScene();
				break;
			}
			}
		default:
			break;
		}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) //키보드입력시 지속적인 입력을받음 누른시간동안
		{
			window->close();
		}
		else
		{
			window->setTitle("game");
		}

	}
}

void Engine::Update()
{
	deltaTime = timer.getElapsedTime().asSeconds();
	timer.restart();
	Input();
	if (!scenes.empty()) //씬이 비어있지않을때
	{
		scenes.top()->Update(deltaTime);

		if (this->scenes.top()->GetQuit())
		{
			//현재 실행중인 씬 종료
			delete this->scenes.top();
			this->scenes.pop();
			cout << "Pop scene\n";
		}
	}
	else
	{

		this->scenes.push(new LoginScene(&scenes, window));
	}
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		if (!scenes.empty()) //씬이 비어있지않을때
		{
			scenes.top()->Render(window);
		}
		window->display();
	}
}
