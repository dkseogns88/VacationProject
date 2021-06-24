#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<vector>
#include<iostream>
using namespace sf;
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "WINDOW");
	window.setFramerateLimit(60);
	
	vector<Texture> txvector;

	Texture tx;
	char name[50];

	for (int i = 32; i < 36; ++i)
	{
		sprintf(name, "Texture/cookie0020x2/cookie0020x2_00%d.png", i);
		tx.loadFromFile(name);
		txvector.push_back(tx); //������� ����Ʈ�ȿ� �ڷḦ ����־���
	}
	Sprite sp;

	Clock clock;
	size_t keyFrameTime = 0;

	while (window.isOpen())//�����찡 ���µǾ�������
	{
		window.clear();
		
		Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
			{
				window.close(); //������ ����
				break;
			}
			default:
				break;
			}
		}
		
		if (clock.getElapsedTime().asSeconds() > 0.2f)
		{
			
			sp.setTexture(txvector.data()[++keyFrameTime % txvector.size()]);

			keyFrameTime++;
			clock.restart();
		}
		window.draw(sp);
		window.display(); //�׸�������� ȭ��������� 
	}
}