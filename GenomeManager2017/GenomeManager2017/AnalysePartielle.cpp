#include "stdafx.h"
#include "AnalysePartielle.h"


AnalysePartielle::AnalysePartielle()
{
}

Analyse::Analyse(list<string> * listeMaladies, string nomFichier)
{
	maladies = listeMaladies;
	ifstream fichier = (nomFichier.c_str(), ios::in);
	string mot;
	if (fichier)
	{
		fichier >> mot;
		if (mot != "MA v1.0")
		{
			cerr << "Ce fichier n'est pas un génome." << endl;
		}
		else
		{
			while (fichier >> mot)
			{
				genome->push_back(mot);
			}
		}
	}
	
}

AnalysePartielle::~AnalysePartielle()
{
}
