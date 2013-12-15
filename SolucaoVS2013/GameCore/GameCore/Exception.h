#pragma once
#include <string>

using namespace std;

class Exception
{
private:
	string message;
	string source;
public:
	Exception();
	Exception(string message, string source);
	virtual ~Exception();
};

