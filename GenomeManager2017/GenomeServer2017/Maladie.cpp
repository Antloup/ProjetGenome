#include "stdafx.h"
#include "Maladie.h"


string Maladie::getNom()
{
	return nom;
}

list<string> * Maladie::getMots()
{
	return mots;
}

Maladie::Maladie(string _nom, list<string>* _mots)
{
	nom = _nom;
	mots = _mots;
}


Maladie::~Maladie()
{
	delete mots;
}
