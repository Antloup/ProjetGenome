#pragma once

// Cible de la commande SocketServer
#include "GenomeServer2017Dlg.h"

class SocketServer : public CAsyncSocket
{
public:
	SocketServer(CGenomeServer2017Dlg* w);
	virtual ~SocketServer();
	virtual void OnAccept(int nErrorCode);
private:
	CGenomeServer2017Dlg* window;
};


