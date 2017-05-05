#include "stdafx.h"
#include "RequeteDiagnostique.h"




RequeteDiagnostique::RequeteDiagnostique(string Source, list<Maladie>* Maladies, Analyse * Analyse) : Requete(Source), maladies(Maladies),analyse(Analyse)
{

}

RequeteDiagnostique::~RequeteDiagnostique()
{

}
