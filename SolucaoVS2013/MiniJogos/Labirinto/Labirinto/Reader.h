#pragma once

#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
	int west;
	int north;
	int east;
	int south;
	int value; // 0 representa um caminho, 1 representa o inicio, 2 representa o fim
}Maze;

class Reader
{
public:
	Reader();

	~Reader();

	int* Reader::makePos(char** m, const char value, const int size);

	vector<string> explode(const string& str, const char& ch);

	Maze** getMaze(const string f);

	int getMazeSize(const string f);
};
