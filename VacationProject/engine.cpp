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
	//���� window������ �����ͷ� ����
	this->window = new RenderWindow(VideoMode(500, 500), "Window");// ������������
	//window.set���ñ� ��� ��Ȱ���Ұ�
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
	
		case Event::KeyPressed: //Ű�����Է½� �ѹ����Է�������
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

		if (Keyboard::isKeyPressed(Keyboard::Escape)) //Ű�����Է½� �������� �Է������� �����ð�����
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
	if (!scenes.empty()) //���� �������������
	{
		scenes.top()->Update(deltaTime);

		if (this->scenes.top()->GetQuit())
		{
			//���� �������� �� ����
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
		if (!scenes.empty()) //���� �������������
		{
			scenes.top()->Render(window);
		}
		window->display();
	}
}
