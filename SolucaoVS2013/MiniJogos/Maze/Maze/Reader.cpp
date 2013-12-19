#include "Reader.h"
#include <ctime>
Reader::Reader()
{
}


Reader::~Reader()
{
}

//repartir uma string em várias partes através de um "split"
//retirado de: http://stackoverflow.com/questions/890164/how-can-i-split-a-string-by-a-delimiter-into-an-array
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

//criar um quadrado no labirinto
Maze& createQuadrado(const int n, const int s, const int e, const int w, const int v)
{
	//inserir valores no quadrado
	Maze* quad = new Maze; 
	quad->north = n;
	quad->south = s;
	quad->east = e;
	quad->west = w;
	quad->value = v;

	return *quad;
}

//descobrir o quadrado correspondente ao tipo escolhido e devolver
Maze& getQuadrado(const int numQuadrado)
{
	switch (numQuadrado){
	case 0:
		return createQuadrado(0, 0, 0, 0, 0);
		break;
	case 1:
		return createQuadrado(1, 0, 0, 0, 0);
		break;
	case 2:
		return createQuadrado(0, 0, 1, 0, 0);
		break;
	case 3:
		return createQuadrado(0, 1, 0, 0, 0);
		break;
	case 4:
		return createQuadrado(0, 0, 0, 1, 0);
		break;
	case 5:
		return createQuadrado(1, 0, 1, 0, 0);
		break;
	case 6:
		return createQuadrado(1, 1, 0, 0, 0);
		break;
	case 7:
		return createQuadrado(1, 0, 0, 1, 0);
		break;
	case 8:
		return createQuadrado(0, 1, 1, 0, 0);
		break;
	case 9:
		return createQuadrado(0, 0, 1, 1, 0);
		break;
	case 10:
		return createQuadrado(0, 1, 0, 1, 0);
		break;
	case 11:
		return createQuadrado(1, 0, 1, 1, 0);
		break;
	case 12:
		return createQuadrado(1, 1, 1, 0, 0);
		break;
	case 13:
		return createQuadrado(1, 1, 0, 1, 0);
		break;
	case 14:
		return createQuadrado(0, 1, 1, 1, 0);
		break;
	case 15:
		return createQuadrado(1, 1, 1, 1, 3);
		break;
	default:
		//caso de erro
		return createQuadrado(3, 3, 3, 3, 3);
		break;
	}
}

//define o value de uma posição no labirinto
void makePos(Maze*** m, const int value, const int size)
{
	//definir posição aleatoria
	srand((unsigned)time(0));
	int i = (rand() % size);
	srand((unsigned)time(0));
	int j = (rand() % size);

	//inserir valor na posição aleatória escolhida
	if (m[i][j]->value != 0)
	{
		m[i][j]->value = value;
	}
}

//receber o tamanho do labirinto
int Reader::getMazeSize(const string f)
{
	ifstream file(f);
	string str;
	int size;
	getline(file, str);
	String2Int(str,size);
	return size;
}

//criar o labirinto
Maze*** Reader::getMaze(const string f)
{
	//inizialização de variaveis
	ifstream file(f);
	string str;
	int size;

	//retira o tamanho do labirinto na primeira linha: 20*20 // 30*30 // 40*40
	getline(file, str);
	String2Int(str,size);

	//inicialização do labirinto
	Maze*** labirinto = new Maze**[size];
	for (int i = 0; i < size; i++)
	{
		labirinto[i] = new Maze*[size];
	}

	//por cada linha no ficheiro criar linha do labirinto
	while (getline(file, str))
	{
		//obter linha do ficheiro
		vector<string> linha = explode(str, ',');
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				//obter quadrado
				int quad;
				String2Int(linha.at(i), quad);
				Maze quadrado = getQuadrado(quad);
				labirinto[i][j] = &quadrado;
			}
		}
	}

	//criar posição inicial
	makePos(labirinto, 1, size);
	//criar posição final
	makePos(labirinto, 2, size);

	return labirinto;
}