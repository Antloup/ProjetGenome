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
	maladie = w->getMaladie();
	file = CT2A((LPCTSTR)w->getFile());
	SocketClient* socket = new SocketClient(this);
	this->sc = socket;
	Init();
}

ResponseHandler::ResponseHandler(string m,string f)
{
	sc = NULL;
	window = NULL;
	maladie = m;
	file = f;
	Init();
}


ResponseHandler::~ResponseHandler()
{
	delete this->sc;
}

void ResponseHandler::Init() {
	
	//Envoie demande maladies
	BuildRequestClient* build = new BuildRequestClient();
	build->createRequest(file);
	this->brc = build;
	if (maladie == "") {
		this->brc->requestFullAnalysis();
	}
	else {
		this->brc->requestDiseases();
	}

	if (sc != NULL) {
		sc->Send(brc->getRequest().c_str(), strlen(brc->getRequest().c_str()));
	}
	
}

CGenomeManager2017Dlg* ResponseHandler::getWindow()
{
	return window;
}

string ResponseHandler::processResponse(std::string response)
{
	//Traiter la réponse
	//string s_output = "Socket response:" + response;
	//CString output(s_output.c_str());
	CString output;

	std::istringstream f_response(response);
	std::string line;
	std::getline(f_response, line);
	if (line != "MA v1.0\r") {
		output = "Erreur interne au serveur.\r\n";
		if (window != NULL) {
			this->getWindow()->setOutput(output);
		}
		
		brc->requestError();
		if (sc != NULL) {
			sc->Send(brc->getRequest().c_str(), strlen(brc->getRequest().c_str()));
		}
		
		return CT2A((LPCTSTR)output);
	}
	std::getline(f_response, line);
	
	if (line == "DISEASES\r") { // Le serveur a envoyé sa liste de maladie
		//string maladie = "";
		bool trouver = false;
		while (std::getline(f_response, line)) {
			line = line.substr(0, line.length()-1);
			if (line == maladie) {
				trouver = true;
				break;
			}
		}

		//Envoie de la maladie a analyser
		if (trouver) {
			output = "Le serveur va analyser votre maladie.";
			if (window != NULL) {
				window->setOutput(output);
			}
			brc->requestSpecificAnalysis(maladie);
			if (sc != NULL) {
				sc->Send(brc->getRequest().c_str(), strlen(brc->getRequest().c_str()));
			}
			
		}
		else {
			output = "Le serveur ne connait pas cette maladie.\r\n";
			if (window != NULL) {
				window->setOutput(output);
			}
		}
		
	}

	else if (maladie != "") {
		if (line == "DISEASE " + maladie + "\r") { // Le serveur a envoyé une réponse
			string haveDisease;
			std::getline(f_response, haveDisease);
			if (haveDisease == "<1>\r") {
				string s_output = "Vous avez la maladie suivante : " + maladie + ".\r\n";
				output = s_output.c_str();
			}
			else if (haveDisease == "<0>\r") {
				output = "Vous n'avez pas la maladie.\r\n";
			}
			else {
				output = "Format de reponse non conforme.\r\n";
			}
			if (window != NULL) {
				window->setOutput(output);
			}
		}
	}
	else {
		istringstream iss(line);
		string mot;
		string s_output;
		std::getline(iss, mot, ' ');
		std::getline(iss, mot);
		if (mot == "\r") {
			s_output = "Vous n'avez pas de maladie.\r\n";
		}
		else {
			s_output = "Vous avez les maladies suivantes :\r\n";
			s_output += mot + "\r\n";
			while (std::getline(iss, mot)) {
				s_output += mot + "\r\n";
				std::getline(iss, mot, ' ');
				std::getline(iss, mot);
			}
			s_output += "\r\n";
		}
		

		output = s_output.c_str();
		if (window != NULL) {
			window->setOutput(output);
		}
	}

	return CT2A((LPCTSTR)output);

}

BuildRequestClient * ResponseHandler::getBrc()
{
	return brc;
}

string ResponseHandler::getMaladie()
{
	return maladie;
}
