// Socket.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "GenomeManager2017.h"
#include "SocketClient.h"
#define BUFF_LEN 2048
#define DEFAULT_PORT 8080
#define DEFAULT_SERVER_ADDRESS L"127.0.0.1"


// Socket

SocketClient::SocketClient(ResponseHandler* rh)
{
	this->rh = rh;
	int nPort = DEFAULT_PORT;
	this->Create();
	CString address(rh->getWindow()->getServerAddress().c_str());
	this->Connect(address, DEFAULT_PORT);
}

SocketClient::~SocketClient()
{
}


// Fonctions membres Socket


void SocketClient::OnAccept(int nErrorCode)
{
	// TODO: ajoutez ici votre code spécialisé et/ou l'appel de la classe de base

	CSocket::OnAccept(nErrorCode);
}


void SocketClient::OnReceive(int nErrorCode)
{
	char szBuff[BUFF_LEN];
	char szResponse[BUFF_LEN];

	int nReceivedSize = Receive(szBuff, BUFF_LEN);
	TRACE1("Received : %d bytes \n", nReceivedSize);

	if (nReceivedSize <= 0) {
		TRACE1("Socket receive error : %d\n", GetLastError());
		return;
	}

	szBuff[nReceivedSize] = '\0';
	std::string response(szBuff);

	//ResponseHandler 
	rh->processResponse(response);

	CSocket::OnReceive(nErrorCode);
}
