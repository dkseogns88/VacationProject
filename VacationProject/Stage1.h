#pragma once

#include "Effect.h"
class Stage1 : public Effect

{
public:

	Stage1();
	virtual ~Stage1();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Destroy();
};
