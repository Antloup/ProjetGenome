#pragma once
#include "RequestHandler.h"

// Cible de la commande SocketS2C

class SocketS2C : public CAsyncSocket
{
public:

	SocketS2C(RequestHandler* rh);
	virtual ~SocketS2C();
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
private:
	RequestHandler* rh;
};


