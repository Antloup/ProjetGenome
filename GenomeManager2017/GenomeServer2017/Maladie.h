#pragma once
#include <list>
class Maladie
{
public:
	Maladie();
	~Maladie();

protected:
	string nom;
	list<string> mots;
};

