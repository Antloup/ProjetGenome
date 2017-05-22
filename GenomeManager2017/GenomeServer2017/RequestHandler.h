#pragma once

#include "GenomeServer2017Dlg.h"
#include "SocketServer.h"
#include "../GenomeManager2017/BuildRequestClient.h"

class SocketS2C;
class RequestHandler
{
public:
	string searchAllDeseases(list<string>* genome, list<Maladie>* serveurMaladies);
	string searchDesease(list<string>* genome, string maladie, list<Maladie>* serveurMaladies);
	string repDiagnostique(list<Maladie>* serveurMaladies);
	RequestHandler(SocketServer* ss,CGenomeServer2017Dlg* w);
	CGenomeServer2017Dlg* getWindow();
	~RequestHandler();

private:
	SocketS2C* ssc;
	CGenomeServer2017Dlg* window;
};

