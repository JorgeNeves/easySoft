#include "Game.h"

Game* Game::_instance = nullptr;

Game::Game()
{
	gsmanager = nullptr;
	//render = nullptr;
}

Game* Game::Instance()
{
	if (!_instance)
	{
		_instance = new Game;
	}
	return _instance;
}

void Game::Redraw()                           	//all drawing code goes here
{
	GameStateManager::Instance()->GetCurrentState()->Draw();
}

void Game::Init(string title, int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow(title.c_str());

	gsmanager = GameStateManager::Instance();

	// CALLBACK definitions
	glutDisplayFunc(&Redraw);
	glutKeyboardFunc(&gsmanager->KeyboardFuncWrapper);
	glutKeyboardUpFunc(&gsmanager->KeyboardUpFuncWrapper);
	
	GraphTestGameState* test = new GraphTestGameState();
	GameStateManager::Instance()->PushState(test);
	glutTimerFunc(30, GameStateManager::Instance()->CurrentStateTimerWrapper, 10);
	//GameStateManager::Instance()->GetCurrentState()->Update();

	glutMainLoop();           	//the main loop of the GLUT framework
}