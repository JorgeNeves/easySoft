#include "Exception.h"


Exception::Exception()
{
	this->message = "null";
	this->source = "null";
}

Exception::Exception(string message, string source)
{
	this->message = message;
	this->source = source;
}

Exception::~Exception()
{
}
