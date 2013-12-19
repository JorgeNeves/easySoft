#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <time.h>
#include <iostream>
#include <GL/glut.h>
#include "Reader.h"

using namespace std;

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#define SIDE 300
#define MARGEM 5
#define RAIO 5
#endif

#define DEBUG 1

/* VARIAVEIS GLOBAIS */

typedef struct {
	GLboolean   doubleBuffer;
	GLint       delay;
}Estado;

typedef struct {
	GLint       numLados;
	GLfloat     raio;
	GLfloat     tamLado;
	GLenum      tipoPoligono;
}Modelo;

typedef struct {
	int       a;
	int     b;
}Liga;

typedef struct {
	int       mPosX;
	int     mPosY;
}Avatar;



Estado estado;
Maze maze[40][40];
Modelo modelo;
Avatar avatar;
int mSize;




/* Inicialização do ambiente OPENGL */
void Init(void)
{

	mSize = 40;

	//delay para o timer
	estado.delay = 1000;
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			maze[i][j].north = 1;
			maze[i][j].east = 1;
			maze[i][j].south = 1;
			maze[i][j].west = 1;
			if ((i % 2) == 0)
			{
				maze[i][j].value = 3;
			}
			else
			{
				maze[i][j].value = 0;
			}
		}

	}
	maze[0][0].north = 1;
	maze[0][0].east = 0;
	maze[0][0].south = 1;
	maze[0][0].west = 1;
	maze[0][0].value = 1;


	maze[30][30].north = 1;
	maze[30][30].east = 0;
	maze[30][30].south = 1;
	maze[30][30].west = 1;
	maze[30][30].value = 2;
	/*maze[0][1].north = 1;
	maze[0][1].east = 1;
	maze[0][1].south = 0;
	maze[0][1].west = 0;
	maze[0][1].value = 1;

	maze[1][0].north = 1;
	maze[1][0].east = 1;
	maze[1][0].south = 1;
	maze[1][0].west = 1;
	maze[1][0].value = 0;

	maze[1][1].north = 0;
	maze[1][1].east = 1;
	maze[1][1].south = 1;
	maze[1][1].west = 1;
	maze[1][1].value = 2;*/

	for (int i = 0; i < mSize; i++) {
		for (int j = 0; j < mSize; j++) {
			if (maze[i][j].value == 1)
			{
				avatar.mPosX = i;
				avatar.mPosY = j;
			}
		}
	}




	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);

}

void ligacoes(int value)
{
	std::list<Liga> p;
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize; j++)
		{
			if (maze[i][j].north == 0){ Liga l; l.a = i * 10 + j; l.b = (i - 1) * 10 + j;  p.push_back(l); }
			if (maze[i][j].south == 0){ Liga l; l.a = i * 10 + j; l.b = i + 1 * 10 + j;  p.push_back(l); }
			if (maze[i][j].east == 0) { Liga l; l.a = i * 10 + j; l.b = i * 10 + j + 1;  p.push_back(l); }
			if (maze[i][j].west == 0) { Liga l; l.a = i * 10 + j; l.b = i * 10 + j - 1;  p.push_back(l); }

		}
	}

	while (!p.empty())
	{
		Liga x = p.front();
		cout << "Liga(" << x.a << "," << x.b << ")." << endl;
		p.pop_front();
	}



}

/**************************************
***  callbacks de janela/desenho    ***
**************************************/

// CALLBACK PARA REDIMENSIONAR JANELA

void Reshape(int width, int height)
{
	GLint size;

	if (width < height)
		size = width;
	else
		size = height;

	// glViewport(botom, left, width, height)
	// define parte da janela a ser utilizada pelo OpenGL

	glViewport(0, 0, (GLint)size, (GLint)size);


	// Matriz Projeccao
	// Matriz onde se define como o mundo e apresentado na janela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluOrtho2D(left,right,bottom,top); 
	// projeccao ortogonal 2D, com profundidade (Z) entre -1 e 1
	gluOrtho2D(-20, SIDE * 40, SIDE * 40 + 20, -20);

	// Matriz Modelview
	// Matriz onde são realizadas as tranformacoes dos modelos desenhados
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


// ... definicao das rotinas auxiliares de desenho ...

// Callback de desenho

void Draw(void)
{
	ligacoes(0);
	for (int i = 0; i < mSize; i++) {
		for (int j = 0; j < mSize; j++) {

			if (avatar.mPosX == i && avatar.mPosY == j){
				cout << "avatar:" << avatar.mPosX << "," << avatar.mPosY << endl;
				glColor3f(0.2, 0.3, 1.0);
				glBegin(GL_TRIANGLE_FAN);
				float x1 = SIDE*.5 + SIDE * j + RAIO;
				float y1 = SIDE*.5 + SIDE * i - RAIO;
				//glVertex2f(x1, y1);

				for (int angle = 0; angle < 360; angle += 5){

					glVertex2f(x1 + sin(angle) * RAIO, y1 + cos(angle) * RAIO);


				}
				glEnd();
				glColor3f(1.0, 1.0, 1.0);
			}
			if (maze[i][j].value == 3){
				glBegin(GL_QUADS);
				glVertex2f(SIDE * j + MARGEM, SIDE*i + MARGEM);
				glVertex2f(SIDE * j + MARGEM, SIDE*i + SIDE - MARGEM);
				glVertex2f(SIDE - MARGEM + SIDE * j, SIDE*i + SIDE - MARGEM);
				glVertex2f(SIDE - MARGEM + SIDE * j, SIDE*i + MARGEM);
				glEnd();
			}
			if (maze[i][j].south == 1) {

				glBegin(GL_LINES);
				glVertex2f(SIDE * j, SIDE + SIDE*i);
				glVertex2f(SIDE + SIDE * j, SIDE + SIDE*i);
				glEnd();
			}
			if (maze[i][j].north == 1) {
				/*glTranslatef(j * 2 + 2, 0, i * 2);
				glutSolidCube(2);*/
				glBegin(GL_LINES);
				glVertex2f(SIDE + SIDE * j, SIDE*i);
				glVertex2f(SIDE * j, SIDE*i);

				glEnd();
			}
			if (maze[i][j].east == 1) {
				glBegin(GL_LINES);
				glVertex2f(SIDE + SIDE * j, SIDE + SIDE * i);
				glVertex2f(SIDE + SIDE * j, SIDE*i);
				glEnd();
			}
			if (maze[i][j].west == 1) {
				glBegin(GL_LINES);
				glVertex2f(SIDE * j, SIDE*i);
				glVertex2f(SIDE * j, SIDE + SIDE * i);
				glEnd();
			}
			if (maze[i][j].value == 1){
				glColor3f(0.0, 0.2, 1.0);
				glBegin(GL_LINE_LOOP);

				glVertex2f(SIDE * j + MARGEM, SIDE*i + MARGEM);
				glVertex2f(SIDE * j + MARGEM, SIDE*i + SIDE - MARGEM);
				glVertex2f(SIDE - MARGEM + SIDE * j, SIDE*i + SIDE - MARGEM);
				glVertex2f(SIDE - MARGEM + SIDE * j, SIDE*i + MARGEM);

				glEnd();
				glColor3f(1.0, 1.0, 1.0);
			}
			if (maze[i][j].value == 2){
				glColor3f(1.0, 0.2, 0.0);
				glBegin(GL_LINE_LOOP);

				glVertex2f(SIDE * j + MARGEM, SIDE*i + MARGEM);
				glVertex2f(SIDE * j + MARGEM, SIDE*i + SIDE - MARGEM);
				glVertex2f(SIDE - MARGEM + SIDE * j, SIDE*i + SIDE - MARGEM);
				glVertex2f(SIDE - MARGEM + SIDE * j, SIDE*i + MARGEM);

				glEnd();
				glColor3f(1.0, 1.0, 1.0);
			}

		}
	}



	glFlush();
	if (estado.doubleBuffer)
		glutSwapBuffers();
}

/*******************************
***   callbacks timer/idle   ***
*******************************/

// Callback Idle

void Idle(void)
{

	// accoes a tomar quando o glut está idle 

	// redesenhar o ecra 
	// glutPostRedisplay();
}

// Callback de temporizador




void imprime_ajuda(void)
{
	printf("\n\nDesenho de um quadrado\n");
	printf("h,H - Ajuda \n");
	printf("p,P - Poligono desenhado com GL_POLYGON\n");
	printf("t,T - Poligono desenhado com GL_TRIANGLE_FAN\n");
	printf("l,L - Poligono desenhado com GL_LINE_LOOP\n");
	printf("+   - Aumentar tamanho numero de Lados\n");
	printf("-   - Diminuir tamanho numero de Lados\n");
	printf("R   - Aumentar tamanho raio\n");
	printf("r   - Diminuir tamanho raio\n");
	printf("ESC - Sair\n");
}

/*******************************
***  callbacks de teclado    ***
*******************************/

// Callback para interaccao via teclado (carregar na tecla)

void Key(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(1);
		// ... accoes sobre outras teclas ... 

	case 'h':
	case 'H':
		imprime_ajuda();
		break;
	case '+':
		if (modelo.numLados<32)
		{
			modelo.numLados++;
			glutPostRedisplay(); // redesenhar o ecrã
		}
		break;
	case '-':
		if (modelo.numLados>3)
		{
			modelo.numLados--;
			glutPostRedisplay(); // redesenhar o ecrã
		}
		break;
	case 'p':
	case 'P':
		modelo.tipoPoligono = GL_POLYGON;
		glutPostRedisplay(); // redesenhar o ecrã
		break;
	case 't':
	case 'T':
		modelo.tipoPoligono = GL_TRIANGLE_FAN;
		glutPostRedisplay(); // redesenhar o ecrã
		break;
	case 's':
	case 'S':
		if (maze[avatar.mPosX][avatar.mPosY].south == 0)
		{
			avatar.mPosX++;
			glutPostRedisplay(); // redesenhar o ecrã
		}
		break;
	case 'w':
	case 'W':
		if (maze[avatar.mPosX][avatar.mPosY].north == 0)
		{
			avatar.mPosX--;
			glutPostRedisplay(); // redesenhar o ecrã
		}
		break;
	case 'd':
	case 'D':
		if (maze[avatar.mPosX][avatar.mPosY].east == 0)
		{
			avatar.mPosY++;
			glutPostRedisplay(); // redesenhar o ecrã
		}
		break;
	case 'a':
	case 'A':
		if (maze[avatar.mPosX][avatar.mPosY].west == 0)
		{
			avatar.mPosY--;
			glutPostRedisplay(); // redesenhar o ecrã
		}
		break;
	case 'R':
		if (modelo.raio<0.9)
		{
			modelo.raio += 0.05;
			glutPostRedisplay(); // redesenhar o ecrã
		}
		break;
	case 'r':
		if (modelo.raio>.2)
		{
			modelo.raio -= 0.05;
			glutPostRedisplay(); // redesenhar o ecrã
		}
		break;

	}

	if (DEBUG)
		printf("Carregou na tecla %c\n", key);

}

// Callback para interaccao via teclado (largar a tecla)

/*void KeyUp(unsigned char key, int x, int y)
{

if(DEBUG)
printf("Largou a tecla %c\n",key);
}/*/

// Callback para interaccao via teclas especiais  (carregar na tecla)

/*void SpecialKey(int key, int x, int y)
{
// ... accoes sobre outras teclas especiais ...
//    GLUT_KEY_F1 ... GLUT_KEY_F12
//    GLUT_KEY_UP
//    GLUT_KEY_DOWN
//    GLUT_KEY_LEFT
//    GLUT_KEY_RIGHT
//    GLUT_KEY_PAGE_UP
//    GLUT_KEY_PAGE_DOWN
//    GLUT_KEY_HOME
//    GLUT_KEY_END
//    GLUT_KEY_INSERT

switch (key) {

// redesenhar o ecra
//glutPostRedisplay();
}


if(DEBUG)
printf("Carregou na tecla especial %d\n",key);
}/*/

// Callback para interaccao via teclas especiais (largar na tecla)

/*void SpecialKeyUp(int key, int x, int y)
{

if(DEBUG)
printf("Largou a tecla especial %d\n",key);

}/*/


int main(int argc, char **argv)
{
	estado.doubleBuffer = GL_TRUE;

	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 6000);
	glutInitDisplayMode(((estado.doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE) | GLUT_RGB);
	if (glutCreateWindow("Exemplo") == GL_FALSE)
		exit(1);

	Init();

	imprime_ajuda();

	// Registar callbacks do GLUT

	// callbacks de janelas/desenho
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Draw);

	// Callbacks de teclado
	glutKeyboardFunc(Key);
	//glutKeyboardUpFunc(KeyUp);
	//glutSpecialFunc(SpecialKey);
	//glutSpecialFunc(SpecialKeyUp);

	// callbacks timer/idle
	//glutTimerFunc(estado.delay, Timer, 0);
	//glutIdleFunc(Idle);


	// COMECAR...
	glutMainLoop();
}