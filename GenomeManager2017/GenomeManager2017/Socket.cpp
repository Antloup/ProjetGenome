// Socket.cpp�: fichier d'impl�mentation
//

#include "stdafx.h"
#include "GenomeManager2017.h"
#include "Socket.h"


// Socket

Socket::Socket()
{
}

Socket::~Socket()
{
}


// Fonctions membres Socket


void Socket::OnAccept(int nErrorCode)
{
	// TODO: ajoutez ici votre code sp�cialis� et/ou l'appel de la classe de base

	CAsyncSocket::OnAccept(nErrorCode);
}


void Socket::OnReceive(int nErrorCode)
{
	// TODO: ajoutez ici votre code sp�cialis� et/ou l'appel de la classe de base

	CAsyncSocket::OnReceive(nErrorCode);
}
