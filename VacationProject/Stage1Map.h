#pragma once

#include "Effect.h"
class Stage1Map : public Effect

{
public:

	Stage1Map();
	virtual ~Stage1Map();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Destroy();
};
