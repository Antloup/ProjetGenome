#pragma once
#include <string>

using namespace std;

class Personne
{
public:
	Personne();
	Personne(string nom, string prenom);
	~Personne();

protected:
	string nom;
	string prenom;
};

