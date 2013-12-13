#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/glut.h>

#ifndef M_PI
#define M_PI 3.1415926
#endif



GLboolean doubleBuffer, rodar;
GLdouble tam, ang, dif;
GLint delay;
int max_x = 500;
int max_y = 500;
int *matriz[3];


void Init(void){
	for (int i = 0; i < 3; i++){
		matriz[i] = new int[3];
	}
	
	glClearColor(0.0, 0.0, 0.0, 0.0);   // define a cor para apagar a janela
	tam = (2.0 / 3.0);
}
void OnMouseClick(int button, int state, int x, int y)
{

	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int xx = max_x / 3;
		int xy = max_y / 3;
		//coluna 1		
		if (x < xx){
			//quadrado 1
			if (y< xy){
				matriz[0][0] = 1;
			}
			//quadrado 4
			else if (y >= xy && y <= xy * 2){
				
			}
			//quadrado 7
			else {
				
			}
		}
		//coluna 2
		else if (x >= xx  && x <= xx*2 ){
			//quadrado 2
			if (y< xy){
				
			}
			//quadrado 5
			else if (y >= xy && y <= xy * 2){
				
			}
			//quadrado 8
			else {
				
			}
		}
		//coluna 3
		else {
			//quadrado 3
			if (y< xy){
				
			}
			//quadrado 6
			else if (y >= xy && y <= xy * 2){
				
			}
			//quadrado 9
			else {
				
			}
		}
		glutPostRedisplay();
		
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

void Draw(void){

	glClear(GL_COLOR_BUFFER_BIT);
	//quadrado 1
	
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(-(tam / 2.0), (tam)+(tam / 2.0));
	glVertex2f(-((tam)+(tam) / 2.0), (tam)+(tam / 2.0));
	glVertex2f(-((tam)+(tam) / 2.0), (tam / 2.0));
	glVertex2f(-(tam / 2.0), (tam / 2.0));
	glEnd();
	//quadrado 2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f((tam) / 2.0, (tam / 2.0) + tam);
	glVertex2f(-(tam) / 2.0, (tam / 2.0) + tam);
	glVertex2f(-(tam) / 2.0, (tam) / 2.0);
	glVertex2f((tam) / 2.0, (tam) / 2.0);
	glEnd();
	//quadrado 3
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(((tam)+(tam) / 2.0), (tam)+(tam / 2.0));
	glVertex2f((tam) / 2.0, (tam)+(tam / 2.0));
	glVertex2f((tam) / 2.0, (tam / 2.0));
	glVertex2f(((tam)+(tam) / 2.0), (tam / 2.0));
	glEnd();
	//quadrado 4
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-(tam / 2.0), (tam) / 2.0);
	glVertex2f(-((tam)+(tam) / 2.0), (tam) / 2.0);
	glVertex2f(-((tam)+(tam) / 2.0), -(tam / 2.0));
	glVertex2f(-(tam / 2.0), -(tam / 2.0));
	glEnd();
	//quadrado 5
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f((tam) / 2.0, (tam) / 2.0);
	glVertex2f(-(tam) / 2.0, (tam) / 2.0);
	glVertex2f(-(tam) / 2.0, -(tam) / 2.0);
	glVertex2f((tam) / 2.0, -(tam) / 2.0);
	glEnd();
	//quadrado 6
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f((tam)+(tam / 2.0), (tam) / 2.0);
	glVertex2f((tam) / 2.0, (tam) / 2.0);
	glVertex2f((tam) / 2.0, -(tam / 2.0));
	glVertex2f((tam)+(tam / 2.0), -(tam / 2.0));
	glEnd();
	//quadrado 7
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(-(tam) / 2.0, -(tam / 2.0));
	glVertex2f(-(tam + (tam / 2.0)), -(tam / 2.0));
	glVertex2f(-(tam + (tam / 2.0)), -(tam + tam / 2.0));
	glVertex2f(-((tam) / 2.0), -(tam + tam / 2.0));
	glEnd();
	//quadrado 8
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f((tam) / 2.0, -(tam) / 2.0);
	glVertex2f(-(tam) / 2.0, -(tam) / 2.0);
	glVertex2f(-(tam) / 2.0, - (tam + tam/2.0));
	glVertex2f((tam) / 2.0, -(tam+tam / 2.0));
	glEnd();
	//quadrado 9
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(((tam)+(tam) / 2.0), -(tam / 2.0));
	glVertex2f((tam) / 2.0, -(tam / 2.0));
	glVertex2f((tam) / 2.0, -(tam+tam / 2.0));
	glVertex2f(((tam)+(tam) / 2.0), -(tam+tam / 2.0));
	glEnd();
	
	if (doubleBuffer) {
		glutSwapBuffers();
	}
	else {
		glFlush();
	}
	printf("Tam:%f Ang:%f\n", tam, ang);
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
	case '<':    // diminui
		if (tam >= 0.2) {
			tam -= 0.1;
			glutPostRedisplay();   // faz o redisplay da janela
		}
		break;
	case '>':    // aumenta
		if (tam <= 0.8) {
			tam += 0.1;
			glutPostRedisplay();   // faz o redisplay da janela
		}
		break;
	case 'R':    // inicia rotação
		rodar = GL_TRUE;
		glutTimerFunc(delay, Timer, 0);  // define um callback de tempo (delay ms)
		break;
	case 'r':    // termina rotação
		rodar = GL_FALSE;
		break;
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