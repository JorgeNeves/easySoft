#pragma once

#include <stdlib.h>
#include <string>
#include <GL\glut.h>

#include "Exception.h"
#include "LOCALE_EN.h"
#include "GameStateManager.h"
#include "SocialGraphState.h"

using namespace std;

class Game
{

private:
	static Game* _instance;

	// Components
	GameStateManager* gsmanager;
	//Renderer renderer;

	// private object creators for singleton implementation
	Game();
	Game(const Game&);
	Game& operator=(const Game&){};

public:
	static Game* Instance();
	void Init(string title, int argc, char* argv[]);
	void Start();
	void Stop();
	void RegisterGSM(GameStateManager* gsm, int delay);
	~Game();
};