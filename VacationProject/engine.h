#pragma once
//���漱��  :������� ���ӹ���
class AnimationObject;
#include "framework.h"
#include "engine.h"
#include "AnimationObject.h"


//���� ��ü�� �̷�� Ŭ����
class Engine final // final ���̻� ��Ŭ�������� ��ӹ��� ����
{

	//������, �Ҹ���
public:
	
	Engine();
	~Engine();

	

	
	
//��� ����
private:

	RenderWindow* window = nullptr;
	Event evt;

	Clock timer;
	float deltaTime = 0.f;

	AnimationObject* obj = nullptr;
	
	
	
	
//�޼ҵ�
private:
	//������ �ʱ�ȭ�ϴ� �Լ�
	void Init();

	//��������� �Է°��� ó��
	void Input();

	//���� ����ִ� ������Ʈ�� ������Ʈ
	void Update();
public:
	//�����쿡 ������� �����
	void Render();
	//������ ������������ ȣ��Ǵ� �Լ�
	void Destroy();

	
};


