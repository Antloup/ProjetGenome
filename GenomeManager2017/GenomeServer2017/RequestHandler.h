#pragma once

#include "GenomeServer2017Dlg.h"
#include "SocketServer.h"
#include "../GenomeManager2017/BuildRequestClient.h"

class SocketS2C;
class RequestHandler
{
public:
	string searchAllDiseases(list<string>* genome, list<Maladie>* serveurMaladies);
	string searchDisease(list<string>* genome, string maladie, list<Maladie>* serveurMaladies);
	string repDiagnostique(list<Maladie>* serveurMaladies);
	string processRequest(string req);
	RequestHandler(SocketServer* ss = NULL,CGenomeServer2017Dlg* w = NULL);
	CGenomeServer2017Dlg* getWindow();
	~RequestHandler();

private:
	SocketS2C* ssc;
	CGenomeServer2017Dlg* window;
};

