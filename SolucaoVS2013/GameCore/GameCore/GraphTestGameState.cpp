#include "GraphTestGameState.h"


GraphTestGameState::GraphTestGameState()
{
}

GraphTestGameState::~GraphTestGameState()
{
}

void GraphTestGameState::Draw()
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

void GraphTestGameState::Update()
{

}

void GraphTestGameState::Load()
{
	
}

void GraphTestGameState::Unload()
{

}