#include "stdafx.h"
#include "ResponseHandler.h"
#include "SocketClient.h"
#include "BuildRequestClient.h"
#include <iostream>
#include <sstream>
#include "../GenomeServer2017/Maladie.h"

ResponseHandler::ResponseHandler(CGenomeManager2017Dlg * w)
{
	window = w;
	SocketClient* socket = new SocketClient(this);
	this->sc = socket;
	//Envoie demande maladies
	std::string file = CT2A((LPCTSTR)w->getFile());
	BuildRequestClient* build = new BuildRequestClient(file);
	this->brc = build;
	this->brc->requestDiseases();
	sc->Send(brc->getRequest().c_str(), strlen(brc->getRequest().c_str()));

}


ResponseHandler::~ResponseHandler()
{
	delete this->sc;
}

CGenomeManager2017Dlg* ResponseHandler::getWindow()
{
	return window;
}

void ResponseHandler::processResponse(std::string response)
{
	//Traiter la réponse
	CString output(response.c_str());
	this->getWindow()->setOutput(output);

	std::istringstream f_response(response);
	std::string line;
	std::getline(f_response, line);
	if (line != "MA v1.0") {
		brc->requestError();
		sc->Send(brc->getRequest().c_str(), strlen(brc->getRequest().c_str()));
		
		return;
	}
	std::getline(f_response, line);
	if (line == "DESEASES") { // Le serveur a envoyé sa liste de maladie
		string maladie = "";
		while (std::getline(f_response, line)) {
			if (line == window->getMaladie()) {
				maladie = line;
				break;
			}
		}

		//Envoie de la maladie a analyser
		if (maladie != "") {
			brc->requestSpecificAnalysis(maladie);
			sc->Send(brc->getRequest().c_str(), strlen(brc->getRequest().c_str()));
		}
		
	}

	else if (line == "DESEASE "+window->getMaladie()) { // Le serveur a envoyé une réponse
		string haveDesease;
		std::getline(f_response, haveDesease);
		CString output;
		if (haveDesease == "1") {
			output = "maladie";
		}
		else if (haveDesease == "0") {
			output = "Pas maladie";
		}
		else {
			output = "What?";
		}
		window->setOutput(output);
	}
}
