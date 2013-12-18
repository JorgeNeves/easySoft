#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <time.h>
#include <iostream>
#include <GL/glut.h>

using namespace std;

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#define SIDE 150
#define MARGEM 20
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
	int       west;
	int     north;
	int     east;
	int      south;
}Maze;

typedef struct {
	int       a;
	int     b;
}Liga;



Estado estado;
Modelo modelo;
Maze maze[2][2];




/* Inicialização do ambiente OPENGL */
void Init(void)
{


	//delay para o timer
	estado.delay = 1000;
	maze[0][0].north=1;
	maze[0][0].east = 1;
	maze[0][0].south = 0;
	maze[0][0].west = 1;

	maze[0][1].north = 1;
	maze[0][1].east = 1;
	maze[0][1].south = 1;
	maze[0][1].west = 1;

	maze[1][0].north = 0;
	maze[1][0].east = 0;
	maze[1][0].south = 1;
	maze[1][0].west = 1;

	maze[1][1].north = 1;
	maze[1][1].east = 1;
	maze[1][1].south = 1;
	maze[1][1].west = 0;
	

	

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);

}

void ligacoes(int value)
{
	std::list<Liga> p;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
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
	gluOrtho2D(-20, 320, 320, -20);

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
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (maze[i][j].south == 1) {
				glPushMatrix();
				//glTranslatef(j * 2 - 2, 0, i * 2);
				//glutSolidCube(2);
				glBegin(GL_LINES);
				glVertex2f(SIDE * j, SIDE + SIDE*i);
				glVertex2f(SIDE + SIDE * j, SIDE + SIDE*i);
				cout << " [" << i << "," << j << "]  -----------" << endl;
				cout << SIDE * j << " - " << SIDE*j << endl;
				cout << SIDE +  SIDE * j << " - " << SIDE*j << endl;
				glEnd();
				glPopMatrix();
			}
			if (maze[i][j].north == 1) {
				glPushMatrix();
				/*glTranslatef(j * 2 + 2, 0, i * 2);
				glutSolidCube(2);*/
				glBegin(GL_LINES);
				glVertex2f(SIDE + SIDE * j, SIDE*i);
				glVertex2f(SIDE * j, SIDE*i);
				
				glEnd();
				glPopMatrix();
			}
			if (maze[i][j].east == 1) {
				glPushMatrix();
				glBegin(GL_LINES);
				glVertex2f(SIDE + SIDE * j, SIDE + SIDE * i);
				glVertex2f(SIDE + SIDE * j, SIDE*i);
				glEnd();
				glPopMatrix();
			}
			if (maze[i][j].west == 1) {
				glPushMatrix();
				glBegin(GL_LINES);
				glVertex2f(SIDE * j, SIDE*i);
				glVertex2f(SIDE * j, SIDE + SIDE * i);
				glEnd();
				glPopMatrix();
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
	case 'l':
	case 'L':
		modelo.tipoPoligono = GL_LINE_LOOP;
		glutPostRedisplay(); // redesenhar o ecrã
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
	glutInitWindowSize(300, 300);
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