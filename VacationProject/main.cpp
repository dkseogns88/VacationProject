#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "WINDOW");
	window.setFramerateLimit(60);
	IntRect txsq(0,0,319/3,424/4); //�̹����� �ڸ�
	// 319 X 424 �̹����� ������ 
	Texture tx; // �̹����� �ҷ���
	tx.loadFromFile("Texture/dragonFrames.png");
	
	Sprite sp(tx,txsq); //Texture ���ҷ��ͼ� �������� ������
	sp.setScale(3.f, 3.f);

	Clock clock; //�ð�

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
		if (clock.getElapsedTime().asSeconds() >= 0.3f) //�����ϴٰ� 0.3�ʰ������� if������
		{
			if (txsq.left >= 212)
			{
				txsq.left = 0;
			}
			else
			{
				txsq.left += 319 / 3;
			}
			sp.setTextureRect(txsq);
			clock.restart(); // 0���ʹٽý���
		}
		window.draw(sp);
		window.display(); //�׸�������� ȭ��������� 
	}
}