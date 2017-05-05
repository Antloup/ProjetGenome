#include "stdafx.h"
#include "Reponse.h"

/*
Reponse::Reponse(string _client, list<pair<Maladie, bool>>* _resultat)
{
	client = _client;
	resultat = _resultat;
}
*/


Reponse::~Reponse()
{
	delete resultat;
}
