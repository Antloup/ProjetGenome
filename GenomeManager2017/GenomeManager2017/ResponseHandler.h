#pragma once
#include "GenomeManager2017Dlg.h"
#include <string>
#include "BuildRequestClient.h"

class ResponseHandler
{
public:
	ResponseHandler(CGenomeManager2017Dlg* w);
	~ResponseHandler();
	CGenomeManager2017Dlg* getWindow();
	void processResponse(std::string response);
private:
	CGenomeManager2017Dlg* window;
	SocketClient* sc;
	BuildRequestClient* brc;
};

