#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/glut.h>
#include<Windows.h>
#include<SWI-cpp.h>
#include<iostream>
using namespace std;
#ifndef M_PI
#define M_PI 3.1415926
#endif



GLboolean doubleBuffer, rodar;
GLdouble tam, ang, dif;
GLint delay;
int max_x = 500;
int max_y = 500;

//estrutura para guardar as cores de cada quadrado do tabuleiro
typedef struct COLOR{
	float vermelho;
	float verde;
	float azul;
}color;

color *matriz[3];

void Init(void){
	//Inicia matriz tabuleiro (cor branca)
	for (int i = 0; i < 3; i++){
		matriz[i] = new color[3];
		for (int j = 0; j < 3; j++){
			matriz[i][j] = { 1.0, 1.0, 1.0 };
		}
		
	}

	glClearColor(0.0, 0.0, 0.0, 0.0);   // define a cor para apagar a janela
	tam = (2.0 / 3.0);
	glutPostRedisplay();
}
void Draw(void){

	glClear(GL_COLOR_BUFFER_BIT);
	//quadrado 1

	glBegin(GL_QUADS);

	glColor3f(matriz[0][0].vermelho, matriz[0][0].verde, matriz[0][0].azul);
	glVertex2f(-(tam / 2.0), (tam)+(tam / 2.0));
	glVertex2f(-((tam)+(tam) / 2.0), (tam)+(tam / 2.0));
	glVertex2f(-((tam)+(tam) / 2.0), (tam / 2.0));
	glVertex2f(-(tam / 2.0), (tam / 2.0));
	glEnd();
	//quadrado 2
	glBegin(GL_QUADS);

	glColor3f(matriz[1][0].vermelho, matriz[1][0].verde, matriz[1][0].azul);
	glVertex2f((tam) / 2.0, (tam / 2.0) + tam);
	glVertex2f(-(tam) / 2.0, (tam / 2.0) + tam);
	glVertex2f(-(tam) / 2.0, (tam) / 2.0);
	glVertex2f((tam) / 2.0, (tam) / 2.0);
	glEnd();
	//quadrado 3
	glBegin(GL_QUADS);
	glColor3f(matriz[2][0].vermelho, matriz[2][0].verde, matriz[2][0].azul);
	glVertex2f(((tam)+(tam) / 2.0), (tam)+(tam / 2.0));
	glVertex2f((tam) / 2.0, (tam)+(tam / 2.0));
	glVertex2f((tam) / 2.0, (tam / 2.0));
	glVertex2f(((tam)+(tam) / 2.0), (tam / 2.0));
	glEnd();
	//quadrado 4
	glBegin(GL_QUADS);

	glColor3f(matriz[0][1].vermelho, matriz[0][1].verde, matriz[0][1].azul);
	glVertex2f(-(tam / 2.0), (tam) / 2.0);
	glVertex2f(-((tam)+(tam) / 2.0), (tam) / 2.0);
	glVertex2f(-((tam)+(tam) / 2.0), -(tam / 2.0));
	glVertex2f(-(tam / 2.0), -(tam / 2.0));
	glEnd();
	//quadrado 5
	glBegin(GL_QUADS);

	glColor3f(matriz[1][1].vermelho, matriz[1][1].verde, matriz[1][1].azul);
	glVertex2f((tam) / 2.0, (tam) / 2.0);
	glVertex2f(-(tam) / 2.0, (tam) / 2.0);
	glVertex2f(-(tam) / 2.0, -(tam) / 2.0);
	glVertex2f((tam) / 2.0, -(tam) / 2.0);
	glEnd();
	//quadrado 6
	glBegin(GL_QUADS);

	glColor3f(matriz[2][1].vermelho, matriz[2][1].verde, matriz[2][1].azul);
	glVertex2f((tam)+(tam / 2.0), (tam) / 2.0);
	glVertex2f((tam) / 2.0, (tam) / 2.0);
	glVertex2f((tam) / 2.0, -(tam / 2.0));
	glVertex2f((tam)+(tam / 2.0), -(tam / 2.0));
	glEnd();
	//quadrado 7
	glBegin(GL_QUADS);

	glColor3f(matriz[0][2].vermelho, matriz[0][2].verde, matriz[0][2].azul);
	glVertex2f(-(tam) / 2.0, -(tam / 2.0));
	glVertex2f(-(tam + (tam / 2.0)), -(tam / 2.0));
	glVertex2f(-(tam + (tam / 2.0)), -(tam + tam / 2.0));
	glVertex2f(-((tam) / 2.0), -(tam + tam / 2.0));
	glEnd();
	//quadrado 8
	glBegin(GL_QUADS);

	glColor3f(matriz[1][2].vermelho, matriz[1][2].verde, matriz[1][2].azul);
	glVertex2f((tam) / 2.0, -(tam) / 2.0);
	glVertex2f(-(tam) / 2.0, -(tam) / 2.0);
	glVertex2f(-(tam) / 2.0, -(tam + tam / 2.0));
	glVertex2f((tam) / 2.0, -(tam + tam / 2.0));
	glEnd();
	//quadrado 9
	glBegin(GL_QUADS);

	glColor3f(matriz[2][2].vermelho, matriz[2][2].verde, matriz[2][2].azul);
	glVertex2f(((tam)+(tam) / 2.0), -(tam / 2.0));
	glVertex2f((tam) / 2.0, -(tam / 2.0));
	glVertex2f((tam) / 2.0, -(tam + tam / 2.0));
	glVertex2f(((tam)+(tam) / 2.0), -(tam + tam / 2.0));
	glEnd();

	//Linhas
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(tam / 2, (tam + tam / 2.0));
	glVertex2d(tam / 2, -(tam + tam / 2.0));
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(-tam / 2, (tam + tam / 2.0));
	glVertex2d(-tam / 2, -(tam + tam / 2.0));
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(-(tam + tam / 2.0), tam / 2);
	glVertex2d((tam + tam / 2.0), tam / 2);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(-(tam + tam / 2.0), -tam / 2);
	glVertex2d((tam + tam / 2.0), -tam / 2);
	glEnd();
	if (doubleBuffer) {
		glutSwapBuffers();
	}
	else {
		glFlush();
	}
	
}
/*
	Verifica se alguem ganhou
*/
bool checkWin(){
	int vitoriaazul=0;
	int vitoriavermelha=0;
	//verifica na vertical
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (matriz[i][j].verde != 1){
				if (matriz[i][j].azul == 1){
					vitoriaazul++;
				}
				else {
					vitoriavermelha++;
				}
			}
		}
		if (vitoriaazul < 3) vitoriaazul = 0;
		if (vitoriavermelha < 3) vitoriavermelha = 0;
	}
	//verifica na horizontal
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (matriz[j][i].verde != 1){
				if (matriz[j][i].azul == 1){
					vitoriaazul++;
				}
				else if (matriz[j][i].vermelho == 1){
					vitoriavermelha++;
				}
			}
		}
		if (vitoriaazul < 3) vitoriaazul = 0;
		if (vitoriavermelha < 3) vitoriavermelha = 0;
	}
	//verifica na diagonal
	for (int i = 0; i < 3; i++){
		if (matriz[i][i].verde != 1){
			if (matriz[i][i].azul == 1){
				vitoriaazul++;
			}
			else {
				vitoriavermelha++;
			}
		}
		if (i == 2){
			if (vitoriaazul < 3) vitoriaazul = 0;
			if (vitoriavermelha < 3) vitoriavermelha = 0;
		}
	}
	
	
		if (matriz[2][0].verde != 1){
			if (matriz[2][0].azul == 1){
				vitoriaazul++;
			}
			else {
				vitoriavermelha++;
			}
		}
		if (matriz[1][1].verde != 1){
			if (matriz[1][1].azul == 1){
				vitoriaazul++;
			}
			else {
				vitoriavermelha++;
			}
		}
		if (matriz[0][2].verde != 1){
			if (matriz[0][2].azul == 1){
				vitoriaazul++;
			}
			else {
				vitoriavermelha++;
			}
		}

	//verifica se o tabuleiro está cheio
	bool full=true;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (matriz[i][j].verde == 1){
				full = false;
			}
		}
	}

	if (vitoriaazul >= 3 && vitoriavermelha < 3){
		Draw();
		MessageBox(NULL, "YOU WON! Level UP!", "Info", MB_ICONINFORMATION);
		exit(0);
		
	}
	if (vitoriavermelha >= 3){
		Draw();
		MessageBox(NULL, "YOU LOSE! Try Again!", "Info",
			MB_ICONINFORMATION);
		
		return true;
	}
	else if(full){
		Draw();
		MessageBox(NULL, "DRAW!", "Info",
			MB_ICONINFORMATION);
		return true;
	}
	return false;

}
//Jogada aleatoria do computador (gerada pelo prolog)
void JogadaPC(){

	if (checkWin()){
		Init();
		Draw();
		return;
	}

	char* argv[] = { "libswipl.dll", "-s", "galo.pl", NULL };
	PlEngine p(3,argv);
	PlTermv av(2);
	string tabuleiro="[";
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (matriz[j][i].verde != 1){
				if (matriz[j][i].azul == 1){
					tabuleiro += "x,";
				}
				else {
					tabuleiro += "o,";
				}
			}
			else {
				tabuleiro += "A,";
			}
		}
	}
	
	tabuleiro = tabuleiro.substr(0, tabuleiro.size() - 1);
	tabuleiro += "]";
	
	av[0] = PlCompound(tabuleiro.c_str());
	PlQuery query("proxima_jogada", av);
	int posicao;
	if (query.next_solution()){
		
		posicao = atoi((char*)av[1]);
	}
	
	if (posicao == 1){
		matriz[0][0] = { 1.0, 0.0, 0.0 };
	}
	else if (posicao == 2){
		matriz[1][0] = { 1.0, 0.0, 0.0 };
	}
	else if (posicao == 3){
		matriz[2][0] = { 1.0, 0.0, 0.0 };
	}
	else if (posicao == 4){
		matriz[0][1] = { 1.0, 0.0, 0.0 };
	}
	else if (posicao == 5){
		matriz[1][1] = { 1.0, 0.0, 0.0 };
	}
	else if (posicao == 6){
		matriz[2][1] = { 1.0, 0.0, 0.0 };
	}
	else if (posicao == 7){
		matriz[0][2] = { 1.0, 0.0, 0.0 };
	}
	else if (posicao == 8){
		matriz[1][2] = { 1.0, 0.0, 0.0 };
	}
	else if (posicao == 9){
		matriz[2][2] = { 1.0, 0.0, 0.0 };
	}
	
	if (checkWin()){
		Init();
		Draw();
		return;
	}
	
	
}
void OnMouseClick(int button, int state, int x, int y)
{

	int i = 0;
	//quando é feito um click sobre um quadrado
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int xx = max_x / 3;
		int xy = max_y / 3;
		//coluna 1		
		if (x < xx){
			//quadrado 1
			if (y < xy && matriz[0][0].verde==1.0){
				matriz[0][0] = { 0.0, 0.0, 1.0 };
				i = 1;
				
			}
			//quadrado 4
			else if (y >= xy && y <= xy * 2 && matriz[0][1].verde == 1.0){
				
				matriz[0][1] = { 0.0, 0.0, 1.0 };
				i = 1;
			}
			//quadrado 7
			else if (y >= xy*2 && matriz[0][2].verde == 1.0){
				
				matriz[0][2] = { 0.0, 0.0, 1.0 };
				i = 1;
			}
		}
		//coluna 2
		else if (x >= xx  && x <= xx*2 ){
			//quadrado 2
			if (y< xy && matriz[1][0].verde == 1.0){
				matriz[1][0] = { 0.0, 0.0, 1.0 };
				i = 1;
			}
			//quadrado 5
			else if (y >= xy && y <= xy * 2 && matriz[1][1].verde == 1.0){
				matriz[1][1] = { 0.0, 0.0, 1.0 };
				i = 1;
			}
			//quadrado 8
			else if (y >= xy * 2 && matriz[1][2].verde == 1.0) {
				matriz[1][2] = { 0.0, 0.0, 1.0 };
				i = 1;
			}
		}
		//coluna 3
		else if (x > xx*2){
			//quadrado 3
			if (y< xy && matriz[2][0].verde == 1.0){
				matriz[2][0] = { 0.0, 0.0, 1.0 };
				i = 1;
			}
			//quadrado 6
			else if (y >= xy && y <= xy * 2 && matriz[2][1].verde == 1.0){
				matriz[2][1] = { 0.0, 0.0, 1.0 };
				i = 1;
			}
			//quadrado 9
			else if (y >= xy * 2 && matriz[2][2].verde == 1.0){
				matriz[2][2] = { 0.0, 0.0, 1.0 };
				i = 1;
			}
		}
		if (i == 1){
			glutPostRedisplay();
			JogadaPC();
			Draw();
		}
	}
}


void Reshape(int width, int height){
	width = max_x;
	height = max_y;
	glViewport(0, 0, width, height);  // define o viewport como sendo a janela toda
	glutPositionWindow(glutGet(GLUT_SCREEN_WIDTH)/3, glutGet(GLUT_SCREEN_HEIGHT)/4);
	glMatrixMode(GL_PROJECTION);   // faz operações sobre a matriz GL_PROJECTION
	glLoadIdentity();
	gluOrtho2D(-1,1,-1,1);       // define as coordenada relativas do viewport
	// esq, dir, baixo, cima
	glMatrixMode(GL_MODELVIEW);    // faz operações sobre a matriz GL_MODELVIEW
	glLoadIdentity();
	glutMouseFunc(OnMouseClick);
	glutReshapeWindow(500, 500);

}




void Timer(int valor) {

	ang += dif;   // faz o incremento ao angulo de rotação

	if (ang>2 * M_PI) {  // se passou de 2*M_PI subtrai 2*M_PI
		ang = ang - 2 * M_PI;
	}

	glutPostRedisplay();  // redesenha o ecran

	if (rodar) glutTimerFunc(delay, Timer, 0);  // se ainda é para rodar redefine o callback
}
void Key(unsigned char key, int x, int y){

	switch (key) {
	case 27:   // Se é escape sai
		exit(0);
	}
}

int Args(int argc, char **argv){

	GLint i;

	doubleBuffer = GL_FALSE;  // define o doubleBuffer como falso
	tam = .5;        // tamanho inicial do quadrado
	ang = 0;         // angulo inicial
	dif = M_PI / 16;   // incremento da rotação
	delay = 250;     // intervalo de animação

	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-sb") == 0) {
			doubleBuffer = GL_FALSE;
		}
		else if (strcmp(argv[i], "-db") == 0) {
			doubleBuffer = GL_TRUE;
		}
		else if (strncmp(argv[i], "-dif", 4) == 0) {
			dif = atof(&argv[i][4]);
			if (dif > 2 * M_PI)
				dif = M_PI / 16;
		}
		else if (strncmp(argv[i], "-del", 4) == 0) {
			dif = atof(&argv[i][4]);
			if (delay < 10)
				delay = 10;
		}
		else {
			printf("%s (Bad option).\n", argv[i]);
			return GL_FALSE;
		}
	}
	return GL_TRUE;
}

int main(int argc, char **argv){

	GLenum type;

	glutInit(&argc, argv);   // Inicializa o GLUT

	// chama a função para processar os argumentos
	if (Args(argc, argv) == GL_FALSE)
		exit(1);

	type = GLUT_RGB | GLUT_ACCUM;  // define as opções GLUT_RGB e GLUT_ACCUM
	// se doubleBuffer for verdadeiro define GLUT_DOUBLE  senão define GLUT_SINGLE
	type |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;
	glutInitDisplayMode(type);	    // Inicializa o modo do display
	glutInitWindowSize(500, 500);   // cria uma janela 300x300 pixeis
	glutCreateWindow("Teste");      // nome da janela pode passar argv[0]

	Init();	// chama a função Init para inicialização do OpenGL

	glutReshapeFunc(Reshape);   // Regista o callback Reshape
	glutKeyboardFunc(Key);      // Regista o callback Keyboard
	glutDisplayFunc(Draw);      // Regista o callback Display

	glutMainLoop();		// Inicia o ciclo de execução do GLUT
}