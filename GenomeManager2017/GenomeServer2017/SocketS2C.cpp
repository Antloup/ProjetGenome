// SocketS2C.cpp�: fichier d'impl�mentation
//

#include "stdafx.h"
#include "GenomeServer2017.h"
#include "ParseRequestServer.h"
#include "SocketS2C.h"
#define BUFF_LEN 2048
#include <string>
#include "RequestHandler.h"


// SocketS2C

SocketS2C::SocketS2C(RequestHandler* rh)
{
	this->rh = rh;
	CString strPeerName;
	UINT uiPort;
	this->GetPeerName(strPeerName, uiPort);
}

SocketS2C::~SocketS2C()
{
}


// Fonctions membres SocketS2C


void SocketS2C::OnReceive(int nErrorCode)
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
	TRACE(szBuff);
	CString output(szBuff);
	this->rh->getWindow()->setOutput(output);


	//Traiter la requete
	string req(szBuff);	
	//req = "MA v1.0\r\nCHECK DISEASE\r\ncancer\r\nACT;CG;ATCG;\r\n";
	/*ParseRequestServer p(req);
	for (list<string>::iterator it = p.getGenome()->begin(); it != p.getGenome()->end(); ++it)
	{
		string output = *it;
		CString out (output.c_str());
		this->rh->getWindow()->setOutput(out);
	}*/

	string strResponse = rh->processRequest(req);


	//Envoyer la r�ponse
	int nSentBytes = 0;
	const char* pszBuff = strResponse.c_str();
	int nResponseSize = strResponse.length();

	while (nSentBytes < nResponseSize) {
		nSentBytes = Send(pszBuff, nResponseSize);
		nResponseSize = nResponseSize - nSentBytes;
		pszBuff = pszBuff + nSentBytes;
	}


	CAsyncSocket::OnReceive(nErrorCode);
}


void SocketS2C::OnSend(int nErrorCode)
{
	// TODO: ajoutez ici votre code sp�cialis� et/ou l'appel de la classe de base

	CAsyncSocket::OnSend(nErrorCode);
}
