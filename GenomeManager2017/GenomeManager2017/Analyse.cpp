#include "stdafx.h"
#include "Analyse.h"
#include <fstream>






Analyse::Analyse(string nomFichier)
{
	ifstream fichier = (nomFichier.c_str(), ios::in);
	string mot;
	fichier >> mot;
	genome = new list<string>;
	if (mot != "Genome")
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

Analyse::~Analyse()
{
	delete genome;
}
