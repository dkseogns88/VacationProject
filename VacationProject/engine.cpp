#include "framework.h"
#include "engine.h"
#include "EffectScene.h"
#include "CharacterScene.h"

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
	icon.loadFromFile("Texture/OW.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	this->scenes.push(new Scene);

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
		/*
			case Event::MouseButtonPressed:
			{
				window->setTitle("Click");
				break;
			}
		*/
		case Event::KeyPressed: //Ű�����Է½� �ѹ����Է�������
		{
			switch (evt.key.code)
			{
			case Keyboard::A:
			{
				cout << "butten A\n";
				break;
			}
			case Keyboard::S:
			{
				this->scenes.push(new EffectScene);
				cout << "now scene:effectScene";
				break;

			}
			case Keyboard::Q:
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


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			window->setTitle("Left clock");
		}
		if (Mouse::isButtonPressed(Mouse::Right))
		{
			window->setTitle("Right clock");
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
		window->close();
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
