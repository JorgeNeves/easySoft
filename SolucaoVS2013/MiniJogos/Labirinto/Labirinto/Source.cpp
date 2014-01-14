#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include<iostream>
#include<cstdlib>
#include<stack>
#include<ctime>
#include<iostream>
#include<fstream>
#include<cctype>
#include<algorithm>
#include<vector>
#include <windows.h>
#include <tchar.h>

#include "MazeController.h"
using namespace std;

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#define _T(a)  L ## a
#define DEBUG 1

/* VARIAVEIS GLOBAIS */
typedef struct {
	GLboolean   doubleBuffer;
	GLint       delay;
}Estado;

typedef struct {
	int posX;
	int posY;
	int nrMoves;
}Avatar;

typedef struct {
	int posX;
	int posY;
}Meta;


#define NORTH   0
#define SOUTH   1
#define EAST    2
#define WEST    3
#define DIFICULTY 5
#define SIDE 300
#define MARGEM 5
#define MARGEM_META 50
#define RAIO 0.3

using namespace std;
int maze_size = 40;
Estado estado;
Avatar player;
Meta meta;
MazeController controler;
int nGood = 0;
int locX = 1, locY = 1;
char** grid;



void printGrid(/*char grid[maze_size][maze_size]*//*char** grid*/){
	system("cls");
	for (int i = 0; i < maze_size; i++){
		for (int j = 0; j < maze_size; j++){
			cout << grid[i][j];
		}
		cout << endl;
	}
}

int moveEW(int direction, int x){
	if (direction == EAST)
		return x + 1;
	else if (direction == WEST)
		return x - 1;
	else
		return x;
}

int moveNS(int direction, int y){
	if (direction == NORTH)
		return y - 1;
	else if (direction == SOUTH)
		return y + 1;
	else
		return y;
}

bool isGood(int x, int y, int direction /*, char grid[maze_size][maze_size]*//*, char** grid*/){
	x = moveEW(direction, x);
	y = moveNS(direction, y);

	if (grid[y][x] == ' ' || x >= (maze_size - 1) || x <= 0 || y <= 0 || y >= (maze_size - 1)){
		return false;
	}

	// check cardinal directions
	if (direction == NORTH){
		if (grid[y][x - 1] != ' ' &&  grid[y - 1][x] != ' ' && grid[y][x + 1] != ' ' &&  grid[y - 1][x - 1] != ' ' && grid[y - 1][x + 1] != ' '){
			return true;
		}
	}
	if (direction == SOUTH){
		if (grid[y][x - 1] != ' ' &&  grid[y + 1][x] != ' ' && grid[y][x + 1] != ' ' && grid[y + 1][x - 1] != ' ' && grid[y + 1][x + 1] != ' '){
			return true;
		}
	}
	if (direction == EAST){
		if (grid[y][x + 1] != ' ' &&  grid[y - 1][x] != ' ' && grid[y + 1][x] != ' ' && grid[y - 1][x + 1] != ' ' && grid[y + 1][x + 1] != ' '){
			return true;
		}
	}
	if (direction == WEST){
		if (grid[y][x - 1] != ' ' &&  grid[y - 1][x] != ' ' && grid[y + 1][x] != ' ' && grid[y - 1][x - 1] != ' ' && grid[y + 1][x - 1] != ' '){
			return true;
		}
	}
	return false;
}

void fillGrid(){
	//char grid[maze_size][maze_size];
	//char** grid;
	// init grid
	grid = new char*[maze_size];
	for (int i = 0; i < maze_size; i++){
		grid[i] = new char[maze_size];
		for (int j = 0; j < maze_size; j++){
			grid[i][j] = '#';
		}
	}

	//init rand
	srand(time(0));

	//init stacks for xy coords
	stack<int> xValues;
	stack<int> yValues;

	nGood = 0;
	int direction = 0;

	do{
		//find n good moves
		for (int i = 0; i < DIFICULTY; i++){
			if (isGood(locX, locY, i/*, grid*/))
				nGood++;
		}

		// if only 1 good move, move there
		if (nGood == 1){
			if (isGood(locX, locY, NORTH/*, grid*/))
				locY = moveNS(NORTH, locY);
			else if (isGood(locX, locY, SOUTH/*, grid*/))
				locY = moveNS(SOUTH, locY);
			else if (isGood(locX, locY, EAST/*, grid*/))
				locX = moveEW(EAST, locX);
			else if (isGood(locX, locY, WEST/*, grid*/))
				locX = moveEW(WEST, locX);
		}

		// if no good moves, move back in stack
		else if (nGood == 0){
			locX = xValues.top();
			locY = yValues.top();
			xValues.pop();
			yValues.pop();
		}

		//if more than 1 good move, push stack
		else if (nGood > 1){
			xValues.push(locX);
			yValues.push(locY);

			//direction to move randomly chosen
			do{
				direction = rand() % 4;
			} while (!isGood(locX, locY, direction/*, grid*/));

			locX = moveEW(direction, locX);
			locY = moveNS(direction, locY);
		}

		// set grid
		grid[locY][locX] = ' ';
		//output grid to show creation
		//printGrid(grid);
		//reset nGood value
		nGood = 0;

	} while (!xValues.empty());

	//return grid;
}

void criaLigacoes(){
	ofstream myfile;
	myfile.open("example.txt");
	for (int i = 0; i < maze_size; i++){
		for (int j = 0; j < maze_size; j++){
			if (grid[i][j] == ' ' && grid[i][j + 1] == ' '){
				myfile << "liga((" << i << "," << j << "),(" << i << "," << j + 1 << "))." << endl;
			}
			if (grid[i][j] == ' ' && grid[i + 1][j] == ' '){
				myfile << "liga((" << i << "," << j << "),(" << i + 1 << "," << j << "))." << endl;
			}
			if (grid[i][j] == ' ' && grid[i][j - 1] == ' '){
				myfile << "liga((" << i << "," << j << "),(" << i << "," << j - 1 << "))." << endl;
			}
			if (grid[i][j] == ' ' && grid[i - 1][j] == ' '){
				myfile << "liga((" << i << "," << j << "),(" << i - 1 << "," << j << "))." << endl;
			}
		}
	}
	myfile.close();
}

vector<string> explode(const string& str, const char& ch) {
	string next;
	vector<string> result;

	// For each character in the string
	for (string::const_iterator it = str.begin(); it != str.end(); it++) {
		// If we've hit the terminal character
		if (*it == ch) {
			// If we have some characters accumulated
			if (!next.empty()) {
				// Add them to the result vector
				result.push_back(next);
				next.clear();
			}
		}
		else {
			// Accumulate the next character into the sequence
			next += *it;
		}
	}
	if (!next.empty())
		result.push_back(next);
	return result;
}

string ReplaceString(std::string subject, const std::string& search, const std::string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

void AjudaMatriz(string list){

	list.erase(std::remove(list.begin(), list.end(), ' '), list.end());
	cout << endl << list << endl;
	list = ReplaceString(list, "),(", ";");
	list = ReplaceString(list, "[(", "");
	list = ReplaceString(list, ")]", "");
	cout << endl << list << endl;
	vector<string> linha = explode(list, ';');
	for (int i = 1; i < linha.size() - 1; i++){
		int x, y;
		string pos = linha.at(i);
		string subs1 = pos.substr(pos.find(',') + 1);
		string subs2 = ReplaceString(pos, pos.substr(pos.find(',')), "");
		istringstream(subs2) >> x;
		//pos.substr(pos.find(','), pos.end)
		istringstream(subs1) >> y;
		grid[x][y] = '*';
	}
}

void AjudaReset(){

	for (int i = 0; i < maze_size; i++){
		for (int j = 0; j < maze_size; j++){

			if (grid[i][j] == '*'){;
			grid[i][j] = ' ';
			}
		}
	}
}

/* Inicialização do ambiente OPENGL */
void Init(void)
{
	fillGrid();
	//criaLigacoes();
	controler.ligacoes(maze_size, grid);
	int* pos;
	pos = controler.makePos(grid, 'i', maze_size);
	player.posX = pos[0];
	player.posY = pos[1];
	player.nrMoves = 0;
	pos = controler.makePos(grid, 'f', maze_size);
	meta.posX = pos[0];
	meta.posY = pos[1];

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
	GLint maze_size;

	if (width < height)
		maze_size = width;
	else
		maze_size = height;

	// glViewport(botom, left, width, height)
	// define parte da janela a ser utilizada pelo OpenGL

	glViewport(0, 0, (GLint)maze_size, (GLint)maze_size);


	// Matriz Projecção
	// Matriz onde se define como o mundo e apresentado na janela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluOrtho2D(left,right,bottom,top); 
	// projecção ortogonal 2D, com profundidade (Z) entre -1 e 1
	gluOrtho2D(-5, 45, -5, 45);

	// Matriz Modelview
	// Matriz onde são realizadas as tranformacões dos modelos desenhados
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


// ... definicao das rotinas auxiliares de desenho ...

void desenhaQuadrado(int i, int j)
{
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
		glVertex2f(i,j);
		glVertex2f(i+1,j);
		glVertex2f(i+1,j+1);
		glVertex2f(i,j+1);
	glEnd();

	//linhas da esquerda
	glColor3f(1, 1, 1);
	glLineWidth(0.8);
	glBegin(GL_LINES);
		glVertex2f(i,j);
		glVertex2f(i,j+1);
	glEnd();

	//linhas da direita
	glColor3f(1, 1, 1);
	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i + 1, j);
	glVertex2f(i + 1, j + 1);
	glEnd();

	//linhas de cima
	glColor3f(1, 1, 1);
	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i, j);
	glVertex2f(i + 1, j);
	glEnd();

	//linhas de baixo
	glColor3f(1, 1, 1);
	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i, j + 1);
	glVertex2f(i + 1, j + 1);
	glEnd();
}

void desenhaInicio(int i, int j)
{
	/*glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(i, j);
	glVertex2f(i + 1, j);
	glVertex2f(i + 1, j + 1);
	glVertex2f(i, j + 1);
	glEnd();*/

	 
	//linhas da esquerda
	glColor3f(0, 0, 1);
	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i, j);
	glVertex2f(i, j + 1);
	glEnd();

	//linhas da direita

	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i + 1, j);
	glVertex2f(i + 1, j + 1);
	glEnd();

	//linhas de cima
	
	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i, j);
	glVertex2f(i + 1, j);
	glEnd();

	//linhas de baixo

	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i, j + 1);
	glVertex2f(i + 1, j + 1);
	glEnd();

	
}

void desenhaFim(int i, int j)
{
	/*glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(i, j);
	glVertex2f(i + 1, j);
	glVertex2f(i + 1, j + 1);
	glVertex2f(i, j + 1);
	glEnd();*/


	//linhas da esquerda
	glColor3f(1, 0, 0);
	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i, j);
	glVertex2f(i, j + 1);
	glEnd();

	//linhas da direita

	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i + 1, j);
	glVertex2f(i + 1, j + 1);
	glEnd();

	//linhas de cima

	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i, j);
	glVertex2f(i + 1, j);
	glEnd();

	//linhas de baixo

	glLineWidth(0.8);
	glBegin(GL_LINES);
	glVertex2f(i, j + 1);
	glVertex2f(i + 1, j + 1);
	glEnd();


}

void desenhaLabirinto(){
	for (int i = 0; i < maze_size; i++){
		for (int j = 0; j < maze_size; j++){

			if (grid[i][j] == '#'){

				desenhaQuadrado(i, j);

			}
		}
	}
}

void desenhaSpecialPos(){
	for (int i = 0; i < maze_size; i++){
		for (int j = 0; j < maze_size; j++){

			if (grid[i][j] == 'i'){

				desenhaInicio(i, j);

			}
			if (grid[i][j] == 'f'){

				desenhaFim(i, j);

			}
		}
	}
}

void desenhaSpecialAjuda(){
	for (int i = 0; i < maze_size; i++){
		for (int j = 0; j < maze_size; j++){

			if (grid[i][j] == '*'){

				glColor3f(0.2, 1.0, 0.2);
				glBegin(GL_TRIANGLE_FAN);
				float x1 = i + .5;
				float y1 = j + .5;
				glVertex2f(x1, y1);

				for (int angle = 0; angle < 360; angle += 5){

					glVertex2f(x1 + sin(angle) * RAIO*.5, y1 + cos(angle) * RAIO*.5);

				}
				glEnd();
			

			}
		}
	}
}

void desenhaAvatar(){
	glColor3f(0.5, 0.0, 0.5);
	glBegin(GL_TRIANGLE_FAN);
	float x1 = player.posX + .5;
	float y1 = player.posY + .5;
	glVertex2f(x1, y1);

	for (int angle = 0; angle < 360; angle += 5){

		glVertex2f(x1 + sin(angle) * RAIO, y1 + cos(angle) * RAIO);

	}
	glEnd();
}

void desenhaLetra(){
	string msg = "movimentos:" + controler.convertInt(player.nrMoves);
	float lpos = 1;
	for (int i = 0; i < msg.length(); i++){
		
			glColor3f(1.0f, 0.0f, 0.3f);
			glRasterPos2f(lpos, 41);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg.at(i));
			lpos += 1.5f;
	}

}


void winMsg(){
	glutPostRedisplay();
	if (player.posX == meta.posX && player.posY == meta.posY){
		MessageBox(NULL, _T("Chegaste a meta!!"), 
			_T("PARABÉNS!"), MB_OK | MB_ICONERROR);
	}
}

void move(int dir){
	switch (dir) {
		//Norte
		case 1:
			if (grid[player.posX][player.posY+1] != '#'){
				player.posY++;
				player.nrMoves++;
				glutPostRedisplay();
			}
			break;
		//sul
		case 2:
			if (grid[player.posX][player.posY-1] != '#'){
				player.posY--;
				player.nrMoves++;
				glutPostRedisplay();
			}
			break;
		//este
		case 3:
			if (grid[player.posX+1][player.posY] != '#'){
				   player.posX++;
				   player.nrMoves++;
				   glutPostRedisplay();
			}
			break;
		//oeste
		case 4:
			if (grid[player.posX-1][player.posY] != '#'){
				player.posX--;
				player.nrMoves++;
				glutPostRedisplay();
			}
			break;
	}
	cout << "player = " << player.posX << ", " << player.posY << endl;
}


void resetMaze(int size){
	maze_size = size;
	controler.retract();
	Init();
	glutPostRedisplay();
}

// Callback de desenho

void Draw(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	
	// ... chamada das rotinas auxiliares de desenho ...

	//desenhaQuadrado(0,0);

	desenhaLabirinto();
	desenhaSpecialPos();
	desenhaSpecialAjuda();	
	desenhaAvatar();
	desenhaLetra();	
	winMsg();

	glFlush();

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


void imprime_ajuda(void)
{
	printf("\n\nDesenho de um quadrado\n");
	printf("h,H - Ajuda \n");
	printf("r,R - Desligar Ajuda\n");
	printf("w,W - Mover para cima\n");
	printf("s,S - Mover para baixo\n");
	printf("a,A - Mover para esquerda\n");
	printf("d,D - Mover para direita\n");
	printf("1   - Labirinto 20x20\n");
	printf("2   - Labirinto 30x30\n");
	printf("3   - Labirinto 40x40\n");
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

	case 'h':
	case 'H':{
				 imprime_ajuda();
				 AjudaMatriz(controler.cam_curto(player.posX, player.posY, meta.posX, meta.posY));
				 glutPostRedisplay();
				 break;
	}
	case 'r':
	case 'R':{
				 AjudaReset();
				 glutPostRedisplay();
				 break;
	}
	case 'w':
	case 'W':
		move(1);
		break;
	case 's':
	case 'S':
		move(2);
		break;
	case 'd':
	case 'D':
		move(3);
		break;
	case 'a':
	case 'A':
		move(4);
		break;
	case '1':
		resetMaze(20);
		break;
	case '2':
		resetMaze(30);
		break;
	case '3':
		resetMaze(40);
		break;
	}
		if (DEBUG)
			printf("Carregou na tecla %c\n", key);
	

}

// Callback para interacção via teclado (largar a tecla)

/*void KeyUp(unsigned char key, int x, int y)
{

if(DEBUG)
printf("Largou a tecla %c\n",key);
}/*/

// Callback para interacção via teclas especiais  (carregar na tecla)

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

// Callback para interacção via teclas especiais (largar a tecla)

/*void SpecialKeyUp(int key, int x, int y)
{

if(DEBUG)
printf("Largou a tecla especial %d\n",key);

}/*/



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(((estado.doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE) | GLUT_RGB);
	if (glutCreateWindow("Labirinto") == GL_FALSE)
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

	return 0;
}