#pragma once
#include "Requete.h";
#include "Maladie.h";
#include "../GenomeManager2017/Analyse.h";

class RequeteDiagnostique : public Requete
{
public:
	RequeteDiagnostique(string source,list<Maladie>* maladies, Analyse* analyse);
	virtual ~RequeteDiagnostique();
protected:
	list<Maladie> * maladies;
	Analyse * analyse;
};

