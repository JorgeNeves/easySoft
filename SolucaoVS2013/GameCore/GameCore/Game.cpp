#include "Game.h"

Game* Game::_instance = nullptr;

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
	glPushMatrix();     	//saves the current matrix on the top of the matrix stack
	glTranslatef(0, 0, -100); //translates the current matrix 0 in x, 0 in y and -100 in z
	glBegin(GL_TRIANGLES);  //tells OpenGL that we're going to start drawing triangles
	glColor3f(1, 0, 0);   	//sets the current colour to red
	glVertex3f(-30, -30, 0);  //specifies the first vertex of our triangle

	glColor3f(0, 1, 0);   	//sets the current colour to green
	glVertex3f(30, -30, 0);   //specifies the second vertex of our triangle

	glColor3f(0, 0, 1);   	//sets the current colour to blue
	glVertex3f(-30, 30, 0);   //specifies the third vertex of our triangle
	glEnd();                //tells OpenGL that we've finished drawing
	glPopMatrix();          //retrieves our saved matrix from the top of the matrix stack
	glutSwapBuffers();      //swaps the front and back buffers
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

	glutMainLoop();           	//the main loop of the GLUT framework
}