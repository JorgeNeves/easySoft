#ifndef _GAME
#define _GAME

#include <stdlib.h>
#include <string>
#include <GL\glut.h>

#include "InputManager.h"
#include "GameStateManager.h"
#include "GameState.h"
#include "GraphTestGameState.h"

using namespace std;

class Game
{

private:
	static Game* _instance;
	static void Redraw();

	// private object creators for singleton implementation
	Game(){};
	Game(Game &const){};
	Game& operator=(Game const&){};

public:
	static Game* Instance();
	void Init(string title, int argc, char* argv[]);
	void Start();
	void Stop();

	~Game();
};

#endif