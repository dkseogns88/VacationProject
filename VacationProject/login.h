#pragma once

#include "Effect.h"
class login : public Effect

{
public:
	
	login();
	virtual ~login();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Destroy();
};
