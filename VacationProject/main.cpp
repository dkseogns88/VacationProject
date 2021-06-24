#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "WINDOW");
	window.setFramerateLimit(60);
	IntRect txsq(0,0,319/3,424/4); //이미지를 자름
	// 319 X 424 이미지의 사이즈 
	Texture tx; // 이미지를 불러옴
	tx.loadFromFile("Texture/dragonFrames.png");
	
	Sprite sp(tx,txsq); //Texture 을불러와서 움직임을 구현함
	sp.setScale(3.f, 3.f);

	Clock clock; //시간

	while (window.isOpen())//윈도우가 오픈되어있을때
	{
		window.clear();
		
		Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
			{
				window.close(); //윈도우 종료
				break;
			}
			default:
				break;
			}
		}
		if (clock.getElapsedTime().asSeconds() >= 0.3f) //실행하다가 0.3초가지나면 if문실행
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
			clock.restart(); // 0부터다시시작
		}
		window.draw(sp);
		window.display(); //그린결과물을 화면으로출력 
	}
}