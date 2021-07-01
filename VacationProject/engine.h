#pragma once
//전방선언  :헤더파일 꼬임방지
class AnimationObject;
#include "framework.h"
#include "engine.h"
#include "AnimationObject.h"


//게임 전체를 이루는 클래스
class Engine final // final 더이상 이클래스에게 상속받지 않음
{

	//생성자, 소멸자
public:
	
	Engine();
	~Engine();

	

	
	
//멤버 변수
private:

	RenderWindow* window = nullptr;
	Event evt;

	Clock timer;
	float deltaTime = 0.f;

	vector<AnimationObject*> obj;
	
	
	
	
//메소드
private:
	//엔진를 초기화하는 함수
	void Init();

	//윈도우상의 입력값을 처리
	void Input();

	//현재 살아있는 오브젝트를 업데이트
	void Update();
public:
	//윈도우에 결과물을 출력함
	void Render();
	//엔진이 없어지기전에 호출되는 함수
	void Destroy();

	
};


