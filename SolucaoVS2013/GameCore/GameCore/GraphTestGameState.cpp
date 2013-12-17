#include "GraphTestGameState.h"


GraphTestGameState::GraphTestGameState()
{
	x = 30;
}

GraphTestGameState::~GraphTestGameState()
{
}

void GraphTestGameState::Draw()
{
	glPushMatrix();     	//saves the current matrix on the top of the matrix stack
	glTranslatef(0, 0, -100); //translates the current matrix 0 in x, 0 in y and -100 in z
	glBegin(GL_TRIANGLES);  //tells OpenGL that we're going to start drawing triangles
	glColor3f(1, 0, 0);   	//sets the current colour to red
	glVertex3f(-30, -30, 0);  //specifies the first vertex of our triangle

	glColor3f(0, 1, 0);   	//sets the current colour to green
	glVertex3f(x, -30, 0);   //specifies the second vertex of our triangle

	glColor3f(0, 0, 1);   	//sets the current colour to blue
	glVertex3f(-30, x, 0);   //specifies the third vertex of our triangle
	glEnd();                //tells OpenGL that we've finished drawing
	glPopMatrix();          //retrieves our saved matrix from the top of the matrix stack
}

void GraphTestGameState::Update()
{
	if (InputManager::Instance()->GetKeyStates()['a'])
	{
		x = x + 0.3;
		printf("%f\n", x);
	}
	if (InputManager::Instance()->GetKeyStates()['1'])
	{
		GameStateManager::Instance()->PushState(new GraphTestGameState());
	}
	if (InputManager::Instance()->GetKeyStates()['2'])
	{
		GameStateManager::Instance()->PopState();
	}
}

void GraphTestGameState::Load()
{
}

void GraphTestGameState::Unload()
{

}