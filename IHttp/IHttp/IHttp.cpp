// IHttp.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "WininetHttp.h"
#include "SocketHttp.h"
#include "WinHttp/HttpClient.h"




bool CreateInstance( IHttpBase** pBase, InterfaceType flag )
{
	IHttpBase* pInst = NULL;
	switch (flag)
	{
	case TypeSocket:
		pInst = new CHttpSocket();
		break;
	case TypeWinInet:
		pInst = new CWininetHttp();
		break;
	case TypeWinHttp:
		pInst = new CWinHttp();
		break;
	}
	*pBase = pInst;
	return pInst != NULL;
}

void InitWSASocket()
{
	WSADATA data;
	WSAStartup(MAKEWORD(2, 2), &data);
}

void UninitWSASocket()
{
	WSACleanup();
}