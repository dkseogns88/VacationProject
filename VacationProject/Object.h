#pragma once
class Object : public Sprite
{
public:
	Object() = default;
	virtual ~Object() = default;


	// protected�� ��ӹ޴� Ŭ���������� ��밡��

private:
	virtual void Init() = 0; //���� �����Լ�

public:


	virtual void Destroy() = 0;
	virtual void Update(const float& deltaTime) = 0;

};
