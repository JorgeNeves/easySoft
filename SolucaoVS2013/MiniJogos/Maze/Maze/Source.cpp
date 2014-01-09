#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <GL/glut.h>
#include<cctype>
#include<algorithm>
#include "MazeController.h"
#include <windows.h>
using namespace std;

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#define SIDE 300
#define MARGEM 5
#define MARGEM_META 50
#define RAIO 50
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

//typedef struct {
//	int       aX;
//	int       aY;
//	int       bX;
//	int       bY;
//}Liga;

typedef struct {
	int       mPosX;
	int     mPosY;
}Avatar;


MazeController controller;
Estado estado;
Maze **maze;
Modelo modelo;
Avatar avatar;
Avatar meta;
int mSize;
bool first;

//string convertInt(int number)
//{
//	stringstream ss;//create a stringstream
//	ss << number;//add number to the stream
//	return ss.str();//return a string with the contents of the stream
//}


//void ligacoes(int value)
//{
//	std::list<Liga> p;
//	for (int i = 0; i < mSize; i++)
//	{
//		for (int j = 0; j < mSize; j++)
//		{
//			if (i == 5 && j == 5)
//				printf("asdsa");
//			/*if (maze[i][j].north == 0){ Liga l; l.aX = i; l.aY = j; l.bX = i; l.bY =j - 1;  p.push_back(l); }
//			if (maze[i][j].south == 0){ Liga l; l.aX = i; l.aY = j; l.bX = i; l.bY = j + 1;  p.push_back(l); }
//			if (maze[i][j].east == 0) { Liga l; l.aX = i; l.aY = j; l.bX = i + 1; l.bY = j;  p.push_back(l); }
//			if (maze[i][j].west == 0) { Liga l; l.aX = i; l.aY = j; l.bX = i - 1; l.bY = j;  p.push_back(l); }*/
//			if (maze[i][j].north == 0){ Liga l; l.aX = j; l.aY = i; l.bX = j; l.bY = i - 1;  p.push_back(l); }
//			if (maze[i][j].south == 0){ Liga l; l.aX = j; l.aY = i; l.bX = j; l.bY = i + 1;  p.push_back(l); }
//			if (maze[i][j].east == 0) { Liga l; l.aX = j; l.aY = i; l.bX = j + 1; l.bY = i;  p.push_back(l); }
//			if (maze[i][j].west == 0) { Liga l; l.aX = j; l.aY = i; l.bX = j - 1; l.bY = i;  p.push_back(l); }
//
//		}
//	}
//
//	char* argv[] = { "libswipl.dll", "-s", "labirinto.pl", NULL };
//	PlEngine pEngine(3, argv);
//
//	ofstream myfile;
//	myfile.open("example.txt");
//	int i = 0;
//	while (!p.empty())
//	{
//		PlTermv av(1);
//		string arg1 = "(";
//		string arg2 = "(";
//		Liga x = p.front();
//		arg1 += convertInt(x.aX) + ",";
//		arg1 += convertInt(x.aY) + ")";
//		arg2 += convertInt(x.bX) + ",";
//		arg2 += convertInt(x.bY) + ")";
//		p.pop_front();
//		string ligacao = "liga(" + arg1 + "," + arg2 + ")";
//
//		av[0] = PlCompound(ligacao.c_str());
//		PlQuery query("asserta", av);
//		
//		if (query.next_solution()) myfile << ligacao << "." << endl;
//			i++;
//
//		PlTermv parm(2);
//		parm[0] = PlCompound(arg1.c_str());
//		PlQuery query2("liga", parm);
//		//cout << endl << endl;
//		while (query2.next_solution()){
//			cout << arg1 <<  " ---> ";
//			printf(parm[1]);
//			cout << " " << endl;
//		}
//
//	}
//	myfile.close();
//	PlTermv av23(2);
//	av23[0] = PlCompound("(0,1)");
//	PlQuery query2("liga", av23);
//	string f2;
//	query2.next_solution();
//	f2 += (char*)av23[1];
//
//	
//	
//	
//	//PlTermv sdf(3);
//
//}

string ReplaceString(std::string subject, const std::string& search,
	const std::string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

void resetAjuda(){
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize; j++)
		{
			if (maze[i][j].value == 5)
				maze[i][j].value = 0;
		}
	}
}

void AjudaMatriz(string list){
	
	list.erase(std::remove(list.begin(), list.end(), ' '), list.end());
	cout << endl << list << endl;
	list = ReplaceString(list, "),(", ";");
	list = ReplaceString(list, "[(", "");
	list = ReplaceString(list, ")]", "");
	cout << endl << list << endl;
	Reader r;
	vector<string> linha = r.explode(list, ';');
	for (int i = 1; i < linha.size()-1; i++){
		int x, y;
		string pos = linha.at(i);
		string subs1 = pos.substr(pos.find(',')+1);
		string subs2 = ReplaceString(pos, pos.substr(pos.find(',')), "");
		istringstream(subs1) >> x;
		//pos.substr(pos.find(','), pos.end)
		istringstream(subs2) >> y;
		maze[x][y].value = 5;
	}
}

/* Inicialização do ambiente OPENGL */
void Init(void)
{


	Reader r;
	mSize = r.getMazeSize("maze20.txt");
	maze = r.getMaze("maze20.txt");
	first = true;
	//controller = MazeController();
	controller.ligacoes(mSize, maze);
	//delay para o timer
	/*estado.delay = 1000;
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
	maze[30][30].value = 2;*/


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
	bool win = false;
	glFlush();
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < mSize; i++) {
		for (int j = 0; j < mSize; j++) {

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

				glVertex2f(SIDE * j + MARGEM_META, SIDE*i + MARGEM_META);
				glVertex2f(SIDE * j + MARGEM_META, SIDE*i + SIDE - MARGEM_META);
				glVertex2f(SIDE - MARGEM_META + SIDE * j, SIDE*i + SIDE - MARGEM_META);
				glVertex2f(SIDE - MARGEM_META + SIDE * j, SIDE*i + MARGEM_META);

				glEnd();
				glColor3f(1.0, 1.0, 1.0);
			}
			if (maze[i][j].value == 2){
				glColor3f(1.0, 0.2, 0.0);
				glBegin(GL_LINE_LOOP);

				glVertex2f(SIDE * j + MARGEM_META, SIDE*i + MARGEM_META);
				glVertex2f(SIDE * j + MARGEM_META, SIDE*i + SIDE - MARGEM_META);
				glVertex2f(SIDE - MARGEM_META + SIDE * j, SIDE*i + SIDE - MARGEM_META);
				glVertex2f(SIDE - MARGEM_META + SIDE * j, SIDE*i + MARGEM_META);

				glEnd();
				glColor3f(1.0, 1.0, 1.0);
				meta.mPosX = i; meta.mPosY = j;
			}
			if (maze[i][j].value == 5){
				glColor3f(1.0, 0.2, 4.0);
				glBegin(GL_LINE_LOOP);

				glVertex2f(SIDE * j + MARGEM_META, SIDE*i + MARGEM_META);
				glVertex2f(SIDE * j + MARGEM_META, SIDE*i + SIDE - MARGEM_META);
				glVertex2f(SIDE - MARGEM_META + SIDE * j, SIDE*i + SIDE - MARGEM_META);
				glVertex2f(SIDE - MARGEM_META + SIDE * j, SIDE*i + MARGEM_META);

				glEnd();
				glColor3f(1.0, 1.0, 1.0);
				meta.mPosX = i; meta.mPosY = j;
			}



			if (avatar.mPosX == i && avatar.mPosY == j){
				cout << "avatar:" << avatar.mPosY << "," << avatar.mPosX << endl;
				glColor3f(0.5, 0.0, 0.5);
				glBegin(GL_TRIANGLE_FAN);
				float x1 = SIDE*.35 + SIDE * j + RAIO;
				float y1 = SIDE*.6 + SIDE * i - RAIO;
				glVertex2f(x1, y1);

				for (int angle = 0; angle < 360; angle += 5){

					glVertex2f(x1 + sin(angle) * RAIO, y1 + cos(angle) * RAIO);

				}
				if (maze[i][j].value == 2) win = TRUE;
				glEnd();
				glColor3f(1.0, 1.0, 1.0);
				glFlush();
			}
		}
	}



	glFlush();
	if (estado.doubleBuffer)
		glutSwapBuffers();

	if (win){
		MessageBox(NULL, "YOU WIN!!", "Msg", MB_OK | MB_ICONERROR);
	}
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
	case 'H':{
				 resetAjuda();
				 glutPostRedisplay(); // redesenhar o ecrã
				 AjudaMatriz(controller.cam_curto(avatar.mPosY, avatar.mPosX, meta.mPosY, meta.mPosX));
				 glutPostRedisplay(); // redesenhar o ecrã
				 break; }
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
	case 'r':
		resetAjuda();
		glutPostRedisplay(); // redesenhar o ecrã
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