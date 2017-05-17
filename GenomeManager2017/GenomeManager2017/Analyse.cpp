#include "stdafx.h"
#include "Analyse.h"
#include <fstream>
#include <iostream>



Analyse::Analyse(string nomFichier)
{
	ifstream fichier (nomFichier.c_str(), ios::in);
	string mot;
	fichier >> mot;
	genome = new list<string>;
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

Analyse::~Analyse()
{
	delete genome;
}