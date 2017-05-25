#include "stdafx.h"
#include "BuildRequestClient.h"
#include <fstream>
#include <iostream>

BuildRequestClient::BuildRequestClient(){}

BuildRequestClient::~BuildRequestClient() {}

void BuildRequestClient::createRequest(string nomFichier)
{
	nomFichier = const_path + nomFichier;
	genome = "";
	request = "";
	ifstream fichier(nomFichier, ios::in);
	string mot;
	getline(fichier, mot);
	if (mot != "MA v1.0")
	{
		cerr << "Ce fichier n'est pas un génome.\r\n" << endl;
	}
	else
	{
		while (getline(fichier, mot))
		{
			genome += mot + ";";
		}
	}
}

string BuildRequestClient::getRequest()
{
	return request;
}

void BuildRequestClient::requestDiseases()
{
	request = "MA v1.0\r\nGET DISEASES\r\n\r\n";
}

void BuildRequestClient::requestFullAnalysis()
{
	request = "MA v1.0\r\nCHECK ALL\r\n" + genome + "\r\n\r\n";

}

void BuildRequestClient::requestSpecificAnalysis(string maladie)
{
	request = "MA v1.0\r\nCHECK DISEASE\r\n" + maladie + "\r\n" + genome + "\r\n\r\n";

}

void BuildRequestClient::requestError() {
	request = "MA v1.0\r\nERROR\r\n";
}
