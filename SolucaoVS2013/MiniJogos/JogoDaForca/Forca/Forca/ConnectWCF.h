#ifndef CONNECTWCF
#define CONNECTWCF
#include "WebServices.h"
#include "schemas.microsoft.com.2003.10.Serialization.xsd.h" 
#include "tempuri.org.xsd.h" 
#include "SocialiteWebService.xsd.h"

//#include "stdafx.h" 
#include <string> 
#include <iostream> 
#include <stdlib.h>

using namespace std;

class ConnectWCF
{
public:
	ConnectWCF();
	~ConnectWCF();

	string getn();
	
};
#endif // !CONNECTWCF

