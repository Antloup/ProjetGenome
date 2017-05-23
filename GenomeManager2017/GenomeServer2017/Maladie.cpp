#include "stdafx.h"
#include "Maladie.h"


string Maladie::getNom()
{
	return nom;
}

list<string> Maladie::getMots()
{
	return mots;
}

Maladie::Maladie(string _nom, list<string> _mots)
{
	nom = _nom;
	mots = _mots;
	//std::copy(_mots->begin(), _mots->end(), std::back_insert_iterator<std::list<T> >(m_childs));
	
}


Maladie::~Maladie()
{
	//delete mots;
}
