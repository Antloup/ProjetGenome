#pragma once
#include <string>
// Cible de la commande Socket

class Socket : public CAsyncSocket
{
public:
	Socket();
	virtual ~Socket();
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
protected:
	std::string source;
	std::string destination;
	int port;
};


