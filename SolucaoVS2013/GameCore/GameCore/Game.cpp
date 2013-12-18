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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //clears the colour and depth buffers
	GameStateManager::Instance()->GetCurrentState()->Draw();
	glutSwapBuffers();      //swaps the front and back buffers
	glutPostRedisplay();
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
	glutTimerFunc(30, GameStateManager::Instance()->CurrentStateTimerWrapper, 10);
	//GameStateManager::Instance()->GetCurrentState()->Update();

	glutMainLoop();           	//the main loop of the GLUT framework
}