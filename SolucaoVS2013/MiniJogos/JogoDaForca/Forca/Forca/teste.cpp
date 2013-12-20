#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include <algorithm>
#include <ctype.h>
#include <Windows.h>
#include <SWI-cpp.h>
#include<iostream>
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
	//letras usadas

	int *acertou;
}Jogo;

Estado estado;
Jogo jogo;
Palavra palavra;


void ligacao(void){
		char* argv[] = { "libswipl.dll", "-s", "forca.pl", NULL };

		PlEngine p(3, argv);
		PlTermv av(1);

		PlQuery query("gera_palavra", av);
		query.next_solution();
		palavra.pal = (char*)av[0];

		palavra.nletras = palavra.pal.length();
		palavra.p = palavra.pal.c_str();

		jogo.acertou = new int(palavra.nletras);
		for (int i = 0; i < palavra.nletras; i++){
			jogo.acertou[i] = 0;
		}

}

/* Inicialização do ambiente OPENGL */
void Init(void)
{

	

	jogo.nerros = 0;

	glClearColor(0.0, 0.0, 0.0, 0.0);

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
		if (jogo.acertou[i] == 1){
			glColor3f(1.0f, 0.0f, 0.3f);
			glRasterPos2f(posxi + 0.05f, -0.6f);

			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, palavra.p[i]);
			
		}
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


//função para conversão de strings em inteiros (atoi dava erro)
//http://www.kumobius.com/2013/08/c-string-to-int/
// Does this handle all the edge cases? Who knows...
// Better make sure you test it thoroughly if you write it yourself!
bool String2Int(const std::string& str, int& result)
{
	std::string::const_iterator i = str.begin();

	if (i == str.end())
		return false;

	bool negative = false;

	if (*i == '-')
	{
		negative = true;
		++i;

		if (i == str.end())
			return false;
	}

	result = 0;

	for (; i != str.end(); ++i)
	{
		if (*i < '0' || *i > '9')
			return false;

		result *= 10;
		result += *i - '0';
	}

	if (negative)
	{
		result = -result;
	}

	return true;
}

void existe(unsigned char key){
	printf("Letra -----  %c\n", jogo.letra);
		

	char* argv[] = { "libswipl.dll", "-s", "forca.pl", NULL };
	PlEngine p(3, argv);
	PlTermv av(3);
	//string palavraTemp = "\"" + palavra.pal + "\"";

	string palavraTemp = "\"ANGELA\"";
	av[0] = PlCompound(palavraTemp.c_str());

	string letra = "\"";
	letra += (char)key;
	letra +="\"";
	av[1] = PlCompound(letra.c_str());
	PlQuery query("comparacont", av);
	
	if (!query.next_solution()){
		palavra.nletras += 1;
	}else{
		string pos = (char*)av[2];
		int tamanho = pos.length();
		int *l = new int(tamanho);
		for (int i = 0; i < tamanho; i++){
			char s = pos.at(i);
			int index = (int)s;
			jogo.acertou[index-1] = 1;
		}
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
	
	existe(key);
	if (DEBUG)
		printf("Carregou na tecla %c\n", key);

}


int main(int argc, char **argv)
{

	ligacao();


	estado.doubleBuffer = GL_TRUE;

	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(((estado.doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE) | GLUT_RGB);
	if (glutCreateWindow("Exemplo") == GL_FALSE)
		exit(1);

	Init();

	//imprime_ajuda();

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