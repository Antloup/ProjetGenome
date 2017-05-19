// SocketServer.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "GenomeServer2017.h"
#include "SocketServer.h"
#include "SocketS2C.h"
#include "RequestHandler.h"


// SocketServer

SocketServer::SocketServer(CGenomeServer2017Dlg* w)
{
	this->window = w;
}

SocketServer::~SocketServer()
{
}


// Fonctions membres SocketServer


void SocketServer::OnAccept(int nErrorCode)
{
	// TODO: ajoutez ici votre code spécialisé et/ou l'appel de la classe de base

	RequestHandler* rh = new RequestHandler(this,window);

	CAsyncSocket::OnAccept(nErrorCode);
}
