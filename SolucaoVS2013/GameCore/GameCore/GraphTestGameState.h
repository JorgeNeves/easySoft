#pragma once
#include <GL\glut.h>
#include <stdio.h>
#include "GameStateManager.h"
#include "InputManager.h"
class GraphTestGameState : public GameState
{
private:
	float x;
	GameStateManager* manager;
public:
	GraphTestGameState();
	~GraphTestGameState();

	void Load();
	void Unload();
	void Update();
	void Draw();
};

