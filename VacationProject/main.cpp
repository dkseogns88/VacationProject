#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "WINDOW");

	RectangleShape rs; //�簢�� ������Ʈ����

	//Vector2f = float �ڷ��� �ΰ� ¥��
	rs.setSize(Vector2f(100.f, 100.f)); 
	rs.setFillColor(Color::Green);
	rs.setPosition(Vector2f(250.f, 250.f)); //������ġ 100.f , 100.f 
	
	rs.setOrigin(rs.getSize() / 2.f); //������Ʈ�� �߽��� set�ϴ� �Լ�

	while (window.isOpen())//�����찡 ���µǾ�������
	{
		window.clear();
		//rs.setPosition(rs.getPosition().x + .01f, rs.getPosition().y + .01f);
		window.draw(rs); //rs������Ʈ�� �����쿡 �׸�
		window.display(); //�׸�������� ȭ��������� 
	}
}