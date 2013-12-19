#include <GL\glut.h>
#include "Game.h"

int main(int argc, char* argv[])
{
	Game* game = Game::Instance();

	game->Init("EasySoft Socialite", argc, argv);
	game->Start();

	return 0;
}