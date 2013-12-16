#pragma once
#include "GameStateController.h"

class GameState
{

public:
	GameState();
	virtual ~GameState();

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};