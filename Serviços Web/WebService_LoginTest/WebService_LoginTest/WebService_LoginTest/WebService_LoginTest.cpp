// WebService_LoginTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WebServices.h>
#include "schemas.microsoft.com.2003.10.Serialization.xsd.h"
#include "tempuri.org.xsd.h"
#include "tempuri.org.wsdl.h"
#include <string> 
#include <iostream> 
#include <stdlib.h> 



int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr = ERROR_SUCCESS;
	WS_ERROR* error = NULL;
	WS_HEAP* heap = NULL;
	WS_SERVICE_PROXY* proxy = NULL;
	WS_ENDPOINT_ADDRESS address = {};

	//endereco servico
	WS_STRING url = WS_STRING_VALUE(L"http://wvm054.dei.isep.ipp.pt/easySoft/easySoftWS/Service.svc?wsdl");
	address.url = url;
	hr = WsCreateHeap(2048, 512, NULL, 0, &heap, error);
	WS_HTTP_BINDING_TEMPLATE templ = {};

	hr = BasicHttpBinding_IService_CreateServiceProxy(&templ, NULL, 0, &proxy, error);
	hr = WsOpenServiceProxy(proxy, &address, NULL, error);

	WCHAR* result;

	printf("Teste correto: user|pwd\n");
	hr = BasicHttpBinding_IService_Login(proxy, L"user", L"pwd", &result, heap, NULL, 0, NULL, error);
	wprintf(L"%s\n", result);

	printf("\n\nTeste incorreto: nouser|nopwd\n");
	hr = BasicHttpBinding_IService_Login(proxy, L"nouser", L"nopwd", &result, heap, NULL, 0, NULL, error);
	wprintf(L"%s\n", result);



	if (proxy)
	{
		WsCloseServiceProxy(proxy, NULL, NULL);
		WsFreeServiceProxy(proxy);
	}
	if (heap)
		WsFreeHeap(heap);
	if (error)
		WsFreeError(error);
	getchar();
	return 0;
}

