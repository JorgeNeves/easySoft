#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include <algorithm>
#include <ctype.h>

using namespace std;
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#define DEBUG 1

/* VARIAVEIS GLOBAIS */

typedef struct {
	GLboolean   doubleBuffer;
	GLint       delay;
}Estado;

typedef struct {
	GLint		nletras;
	string      pal;
	const char* p;
	const char* paux;
}Palavra;

typedef struct{
	int	nerros;
	char* letra;
}Jogo;

Estado estado;
Jogo jogo;
Palavra palavra;


/* Inicialização do ambiente OPENGL */
void Init(void)
{
	
	palavra.pal = "AVAL IACAO";
	palavra.nletras = palavra.pal.length();
	palavra.p = palavra.pal.c_str();
	//string newString;
	
	//transform(palavra.pal.begin(),palavra.pal.end(),newString.begin(),tolower);

	//palavra.paux = newString.c_str();
	//tracinhos();

	//delay para o timer
	estado.delay = 10;
	jogo.nerros = 0;

	glClearColor(0.0, 0.0, 0.0, 0.0);
	/*
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);*/


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


	// Matriz Projecção
	// Matriz onde se define como o mundo e apresentado na janela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluOrtho2D(left,right,bottom,top); 
	// projecção ortogonal 2D, com profundidade (Z) entre -1 e 1
	gluOrtho2D(-1, 1, -1, 1);

	// Matriz Modelview
	// Matriz onde são realizadas as tranformacões dos modelos desenhados
	glMatrixMode(GL_MODELVIEW_MATRIX);
	glLoadIdentity();
}

// ... definicao das rotinas auxiliares de desenho ...

void forca()
{
	glBegin(GL_LINES); //Begins drawing of a 3D line
	glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
	glVertex3f(-0.5f, 0.7f, 0.0f); //Here are two vertices that are used as 
	glVertex3f(-0.5f, -0.3f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
	glEnd(); //End drawing

	glBegin(GL_LINES); //Begins drawing of a 3D line
	glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
	glVertex3f(-0.75f,-0.3f, 0.0f); //Here are two vertices that are used as 
	glVertex3f(0.0f,-0.3f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
	glEnd(); //End drawing

	glBegin(GL_LINES); //Begins drawing of a 3D line
	glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
	glVertex3f(-0.5f, 0.7f, 0.0f); //Here are two vertices that are used as 
	glVertex3f(0.1f, 0.7f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
	glEnd(); //End drawing

	glBegin(GL_LINES); //Begins drawing of a 3D line
	glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
	glVertex3f(0.1f, 0.7f, 0.0f); //Here are two vertices that are used as 
	glVertex3f(0.1f, 0.6f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
	glEnd(); //End drawing
}

void cabeca(){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * M_PI;

	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			0.1f + (0.1f * cos(i *  twicePi / lineAmount)), //x
			0.5f + (0.1f * sin(i * twicePi / lineAmount)) //y
			);
	}
	glEnd();
}

void pescoco(){
	glBegin(GL_LINES); //Begins drawing of a 3D line
	glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
	glVertex3f(0.1f, 0.4f, 0.0f); //Here are two vertices that are used as 
	glVertex3f(0.1f, 0.35f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
	glEnd(); //End drawing
}

void tronco(){
	glBegin(GL_LINES); //Begins drawing of a 3D line
	glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
	glVertex3f(0.1f, 0.35f, 0.0f); //Here are two vertices that are used as 
	glVertex3f(0.1f, 0.1f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
	glEnd(); //End drawing
}

void braco(int n){
	
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
		glVertex3f(0.1f, 0.35f, 0.0f); //Here are two vertices that are used as 
		glVertex3f(0.0f, 0.2f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
		glEnd(); //End drawing
		if (n == 2){
			glBegin(GL_LINES);
			glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
			glVertex3f(0.1f, 0.35f, 0.0f); //Here are two vertices that are used as 
			glVertex3f(0.2f, 0.2f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
			glEnd(); //End drawing
		}
	
}

void perna(int n){

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
	glVertex3f(0.1f, 0.1f, 0.0f); //Here are two vertices that are used as 
	glVertex3f(0.0f, 0.0f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
	glEnd(); //End drawing
	if (n == 2){
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
		glVertex3f(0.1f, 0.1f, 0.0f); //Here are two vertices that are used as 
		glVertex3f(0.2f, 0.0f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
		glEnd(); //End drawing
	}

}

void desenhaLetra(int pos){
	float inc = 1.8 / palavra.nletras;
	float posxi = -0.9;

	for (int i = 0; i < pos+1; i++){
		glColor3f(1.0f, 0.0f, 0.3f);
		glRasterPos2f(posxi + 0.05f, -0.6f);

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, palavra.p[i]);
		posxi += inc;
	}
}

void tracinhos(){
	
	float n = palavra.nletras*0.5;
	
	//negativos
	float inc = 1.8 / palavra.nletras;
	float inc_D = 1.5 / palavra.nletras;
	float posxi =-0.9;

	for (int i = 0; i < palavra.nletras; i++){
		if (palavra.p[i] != ' '){
			glBegin(GL_LINES);
			glColor3f(1.0f, 1.0f, 0.0f); //sets color of line
			glVertex3f(posxi, -0.7f, 0.0f); //Here are two vertices that are used as 
			glVertex3f(posxi + inc_D, -0.7f, 0.0f); //endpoints for the line. Adjust the numbers inside glVertex3f() to move the line
			glEnd(); //End drawing

			glColor3f(1.0f, 1.0f, 0.3f);

			glRectf(posxi, -0.65f, posxi + inc_D, -0.45f);

			desenhaLetra(i);

		}
		posxi += inc;
		
	}

}

void existe(){
	if (palavra.p[0] == toupper((char)jogo.letra)){
		printf("Existe %c\n", jogo.letra);
	}
}
// Callback de desenho

void Draw(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	// ... chamada das rotinas auxiliares de desenho ...

	forca();

	tracinhos();

	if (jogo.nerros == 1){
		cabeca();
	}
	if (jogo.nerros == 2){
		cabeca();
		pescoco();
		tronco();
	}
	if (jogo.nerros == 3){
		cabeca();
		pescoco();
		tronco();
		braco(1);
	}
	if (jogo.nerros == 4){
		cabeca();
		pescoco();
		tronco();
		braco(2);
	}
	if (jogo.nerros == 5){
		cabeca();
		pescoco();
		tronco();
		braco(2);
		perna(1);
	}
	if (jogo.nerros == 6){
		cabeca();
		pescoco();
		tronco();
		braco(2);
		perna(2);
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

void Timer(int value)
{
	// ... accoes do temporizador ... 

	
	glutTimerFunc(estado.delay, Timer, 0);

	// redesenhar o ecra 
	glutPostRedisplay();
}


void imprime_ajuda(void)
{
	printf("\n\nDesenho de um quadrado\n");
	printf("h,H - Ajuda \n");
	printf("p,P - Mostrador desenhado com GL_POLYGON\n");
	printf("t,T - Mostrador desenhado com GL_TRIANGLE_FAN\n");
	printf("l,L - Mostrador desenhado com GL_LINE_LOOP\n");
	printf("A   - Aumentar delay do timer\n");
	printf("d   - Diminuir delay do timer\n");
	printf("+   - Aumentar tamanho numero de Lados\n");
	printf("-   - Diminuir tamanho numero de Lados\n");
	printf("R   - Aumentar tamanho raio\n");
	printf("r   - Diminuir tamanho raio\n");
	printf("ESC - Sair\n");
}

/*******************************
***  callbacks de teclado    ***
*******************************/

// Callback para interacção via teclado (carregar na tecla)

void Key(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(1);
		// ... accoes sobre outras teclas ... 
	}
	jogo.letra = (char *)key;
	
	existe();
	if (DEBUG)
		printf("Carregou na tecla %c\n", key);

}


int main(int argc, char **argv)
{
	estado.doubleBuffer = GL_TRUE;

	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
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
	glutTimerFunc(estado.delay, Timer, 0);
	//glutIdleFunc(Idle);


	// COMECAR...
	glutMainLoop();

	return 0;
}