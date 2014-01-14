#include <GL\glut.h>
#include "Game.h"


#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define GAME_TITLE "Socialite"


int main(int argc, char* argv[])
{
	Game* game = Game::Instance();

	game->Init(GAME_TITLE, WIN_WIDTH, WIN_HEIGHT, argc, argv);
	game->Start();

	return 0;
}