#pragma once
#include <string>
#include "ResponseHandler.h"
// Cible de la commande Socket

class SocketClient : public CSocket
{
public:
	SocketClient(ResponseHandler* rh);
	virtual ~SocketClient();
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
protected:
	ResponseHandler* rh;
};


