#include "framework.h"
#include "engine.h"
#include "AnimationObject.h"

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

	AnimationObject* obj1 = new AnimationObject;
	obj.push_back(new AnimationObject);
	obj1->setPosition(100, 0);
	obj.push_back(obj1);
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
	//cout << deltaTime << endl;
	for (auto& o : obj)
	{
		o->Update(deltaTime);
	}
	timer.restart();
	Input();
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		for (auto& o : obj)
		{
			window->draw(*o);
		}
		window->display();
	}
}
