#pragma once

#include "GenomeServer2017Dlg.h"
#include "SocketServer.h"
class SocketS2C;
class RequestHandler
{
public:
	RequestHandler(SocketServer* ss,CGenomeServer2017Dlg* w);
	CGenomeServer2017Dlg* getWindow();
	~RequestHandler();

private:
	SocketS2C* ssc;
	CGenomeServer2017Dlg* window;
};

