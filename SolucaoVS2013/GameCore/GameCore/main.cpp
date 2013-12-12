#include <GL\glut.h>
#include "Game.h"

int main(int argc, char* argv[])
{	Game::Instance()->Init("JOGO", argc, argv);
	return 0;
}