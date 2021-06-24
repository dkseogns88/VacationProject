#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "WINDOW");
	
	Sprite sp; //�������� ����. scaling �ʿ�
	Texture tx; //texture�� ����� �״�� �������⿡ ����� ���ؼ� ���̰ų� �ø��°� ����
	tx.loadFromFile("Texture/20180109_143508.jpg");
	sp.setScale(.100f,.100f);
	sp.setOrigin(tx.getSize().x/2.f ,tx.getSize().y/2.f);
	sp.setTexture(tx);
	sp.setPosition(250.f, 250.f);
	
	

	while (window.isOpen())//�����찡 ���µǾ�������
	{
		window.clear();
		window.draw(sp);
		window.display(); //�׸�������� ȭ��������� 
	}
}