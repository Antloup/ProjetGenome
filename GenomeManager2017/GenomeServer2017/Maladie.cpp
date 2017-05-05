#include "stdafx.h"
#include "Maladie.h"


Maladie::Maladie(string _nom, list<string>* _mots)
{
	nom = _nom;
	mots = _mots;
}


Maladie::~Maladie()
{
	delete mots;
}
