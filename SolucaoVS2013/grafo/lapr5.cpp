#include"lapr5.h"

void initEstado(){
	estado.camera.dir_lat=-M_PI/4;
	estado.camera.dir_long=M_PI/4+ M_PI;
	estado.camera.fov=60;
	estado.camera.dist=2;
	estado.eixo[0]=0;
	estado.eixo[1]=0;
	estado.eixo[2]=0;
	estado.camera.eyeVer[0]=100;
	estado.camera.eyeVer[1]=100;
	estado.camera.eyeVer[2]=100;
	estado.camera.dim = 1;
	estado.camera.velh = 50;
	estado.camera.velv = 25;
	estado.light=GL_FALSE;
	estado.apresentaNormais=GL_FALSE;
	estado.lightViewer=1;
	estado.delayMovimento = 500;
}

void initModelo(){
	modelo.escala=0.2;

	modelo.cor_cubo = brass;
	modelo.g_pos_luz1[0]=-5.0;
	modelo.g_pos_luz1[1]= 5.0;
	modelo.g_pos_luz1[2]= 5.0;
	modelo.g_pos_luz1[3]= 0.0;
	modelo.g_pos_luz2[0]= 5.0;
	modelo.g_pos_luz2[1]= -15.0;
	modelo.g_pos_luz2[2]= 5.0;
	modelo.g_pos_luz2[3]= 0.0;
}

void myInit()
{

	GLfloat LuzAmbiente[]={0.5,0.5,0.5, 0.0};

	glClearColor (0.0, 0.0, 0.0, 0.0);

	glEnable(GL_SMOOTH); /*enable smooth shading */
	glEnable(GL_LIGHTING); /* enable lighting */
	glEnable(GL_DEPTH_TEST); /* enable z buffer */
	glEnable(GL_NORMALIZE);

	glDepthFunc(GL_LESS);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LuzAmbiente); 
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, estado.lightViewer); 
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); 

	initModelo();
	initEstado();
	modelo.quad=gluNewQuadric();
	gluQuadricDrawStyle(modelo.quad, GLU_FILL);
	gluQuadricNormals(modelo.quad, GLU_OUTSIDE);

	leGrafo();
}

void imprime_ajuda(void)
{
  printf("\n\nDesenho de um labirinto a partir de um grafo\n");
  printf("h,H - Ajuda \n");
  printf("i,I - Reset dos Valores \n");
  printf("******* Diversos ******* \n");
  printf("l,L - Alterna o calculo luz entre Z e eye (GL_LIGHT_MODEL_LOCAL_VIEWER)\n");
  printf("k,K - Alerna luz de camera com luz global \n");
  printf("s,S - PolygonMode Fill \n");
  printf("w,W - PolygonMode Wireframe \n");
  printf("p,P - PolygonMode Point \n");
  printf("c,C - Liga/Desliga Cull Face \n");
  printf("n,N - Liga/Desliga apresentação das normais \n");
  printf("1 - Jogo do Galo \n");
  printf("2 - Jogo da Forca \n");
  printf("3 - Jogo do Labirinto \n");
  printf("******* grafos ******* \n");
  printf("F1  - Grava grafo do ficheiro \n");
  printf("F2  - Lê grafo para ficheiro \n");
  printf("F6  - Cria novo grafo\n");
  printf("******* Camera ******* \n");
  printf("Botão esquerdo - Arrastar os eixos (centro da camera)\n");
  printf("Botão direito  - Rodar camera\n");
  printf("Botão direito com CTRL - Zoom-in/out\n");
  printf("PAGE_UP, PAGE_DOWN - Altera distância da camara \n");
  printf("ESC - Sair\n");
}

void material(enum tipo_material mat)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient[mat]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse[mat]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular[mat]);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess[mat]);
}

const GLfloat red_light[] = {1.0, 0.0, 0.0, 1.0};
const GLfloat green_light[] = {0.0, 1.0, 0.0, 1.0};
const GLfloat blue_light[] = {0.0, 0.0, 1.0, 1.0};
const GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};


void putLights(GLfloat* diffuse)
{
	const GLfloat white_amb[] = {0.2, 0.2, 0.2, 1.0};

	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white_amb);
	glLightfv(GL_LIGHT0, GL_POSITION, modelo.g_pos_luz1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
	glLightfv(GL_LIGHT1, GL_AMBIENT, white_amb);
	glLightfv(GL_LIGHT1, GL_POSITION, modelo.g_pos_luz2);

	/* desenhar luz */
	//material(red_plastic);
	//glPushMatrix();
	//	glTranslatef(modelo.g_pos_luz1[0], modelo.g_pos_luz1[1], modelo.g_pos_luz1[2]);
	//	glDisable(GL_LIGHTING);
	//	glColor3f(1.0, 1.0, 1.0);
	//	glutSolidCube(0.1);
	//	glEnable(GL_LIGHTING);
	//glPopMatrix();
	//glPushMatrix();
	//	glTranslatef(modelo.g_pos_luz2[0], modelo.g_pos_luz2[1], modelo.g_pos_luz2[2]);
	//	glDisable(GL_LIGHTING);
	//	glColor3f(1.0, 1.0, 1.0);
	//	glutSolidCube(0.1);
	//	glEnable(GL_LIGHTING);
	//glPopMatrix();

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}

void desenhaSolo(){
#define STEP 10
	glBegin(GL_QUADS);
		glNormal3f(0,0,1);
		for(int i=-300;i<300;i+=STEP)
			for(int j=-300;j<300;j+=STEP){
				glVertex2f(i,j);
				glVertex2f(i+STEP,j);
				glVertex2f(i+STEP,j+STEP);
				glVertex2f(i,j+STEP);
			}
	glEnd();
}

void desenhaNo(int n){

	No *no = &nos[n];
	glPushMatrix();
	if (n == 0){ material(azul); }
	else { material(red_plastic); }
	glTranslatef(no->x, no->y, no->z + 0.25);
	glutSolidSphere(2.0, 10, 10);
	glPopMatrix();
}

void desenhaArco(Arco arco){
	glPushMatrix();
	material(emerald);

	float xi = nos[arco.noi].x;
	float yi = nos[arco.noi].y;
	float zi = nos[arco.noi].z;

	float xj = nos[arco.nof].x;
	float yj = nos[arco.nof].y;
	float zj = nos[arco.nof].z;

	float oxyproj = sqrt(pow((xj - xi), 2) + pow((yj - yi), 2));
	float delevel = zj - zi;

	float beta = atan2(delevel, oxyproj);
	float alpha = atan2((yj - yi), (xj - xi));

	glTranslatef(xi, yi, zi);
	glRotatef(graus(alpha), 0, 0, 1);
	glRotatef(graus((M_PI / 2.0) - beta), 0, 1, 0);

	float length = sqrt(pow(oxyproj, 2) + pow(delevel, 2));

	GLUquadricObj* quadric = gluNewQuadric();
	gluCylinder(quadric, arco.peso, arco.peso, length, 10, 10);
	glPopMatrix();
}

void desenhaLabirinto(){
	glPushMatrix();
		glTranslatef(0,0,0.05);
		glScalef(5,5,5);
		material(red_plastic);
		for(int i=0; i<numNos; i++){
			glPushName(i+1);
			desenhaNo(i);
			glPopName();
		}
		material(emerald);
		for (int i = 0; i < numArcos; i++)
		{
			glPushName(1001 + i);
			desenhaArco(arcos[i]);
			glPopName();
		}
	glPopMatrix();
}

void desenhaEixo(){
	gluCylinder(modelo.quad,0.5,0.5,20,16,15);
	glPushMatrix();
		glTranslatef(0,0,20);
		glPushMatrix();
			glRotatef(180,0,1,0);
			gluDisk(modelo.quad,0.5,2,16,6);
		glPopMatrix();
		gluCylinder(modelo.quad,2,0,5,16,15);
	glPopMatrix();
}

#define EIXO_X		100
#define EIXO_Y		200
#define EIXO_Z		300

void desenhaEixos(){

	glPushMatrix();
		glTranslated(estado.eixo[0],estado.eixo[1],estado.eixo[2]);
		material(emerald);
		glPushName(EIXO_Z);
			desenhaEixo();
		glPopName();
		glPushName(EIXO_Y);
			glPushMatrix();
				glRotatef(-90,1,0,0);
				material(red_plastic);
				desenhaEixo();
			glPopMatrix();
		glPopName();
		glPushName(EIXO_X);
			glPushMatrix();
				glRotatef(90,0,1,0);
				material(azul);
				desenhaEixo();
			glPopMatrix();
		glPopName();
	glPopMatrix();
}

void setCamera(){
	estado.camera.center[0] = estado.camera.eyeVer[0] + estado.camera.dist*cos(estado.camera.dir_long)*cos(estado.camera.dir_lat);
	estado.camera.center[1] = estado.camera.eyeVer[1] + estado.camera.dist*sin(estado.camera.dir_long)*cos(estado.camera.dir_lat);
	estado.camera.center[2] = estado.camera.eyeVer[2] + estado.camera.dist*sin(estado.camera.dir_lat);

	if (estado.light){
		gluLookAt(estado.camera.eyeVer[0], estado.camera.eyeVer[1], estado.camera.eyeVer[2], estado.camera.center[0], estado.camera.center[1], estado.camera.center[2], 0, 0, 1);
		putLights((GLfloat*)white_light);
	}
	else{
		putLights((GLfloat*)white_light);
		gluLookAt(estado.camera.eyeVer[0], estado.camera.eyeVer[1], estado.camera.eyeVer[2], estado.camera.center[0], estado.camera.center[1], estado.camera.center[2], 0, 0, 1);
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	setCamera();

	/*material(slate);
	glPushMatrix();
	glTranslated(0, 0, -40);
	desenhaSolo();
	glPopMatrix();*/
		
	//desenhaEixos();
	
	desenhaLabirinto();
 
	if(estado.eixoTranslaccao) {
		cout << "Translate... " << estado.eixoTranslaccao << endl; 

	}

	glFlush();
	glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y)
{
	int retCode;
    switch (key)
    {
		case 27 :
				exit(0);
			break;
		case 'h':
		case 'H':
				imprime_ajuda();
			break;
		case 'l':
		case 'L':
				if(estado.lightViewer)
					estado.lightViewer=0;
				else
					estado.lightViewer=1;
				glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, estado.lightViewer);
				glutPostRedisplay();
			break;
		case 'k':
		case 'K':
				estado.light=!estado.light;
				glutPostRedisplay();
			break;
		case 'w':
		case 'W':
				glDisable(GL_LIGHTING);
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				glutPostRedisplay();
			break;
		case 'p':
		case 'P':
				glDisable(GL_LIGHTING);
				glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
				glutPostRedisplay();
			break;
		case 's':
		case 'S':
				glEnable(GL_LIGHTING);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glutPostRedisplay();
			break;
		case 'c':
		case 'C':
				if(glIsEnabled(GL_CULL_FACE))
					glDisable(GL_CULL_FACE);
				else
					glEnable(GL_CULL_FACE);
				glutPostRedisplay();
			break;    
		case 'n':
		case 'N':
				estado.apresentaNormais=!estado.apresentaNormais;
				glutPostRedisplay();
			break;    		
		case 'i':
		case 'I':
				initEstado();
				initModelo();
				glutPostRedisplay();
				break;
		case 'q':
		case 'Q':
			cout << key << endl;
			estado.camera.eyeVer[2] += 1;
			glutPostRedisplay();
			break;
		case 'a':
		case 'A':
			cout << key << endl;
			estado.camera.eyeVer[2] -= 1;
			glutPostRedisplay();
			break;
		case '1':
			retCode = system("Mini_Jogos\\Jogo_do_Galo\\TestJogoGalo.exe");
			if (retCode == 1)
			{
				MessageBox(NULL, _T("Ganhou o jogo do galo!"),
					_T("Resultado"), MB_OK | MB_ICONMASK);
			}
			else 
			{
				MessageBox(NULL, _T("Perdeu!"),
					_T("Resultado"), MB_OK | MB_ICONERROR);
			}
			break;
		case '2':
			retCode = system("Mini_Jogos\\Jogo_da_Forca\\Forca.exe");
			if (retCode == 1)
			{
				MessageBox(NULL, _T("Ganhou o jogo da forca!"),
					_T("Resultado"), MB_OK | MB_ICONMASK);
			}
			else
			{
				MessageBox(NULL, _T("Perdeu!"),
					_T("Resultado"), MB_OK | MB_ICONERROR);
			}
			break;
		case '3':
			retCode = system("Mini_Jogos\\Jogo_do_Labirinto\\Labirinto.exe");
			if (retCode == 1)
			{
				MessageBox(NULL, _T("Ganhou o jogo do labirinto!"),
					_T("Resultado"), MB_OK | MB_ICONMASK);
			}
			else
			{
				MessageBox(NULL, _T("Perdeu!"),
					_T("Resultado"), MB_OK | MB_ICONERROR);
			}
			break;
	}
}

void Special(int key, int x, int y){

	switch(key){
		case GLUT_KEY_F1 :
				gravaGrafo();
			break;
		case GLUT_KEY_F2 :
				leGrafo();
				glutPostRedisplay();
			break;	

		case GLUT_KEY_F6 :
				numNos=numArcos=0;
				addNo(criaNo( 0, 10,0));  // 0
				addNo(criaNo( 0,  5,0));  // 1
				addNo(criaNo(-5,  5,0));  // 2
				addNo(criaNo( 5,  5,0));  // 3
				addNo(criaNo(-5,  0,0));  // 4
				addNo(criaNo( 5,  0,0));  // 5
				addNo(criaNo(-5, -5,0));  // 6
				addArco(criaArco(0,1,1,1));  // 0 - 1
				addArco(criaArco(1,2,1,1));  // 1 - 2
				addArco(criaArco(1,3,1,1));  // 1 - 3
				addArco(criaArco(2,4,1,1));  // 2 - 4
				addArco(criaArco(3,5,1,1));  // 3 - 5
				addArco(criaArco(4,5,1,1));  // 4 - 5
				addArco(criaArco(4,6,1,1));  // 4 - 6
				glutPostRedisplay();
			break;	
		case GLUT_KEY_UP:
				estado.camera.eyeVer[0] += 1 * cos(estado.camera.dir_long)*cos(estado.camera.dir_lat);
				estado.camera.eyeVer[1] += 1 * sin(estado.camera.dir_long)*cos(estado.camera.dir_lat);
				estado.camera.eyeVer[2] += 1 * sin(estado.camera.dir_lat);
				glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
				estado.camera.eyeVer[0] -= 1 * cos(estado.camera.dir_long)*cos(estado.camera.dir_lat);
				estado.camera.eyeVer[1] -= 1 * sin(estado.camera.dir_long)*cos(estado.camera.dir_lat);
				estado.camera.eyeVer[2] -= 1 * sin(estado.camera.dir_lat);
				glutPostRedisplay();
			break;
		/*case GLUT_KEY_LEFT :
				estado.camera.eyeVer[1] -= 1 * cos(estado.camera.dir_long)*cos(estado.camera.dir_lat);
				estado.camera.eyeVer[0] -= 1 * sin(estado.camera.dir_long)*cos(estado.camera.dir_lat);
				glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
				estado.camera.eyeVer[1] += 1 * cos(estado.camera.dir_long)*cos(estado.camera.dir_lat);
				estado.camera.eyeVer[0] += 1 * sin(estado.camera.dir_long)*cos(estado.camera.dir_lat);
				glutPostRedisplay();
				*/
			break;
	}
}

void setProjection(int x, int y, GLboolean picking){
    glLoadIdentity();
	if (picking) { // se está no modo picking, lê viewport e define zona de picking
		GLint vport[4];
		glGetIntegerv(GL_VIEWPORT, vport);
		gluPickMatrix(x, glutGet(GLUT_WINDOW_HEIGHT)  - y, 4, 4, vport); // Inverte o y do rato para corresponder à jana
	}
	    
	gluPerspective(estado.camera.fov,(GLfloat)glutGet(GLUT_WINDOW_WIDTH) /glutGet(GLUT_WINDOW_HEIGHT) ,1,500);

}

void myReshape(int w, int h){	
	glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
	setProjection(0,0,GL_FALSE);
	glMatrixMode(GL_MODELVIEW);
}

void motionRotate(int x, int y){
#define DRAG_SCALE	0.01
	double lim=M_PI/2-0.1;
	estado.camera.dir_long+=(estado.xMouse-x)*DRAG_SCALE;
	estado.camera.dir_lat-=(estado.yMouse-y)*DRAG_SCALE*0.5;
	if(estado.camera.dir_lat>lim)
		estado.camera.dir_lat=lim;
	else 
		if(estado.camera.dir_lat<-lim)
			estado.camera.dir_lat=-lim;
	estado.xMouse=x;
	estado.yMouse=y;
	glutPostRedisplay();
}

void motionZoom(int x, int y){
#define ZOOM_SCALE	0.5
	estado.camera.dist-=(estado.yMouse-y)*ZOOM_SCALE;
	cout << estado.camera.dist << endl;
	if(estado.camera.dist<5)
		estado.camera.dist=5;
	else 
		if(estado.camera.dist>200)
			estado.camera.dist=200;
	estado.yMouse=y;
	glutPostRedisplay();
}

int picking(int x, int y){
	int i, n, objid=0;
	double zmin = 10.0;
	GLuint buffer[100], *ptr;

	glSelectBuffer(100, buffer);
	glRenderMode(GL_SELECT);
	glInitNames();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); // guarda a projecção
		glLoadIdentity();
		setProjection(x,y,GL_TRUE);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setCamera();
	//desenhaEixos();
	desenhaLabirinto();
	
	n = glRenderMode(GL_RENDER);
	if (n > 0)
	{
		ptr = buffer;
		for (i = 0; i < n; i++)
		{
			if (zmin > (double) ptr[1] / UINT_MAX) {
				zmin = (double) ptr[1] / UINT_MAX;
				objid = ptr[3];
			}
			ptr += 3 + ptr[0]; // ptr[0] contem o número de nomes (normalmente 1); 3 corresponde a numnomes, zmin e zmax
		}
	}


	glMatrixMode(GL_PROJECTION); //repõe matriz projecção
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	return objid;
}

int detectCollision(GLfloat xp, GLfloat yp, GLfloat zp){
	int i, n, objid = 0;
	double zmin = 10.0;
	GLuint buffer[100], *ptr;

	glSelectBuffer(100, buffer);
	glRenderMode(GL_SELECT);
	glInitNames();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); // guarda a projecção
	glLoadIdentity();
	//setCamera();
	
	glOrtho(-estado.camera.dim / 2.0, estado.camera.dim / 2.0, 
		-estado.camera.dim / 2.0, estado.camera.dim / 2.0, 
		0.0, estado.camera.dim / 2.0 + (estado.camera.velv + estado.camera.velh));
	//setProjection(x, y, GL_TRUE);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glRotated(-M_PI/2.0 - atan2(estado.camera.velv,estado.camera.velh),1,0,0);
	glRotated(M_PI/2.0 - estado.camera.dir_lat,0,0,1);
	glTranslated(-xp,-yp,-zp);
	
	//desenhaEixos();
	desenhaLabirinto();

	n = glRenderMode(GL_RENDER);
	if (n > 0)
	{
		ptr = buffer;
		for (i = 0; i < n; i++)
		{
			if (zmin >(double) ptr[1] / UINT_MAX) {
				zmin = (double)ptr[1] / UINT_MAX;
				objid = ptr[3];
			}
			ptr += 3 + ptr[0]; // ptr[0] contem o número de nomes (normalmente 1); 3 corresponde a numnomes, zmin e zmax
		}
	}


	glMatrixMode(GL_PROJECTION); //repõe matriz projecção
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	return objid;
}

void mouse(int btn, int state, int x, int y){
	switch(btn) {
		case GLUT_RIGHT_BUTTON :
					if(state == GLUT_DOWN){
						estado.xMouse=x;
						estado.yMouse=y;
						/*
						if(glutGetModifiers() & GLUT_ACTIVE_CTRL)
							glutMotionFunc(motionZoom);
						else*/
							glutMotionFunc(motionRotate);
						
						cout << "Left down\n";
					}
					else{
						glutMotionFunc(NULL);
						cout << "Left up\n";
					}
				break;
		case GLUT_LEFT_BUTTON :
					if(state == GLUT_DOWN){
						estado.eixoTranslaccao=picking(x,y);
						/*if(estado.eixoTranslaccao)
							glutMotionFunc(motionDrag);*/
						cout << "Right down - objecto:" << estado.eixoTranslaccao << endl;
					}
					else{
						if(estado.eixoTranslaccao!=0) {
							estado.camera.center[0]=estado.eixo[0];
							estado.camera.center[1]=estado.eixo[1];
							estado.camera.center[2]=estado.eixo[2];
							glutMotionFunc(NULL);
							estado.eixoTranslaccao=0;
							glutPostRedisplay();
						}
						cout << "Right up\n";
					}
				break;
	}
}

void Timer(int value)
{
	glutTimerFunc(estado.delayMovimento, Timer, 0);
	
	GLint xp = estado.camera.center[0];
	GLint yp = estado.camera.center[1];
	GLint zp = estado.camera.center[2];
	int collision = detectCollision(xp, yp, zp);
	if (collision != 0)
	{
		cout << "entrou" << endl;
		estado.camera.eyeVer[2] += 1;
	}

	/* redesenhar o ecrÃ£ */
	glutPostRedisplay();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);

/* need both double buffering and z buffer */

	/*AdvancedGraphGenerator adv(L"http://wvm054.dei.isep.ipp.pt/SocialLiteWS/SocialiteWS.svc/userdata?id=1&token=debug");
	adv.GetRemoteUserData();
	adv.GetGeneratedGraph();*/

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("OpenGL");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(Special);
	glutMouseFunc(mouse);
	glutTimerFunc(estado.delayMovimento, Timer, 0);

	myInit();

	imprime_ajuda();

    glutMainLoop();
}
