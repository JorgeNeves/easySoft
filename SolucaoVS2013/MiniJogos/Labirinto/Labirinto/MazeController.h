#pragma once
#include <SWI-cpp.h>
#include <math.h>
#include <list>
#include <time.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;
typedef struct {
	int       aX;
	int       aY;
	int       bX;
	int       bY;
}Liga;

class MazeController
{
public:

	MazeController();
	~MazeController();

	int* makePos(char** m, const char value, const int size);
	string convertInt(int number);
	void ligacoes(int value, char** maze);
	void retract();
	string cam_curto(int ax, int ay, int mx, int my);
};