#pragma once

#include <stdlib.h>
#include <string>
#include <GL\glut.h>

#include "Exception.h"
#include "LOCALE_EN.h"
#include "InputManager.h"
#include "GameStateManager.h"
#include "GraphTestGameState.h"

using namespace std;

class Game
{

private:
	static Game* _instance;
	static void Redraw();

	// Components

	InputManager* input;
	GameStateManager* gsmanager;
	//Renderer renderer;

	// private object creators for singleton implementation
	Game();
	Game(Game &const);
	Game& operator=(Game const&){};

public:
	static Game* Instance();
	void Init(string title, int argc, char* argv[]);
	void Start();
	void Stop();

	~Game();
};