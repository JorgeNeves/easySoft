#include "MazeController.h"
using namespace std;

char* argv[] = { "libswipl.dll", "-s", "labirinto.pl", NULL };
PlEngine pEngine(3, argv);

MazeController::MazeController()
{

}

//devolve numero aleatorio
int getRandom(int size)
{
	int i, min, max, decisao, res = 0;

	srand((unsigned)time(0));
	decisao = (rand() % 2);
	min = decisao * (rand() % (size / 2));
	max = (rand() % size);
	if (max < size / 2) max + (size / 2);

	srand((unsigned)time(0));
	res = (rand() % (max));
	while (res < min)
	{
		srand((unsigned)time(0));
		res + (rand() % min);
		if (res < min) res++;
	}

	return res;
}

//define o value de uma posição no labirinto
int* MazeController::makePos(char** m, const char value, const int size)
{
	int	i = getRandom(size);
	int j = getRandom(size);

	bool notready = true;

	while (notready)
	{
		//inserir valor na posição aleatória escolhida
		if (m[i][j] == ' ')
		{
			m[i][j] = value;
			notready = false;
		}
		else
		{
			i = getRandom(size);
			j = getRandom(size);
		}
	}
	int pos[2];
	pos[0] = i;
	pos[1] = j;
	return pos;

}



string MazeController::convertInt(int number)
{
	stringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}


void MazeController::ligacoes(int value, char** maze)
{
	std::list<Liga> p;
	ofstream myfile;
	myfile.open("example.txt");

	for (int i = 0; i < value; i++)
	{
		for (int j = 0; j < value; j++)
		{
			if (maze[i][j] == ' ' && maze[i][j + 1] == ' '){
				Liga l;
				l.aX = i;
				l.aY = j;
				l.bX = i;
				l.bY = j + 1;
				myfile << "liga((" << i << "," << j << "),(" << i << "," << j + 1 << "))." << endl;
				p.push_back(l);
			}
			if (maze[i][j] == ' ' && maze[i + 1][j] == ' '){
				Liga l;
				l.aX = i;
				l.aY = j;
				l.bX = i + 1;
				l.bY = j;
				myfile << "liga((" << i << "," << j << "),(" << i + 1 << "," << j << "))." << endl;
				p.push_back(l);
			}
			if (maze[i][j] == ' ' && maze[i][j - 1] == ' '){
				Liga l;
				l.aX = i;
				l.aY = j;
				l.bX = i;
				l.bY = j - 1;
				myfile << "liga((" << i << "," << j << "),(" << i << "," << j - 1 << "))." << endl;
				p.push_back(l);
			}
			if (maze[i][j] == ' ' && maze[i - 1][j] == ' '){
				Liga l;
				l.aX = i;
				l.aY = j;
				l.bX = i - 1;
				l.bY = j;
				myfile << "liga((" << i << "," << j << "),(" << i - 1 << "," << j << "))." << endl;
				p.push_back(l);
			}

		}
	}

	myfile.close();
	
	int i = 0;
	while (!p.empty())
	{
		PlTermv av(1);
		string arg1 = "(";
		string arg2 = "(";
		Liga x = p.front();
		arg1 += convertInt(x.aX) + ",";
		arg1 += convertInt(x.aY) + ")";
		arg2 += convertInt(x.bX) + ",";
		arg2 += convertInt(x.bY) + ")";
		p.pop_front();
		string ligacao = "liga(" + arg1 + "," + arg2 + ")";

		av[0] = PlCompound(ligacao.c_str());
		PlQuery query("assertz", av);

		if (query.next_solution()) myfile << ligacao << "." << endl;
		i++;

		//PlTermv parm(2);
		//parm[0] = PlCompound(arg1.c_str());
		//PlQuery query2("liga", parm);
		//while (query2.next_solution()){
		//cout << arg1 << " ---> ";
		//printf(parm[1]);
		//cout << " " << endl;
		//}

	}

}


void MazeController::retract(){
	PlTermv av2(1);

	av2[0] = PlCompound("liga(_,_)");
	PlQuery query("retractall", av2);
	query.next_solution();
}

string MazeController::cam_curto(int ax, int ay, int mx, int my){
	string aaaa1 = "(" + convertInt(ax) + ',' + convertInt(ay) + ')';
	string aaaa2 = "(" + convertInt(mx) + ',' + convertInt(my) + ')';
	PlTermv av2(3);

	av2[0] = PlCompound(aaaa1.c_str());
	av2[1] = PlCompound(aaaa2.c_str());
	PlQuery query("encontra_caminho", av2);
	string f;
	query.next_solution();
	f += (char*)av2[2];
	return f;
}

MazeController::~MazeController()
{
}