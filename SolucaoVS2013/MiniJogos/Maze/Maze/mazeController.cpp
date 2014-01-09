#include "MazeController.h"

char* argv[] = { "libswipl.dll", "-s", "labirinto.pl", NULL };
PlEngine pEngine(3, argv);

MazeController::MazeController()
{

}

string MazeController::convertInt(int number)
{
	stringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}


void MazeController::ligacoes(int value, Maze** maze)
{
	std::list<Liga> p;
	for (int i = 0; i < value; i++)
	{
		for (int j = 0; j < value; j++)
		{
			if (i == 5 && j == 5)

			if (maze[i][j].north == 0){ Liga l; l.aX = j; l.aY = i; l.bX = j; l.bY = i - 1;  p.push_back(l); }
			if (maze[i][j].south == 0){ Liga l; l.aX = j; l.aY = i; l.bX = j; l.bY = i + 1;  p.push_back(l); }
			if (maze[i][j].east == 0) { Liga l; l.aX = j; l.aY = i; l.bX = j + 1; l.bY = i;  p.push_back(l); }
			if (maze[i][j].west == 0) { Liga l; l.aX = j; l.aY = i; l.bX = j - 1; l.bY = i;  p.push_back(l); }

		}
	}


	ofstream myfile;
	myfile.open("example.txt");
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
		PlQuery query("asserta", av);

		if (query.next_solution()) myfile << ligacao << "." << endl;
		i++;

		PlTermv parm(2);
		parm[0] = PlCompound(arg1.c_str());
		PlQuery query2("liga", parm);
		while (query2.next_solution()){
			cout << arg1 << " ---> ";
			printf(parm[1]);
			cout << " " << endl;
		}

	}
	myfile.close();
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
