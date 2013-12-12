#ifndef _GAME
#define _GAME

#include <stdlib.h>
#include <string>
#include <GL\glut.h>

using namespace std;

class Game
{

private:
	static Game* _instance;
	static void Redraw();

	Game(){};
	Game(Game &const){};
	Game& operator=(Game const&){};

public:
	static Game* Instance();
	void Init(string title, int argc, char* argv[]);

	~Game();
};

#endif