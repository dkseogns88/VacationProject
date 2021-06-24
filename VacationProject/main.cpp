#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "WINDOW");

	RectangleShape rs; //사각형 오브젝트생성

	//Vector2f = float 자료형 두개 짜리
	rs.setSize(Vector2f(100.f, 100.f)); 
	rs.setFillColor(Color::Green);
	rs.setPosition(Vector2f(250.f, 250.f)); //생성위치 100.f , 100.f 
	
	rs.setOrigin(rs.getSize() / 2.f); //오브젝트의 중심을 set하는 함수

	while (window.isOpen())//윈도우가 오픈되어있을때
	{
		window.clear();
		//rs.setPosition(rs.getPosition().x + .01f, rs.getPosition().y + .01f);
		window.draw(rs); //rs오브젝트를 윈도우에 그림
		window.display(); //그린결과물을 화면으로출력 
	}
}