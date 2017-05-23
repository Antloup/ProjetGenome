#include "stdafx.h"
#include "Personne.h"


Personne::Personne() : nom(""), prenom("")
{
}

Personne::Personne(string nom, string prenom) : nom(nom), prenom(prenom)
{
}

Personne::~Personne()
{
}
