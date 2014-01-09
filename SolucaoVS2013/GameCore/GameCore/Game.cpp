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

void Game::RegisterGSM(GameStateManager* gsm, int delay)
{
	gsmanager = gsm;
	glutKeyboardFunc(&gsmanager->KeyboardFuncWrapper);
	glutKeyboardUpFunc(&gsmanager->KeyboardUpFuncWrapper);
	glutSpecialFunc(&gsmanager->SpecialFuncWrapper);
	glutSpecialUpFunc(&gsmanager->SpecialUpFuncWrapper);
	glutDisplayFunc(&gsmanager->RedrawWrapper);
	glutTimerFunc(delay, &gsmanager->CurrentStateTimerWrapper, 0);
}


void Game::Init(string title, int width, int height, int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow(title.c_str());
	
	RegisterGSM(GameStateManager::Instance(), 30);
	gsmanager->PushState(new SocialGraphState());

	glutMainLoop();           	//the main loop of the GLUT framework
}

void Game::Start()
{
	glutMainLoop();
}