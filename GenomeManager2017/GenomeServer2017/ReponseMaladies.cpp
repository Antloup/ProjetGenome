#include "stdafx.h"
#include "ReponseMaladies.h"


ReponseMaladies::ReponseMaladies(string _client, list<Maladie>* _listeMaladies ) : Reponse(_client)
{
	listeMaladies = _listeMaladies;
}


ReponseMaladies::~ReponseMaladies()
{
	delete listeMaladies;
}
