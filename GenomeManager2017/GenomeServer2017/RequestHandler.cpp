#include "stdafx.h"
#include "RequestHandler.h"
#include "SocketS2C.h"
#include <string>
#include <list>
#include <algorithm>
#include "ParseRequestServer.h"

using namespace std;

string RequestHandler::searchAllDeseases(list<string> * genome, list<Maladie> * serveurMaladies) {
	// Prend en paramètre le génome et la liste de maladies du serveur, et renvoie la réponse sous forme de string, à envoyer directement par la socket

	string reponse = "MA v1.0\r\n";

	for(Maladie itServeur : *serveurMaladies)
	{
		bool malade = true;
		for(string itServeurMots : itServeur.getMots())
		{
			list<string>::iterator trouve = find(genome->begin(), genome->end(), itServeurMots);

			if (trouve == genome->end())
			{
				malade = false;
				break;
			}
		}

		if (malade == true)
		{
			reponse += "DESEASE " + itServeur.getNom() + "\r\n";
		}
	}

	reponse += "\r\n";
	return reponse;
}




string RequestHandler::searchDesease(list<string> * genome, string maladie, list<Maladie> * serveurMaladies) {
	// Prend en paramètre le génome, la maladie et la liste des maladies du serveur, et renvoie la réponse sous forme de string, à envoyer directement par la socket

	list<Maladie>::iterator itServeur= serveurMaladies->begin();//= find(serveurMaladies->begin(), serveurMaladies->end() ,maladie);
	while ( itServeur->getNom() != maladie && itServeur != serveurMaladies->end())
	{
		++itServeur;
	}

	if (itServeur == serveurMaladies->end())
	{
		return "MA v1.0\r\nERROR";
	}

	//for (list<string>::iterator itServeurMots = itServeur->getMots().begin(); itServeurMots != itServeur->getMots().end(); ++itServeurMots)
	for (string it : itServeur->getMots())
	{

		list <string>::iterator trouve = find(genome->begin(), genome->end(), it);
		
		if (trouve == genome->end())
		{
			return "MA v1.0\r\nDESEASE " + maladie + "\r\n<0>\r\n\r\n";
		}
	}

	return "MA v1.0\r\nDESEASE " + maladie + "\r\n<1>\r\n\r\n";
}





string RequestHandler::repDiagnostique(list<Maladie> * serveurMaladies)
{
	// Prend en paramètre la liste des maladies du serveur, et renvoie la réponse sous forme de string, à envoyer directement par la socket

	string reponse = "MA v1.0\r\n";
			
	for (list<Maladie>::iterator itServeur = serveurMaladies->begin() ; itServeur != serveurMaladies->end(); ++itServeur)
	{		
		reponse += "DESEASES\r\n" + itServeur->getNom() + "\r\n";	
	}
	
	reponse += "\r\n";
	return reponse;
}

string RequestHandler::processRequest(string req)
{
	ParseRequestServer request(req);
	string strResponse;
	if (request.getType() == 0)
	{
		strResponse = searchDesease(request.getGenome(), request.getMaladie(), getWindow()->getMaladies());
	}
	else if (request.getType() == 1)
	{
		strResponse = repDiagnostique(getWindow()->getMaladies());
	}
	else if (request.getType() == 2)
	{
		strResponse = searchAllDeseases(request.getGenome(), getWindow()->getMaladies());
	}
	else
	{
		strResponse = "MA v1.0\r\nERROR : Format de requête inconnu\r\n\r\n";
	}
	return strResponse;
}


RequestHandler::RequestHandler(SocketServer* ss, CGenomeServer2017Dlg* w)
{
	this->window = w;
	this->ssc = new SocketS2C(this);
	bool bResult = ss->Accept(*this->ssc);
}

RequestHandler::~RequestHandler()
{
}

CGenomeServer2017Dlg* RequestHandler::getWindow(){
	return window; 
}