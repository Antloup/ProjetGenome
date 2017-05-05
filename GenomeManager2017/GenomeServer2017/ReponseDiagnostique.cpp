#include "stdafx.h"
#include "ReponseDiagnostique.h"

ReponseDiagnostique::ReponseDiagnostique(string _client,list<pair<Maladie, bool>>* _listeResultats)
{
	client = _client;
	listeResultats = _listeResultats;
}


ReponseDiagnostique::~ReponseDiagnostique()
{
	delete listeResultats;
}
