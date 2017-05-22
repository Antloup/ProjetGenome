#pragma once
#include <list>
using namespace std;
class Maladie
{
public:
	string getNom();
	list<string> * getMots();
	Maladie(string _nom, list<string>* _mots);
	~Maladie();

protected:
	string nom;
	list<string>* mots;
	//Test
};

