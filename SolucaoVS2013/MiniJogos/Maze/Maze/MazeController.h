#pragma once
#include "Reader.h"
#include <SWI-cpp.h>
#include <math.h>
#include <list>
#include <time.h>
#include <iostream>
#include <sstream>
#include <string>



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

	string convertInt(int number);
	void ligacoes(int value, Maze** maze);
	string cam_curto(int ax, int ay, int mx, int my);
};

