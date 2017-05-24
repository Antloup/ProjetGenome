#include "stdafx.h"
#include "BuildRequestClient.h"
#include <fstream>
#include <iostream>

BuildRequestClient::BuildRequestClient(string nomFichier)
{
	genome = "";
	request = "";
	ifstream fichier(nomFichier.c_str(), ios::in);
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

BuildRequestClient::~BuildRequestClient() {}

string BuildRequestClient::getRequest()
{
	return request;
}

void BuildRequestClient::requestDiseases()
{
	request = "MA v1.0\r\nGET DESEASES\r\n\r\n";
}

void BuildRequestClient::requestFullAnalysis()
{
	request = "MA v1.0\r\nCHECK ALL\r\n" + genome + "\r\n\r\n";

}

void BuildRequestClient::requestSpecificAnalysis(string maladie)
{
	request = "MA v1.0\r\nCHECK DESEASE\r\n" + maladie + "\r\n" + genome + "\r\n\r\n";

}

void BuildRequestClient::requestError() {
	request = "MA v1.0\r\nERROR\r\n";
}