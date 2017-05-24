#pragma once
#include "GenomeManager2017Dlg.h"
#include <string>
#include "BuildRequestClient.h"
#include <fstream>

class SocketClient;
class ResponseHandler
{
public:
	ResponseHandler(CGenomeManager2017Dlg* w);
	ResponseHandler(string m,string f);
	~ResponseHandler();
	void Init();
	CGenomeManager2017Dlg* getWindow();
	string processResponse(std::string response);
	BuildRequestClient* getBrc();
	string getMaladie();
private:
	CGenomeManager2017Dlg* window;
	SocketClient* sc;
	BuildRequestClient* brc;
	string maladie;
	string file;
};

