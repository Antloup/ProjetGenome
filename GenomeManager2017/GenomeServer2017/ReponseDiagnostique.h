#pragma once
#include "Reponse.h"
class ReponseDiagnostique :
	public Reponse
{
public:
	ReponseDiagnostique(string _client, list<pair<Maladie, bool>>* _listeResultats);
	~ReponseDiagnostique();

protected:
	list<pair<Maladie, bool>>* listeResultats;
};

