#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "WINDOW");
	
	Sprite sp; //절대사이즈가 없다. scaling 필요
	Texture tx; //texture의 사이즈를 그대로 가져오기에 배수에 곱해서 줄이거나 늘리는게 가능
	tx.loadFromFile("Texture/20180109_143508.jpg");
	sp.setScale(.100f,.100f);
	sp.setOrigin(tx.getSize().x/2.f ,tx.getSize().y/2.f);
	sp.setTexture(tx);
	sp.setPosition(250.f, 250.f);
	
	

	while (window.isOpen())//윈도우가 오픈되어있을때
	{
		window.clear();
		window.draw(sp);
		window.display(); //그린결과물을 화면으로출력 
	}
}