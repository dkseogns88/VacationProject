#include "framework.h"
#include "Button.h"
#include "BackgroundScene.h"

sf::Music musics;
Button::Button(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position)
{
	idleTexture = new Texture;
	idleTexture->loadFromFile(idleTexturePath);

	activeTexture = new Texture;
	activeTexture->loadFromFile(activeTexturePath);

	setTexture(*idleTexture);
	setOrigin(getGlobalBounds().width / 2.f, getGlobalBounds().height / 2.f);
	setPosition(position);
}

void Button::Destroy()
{
	DELETE(idleTexture);
	DELETE(activeTexture);
}

bool Button::IsPressed()
{
	return isPress;
}

void Button::Update(const Vector2f& mousePosition, stack<Scene*>* scenes, RenderWindow* window, SoundEffect* soundEffect)
{
	
	isPress = false;
	/*메뉴화면에서 로그인버튼누르면 게임화면으로 씬전환*/
	/*버튼은 생겼지만 눌러도 아무반응이없음*/
	if (getGlobalBounds().contains(mousePosition))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			
			isPress = true;
			musics.stop();
			scenes->push(new BackgroundScene(scenes, window, soundEffect));
		}
	}
}

void Button::Render(RenderTarget* target)
{
	if (target)
	{
		target->draw(*this); //씬에서 버튼을그리는역할
	}
}
