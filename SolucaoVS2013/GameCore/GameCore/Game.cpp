#include "Game.h"

Game* Game::_instance = nullptr;

Game::Game()
{
	input = nullptr;
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
	InputManager* input = InputManager::Instance();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow(title.c_str());

	// CALLBACK definitions
	glutDisplayFunc(&Redraw);
	glutKeyboardFunc(&input->KeyboardFuncWrapper);
	glutKeyboardUpFunc(&input->KeyboardUpFuncWrapper);

	glMatrixMode(GL_PROJECTION);   //changes the current matrix to the projection matrix
	//sets up the projection matrix for a perspective transform
	gluPerspective(45, 	//view angle
		1.0,    //aspect ratio
		10.0,   //near clip
		200.0); //far clip
	glMatrixMode(GL_MODELVIEW);   //changes the current matrix to the modelview matrix
	GraphTestGameState* test = new GraphTestGameState();
	GameStateManager::Instance()->PushState(test);
	glutMainLoop();           	//the main loop of the GLUT framework
}