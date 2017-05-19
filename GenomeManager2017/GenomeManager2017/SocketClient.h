#pragma once
#include <string>
#include "ResponseHandler.h"
// Cible de la commande Socket

class SocketClient : public CAsyncSocket
{
public:
	SocketClient(ResponseHandler* rh);
	virtual ~SocketClient();
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
protected:
	std::string source;
	std::string destination;
	int port;
	ResponseHandler* rh;
};


