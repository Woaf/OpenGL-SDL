#pragma once
#include "GameState.h"
class Teststate : public GameState
{
public:
	Teststate();
	bool Init();
	bool Update();
	bool Destroy();
	~Teststate();
};

