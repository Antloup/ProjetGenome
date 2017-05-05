#pragma once
#include "Reponse.h"
#include <string>
class ReponseMaladies :
	public Reponse
{
public:
	ReponseMaladies(string _client,list<Maladie>* listeMaladies);
	~ReponseMaladies();

protected:
	list<Maladie>* listeMaladies;
};

