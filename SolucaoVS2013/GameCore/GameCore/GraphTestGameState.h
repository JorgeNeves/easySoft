#pragma once
#include "GameState.h"
#include <GL\glut.h>
class GraphTestGameState :
	public GameState
{
public:
	GraphTestGameState();
	~GraphTestGameState();

	void Load();
	void Unload();
	void Update();
	void Draw();
};

