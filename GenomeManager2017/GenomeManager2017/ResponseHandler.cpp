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
	if (window->getMaladie() == "") {
		this->brc->requestFullAnalysis();
	}
	else {
		this->brc->requestDiseases();
	}
	
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
	string s_output = "Socket response:" + response;
	CString output(s_output.c_str());

	//this->getWindow()->setOutput(output);

	std::istringstream f_response(response);
	std::string line;
	std::getline(f_response, line);
	if (line != "MA v1.0\r") {
		CString output("Erreur interne au serveur.\r\n");
		this->getWindow()->setOutput(output);
		brc->requestError();
		sc->Send(brc->getRequest().c_str(), strlen(brc->getRequest().c_str()));
		
		return;
	}
	std::getline(f_response, line);
	if (line == "DESEASES\r") { // Le serveur a envoyé sa liste de maladie
		string maladie = "";
		while (std::getline(f_response, line)) {
			line = line.substr(0, line.length()-1);
			if (line == window->getMaladie()) {
				maladie = line;
				break;
			}
		}

		//Envoie de la maladie a analyser
		if (maladie != "") {
			CString output("Le serveur va analyser votre maladie.");
			window->setOutput(output);
			brc->requestSpecificAnalysis(maladie);
			sc->Send(brc->getRequest().c_str(), strlen(brc->getRequest().c_str()));
		}
		else {
			CString output("Le serveur ne connait pas cette maladie.\r\n");
			window->setOutput(output);
		}
		
	}

	else if (window->getMaladie() != "") {
		if (line == "DESEASE " + window->getMaladie() + "\r") { // Le serveur a envoyé une réponse
			string haveDesease;
			std::getline(f_response, haveDesease);
			CString output;
			if (haveDesease == "<1>\r") {
				string s_output = "Vous avez la maladie suivante : " + window->getMaladie() + ".\r\n";
				output = s_output.c_str();
			}
			else if (haveDesease == "<0>\r") {
				output = "Vous n'avez pas la maladie.\r\n";
			}
			else {
				output = "Format de reponse non conforme.\r\n";
			}
			window->setOutput(output);
		}
	}
	else {
		istringstream iss(line);
		string mot;
		string s_output;
		std::getline(iss, mot, ' ');
		if (mot == "\r") {
			s_output = "Vous n'avez pas de maladie.\r\n";
		}
		else {
			s_output = "Vous avez les maladies suivantes :\r\n";
			while (std::getline(iss, mot)) {
				s_output += mot + "\r\n";
				std::getline(iss, mot, ' ');
				std::getline(iss, mot);
			}
			s_output += "\r\n";
		}
		

		output = s_output.c_str();
		window->setOutput(output);
	}

}
