#pragma once
#include <GL\glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "GameStateManager.h"
#include "grafos.h"

using namespace std;

#define M_PI 3.141592
#define graus(X) (double)((X)*180/M_PI)
#define rad(X)   (double)((X)*M_PI/180)


// luzes e materiais

const GLfloat mat_ambient[][4] = { { 0.33, 0.22, 0.03, 1.0 },	// brass
									{ 0.0, 0.0, 0.0 },			// red plastic
									{ 0.0215, 0.1745, 0.0215 },	// emerald
									{ 0.02, 0.02, 0.02 },		// slate
									{ 0.0, 0.0, 0.1745 },		// azul
									{ 0.02, 0.02, 0.02 },		// preto
									{ 0.1745, 0.1745, 0.1745 } };// cinza

const GLfloat mat_diffuse[][4] = { { 0.78, 0.57, 0.11, 1.0 },		// brass
									{ 0.5, 0.0, 0.0 },				// red plastic
									{ 0.07568, 0.61424, 0.07568 },	// emerald
									{ 0.78, 0.78, 0.78 },			// slate
									{ 0.0, 0.0, 0.61424 },			// azul
									{ 0.08, 0.08, 0.08 },			// preto
									{ 0.61424, 0.61424, 0.61424 } };	// cinza

const GLfloat mat_specular[][4] = { { 0.99, 0.91, 0.81, 1.0 },			// brass
										{ 0.7, 0.6, 0.6 },					// red plastic
										{ 0.633, 0.727811, 0.633 },		// emerald
										{ 0.14, 0.14, 0.14 },				// slate
										{ 0.0, 0.0, 0.727811 },			// azul
										{ 0.03, 0.03, 0.03 },				// preto
										{ 0.727811, 0.727811, 0.727811 } };	// cinza

const GLfloat mat_shininess[] = { 27.8,	// brass
								32.0,	// red plastic
								76.8,	// emerald
								18.78,	// slate
								30.0,	// azul
								75.0,	// preto
								60.0 };	// cinza

enum tipo_material { brass, red_plastic, emerald, slate, azul, preto, cinza };

#ifdef __cplusplus
inline tipo_material operator++(tipo_material &rs, int) {
	return rs = (tipo_material)(rs + 1);
}
#endif

typedef	GLdouble Vertice[3];
typedef	GLdouble Vector[4];


typedef struct Camera{
	GLfloat fov;
	GLdouble dir_lat;
	GLdouble dir_long;
	GLfloat dist;
	Vertice center;

}Camera;

typedef struct Estado{
	Camera		camera;
	int			xMouse, yMouse;
	GLboolean	light;
	GLboolean	apresentaNormais;
	GLint		lightViewer;
	GLint		eixoTranslaccao;
	GLdouble	eixo[3];
}Estado;

typedef struct Modelo {
#ifdef __cplusplus
	tipo_material cor_cubo;
#else
	enum tipo_material cor_cubo;
#endif

	GLfloat g_pos_luz1[4];
	GLfloat g_pos_luz2[4];

	GLfloat escala;
	GLUquadric *quad;
}Modelo;

class GraphTestGameState : public GameState
{
private:
	Estado estado;
	Modelo modelo;
	static GraphTestGameState* activeInst;
	void myInit();
	void imprime_ajuda();
	void putLights(GLfloat*);
	void desenhaNo(No no);
	void desenhaArco(Arco arco);
	void desenhaLabirinto();
	void desenhaEixo();
	void desenhaPlanoDrag(int eixo);
	void desenhaEixos();
	void setCamera();
	void setProjection(int x, int y, GLboolean picking);
	void myReshape(int w, int h);

public:
	GraphTestGameState();
	~GraphTestGameState();

	void Load();
	void Unload();
	void HandleInput(unsigned char key, int special, bool val);
	void Update();
	void Draw();
	static void myReshapeWrapper(int w, int h);
};

