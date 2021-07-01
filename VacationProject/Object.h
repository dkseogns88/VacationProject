#pragma once
class Object : public Sprite
{
public:
	Object() = default;
	virtual ~Object() = default;


	// protected는 상속받는 클래스끼리만 사용가능

private:
	virtual void Init() = 0; //순수 가상함수

public:


	virtual void Destroy() = 0;
	virtual void Update(const float& deltaTime) = 0;

};
