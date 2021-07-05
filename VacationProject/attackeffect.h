#pragma once
#include "Effect.h"
class attackeffect : public Effect
{
public:
	attackeffect();
	virtual ~attackeffect();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};
