#pragma once
#include <string>
#include <list>
#include <fstream>

using namespace std;

class Analyse
{
public:
	
	Analyse(string nomFichier);
	~Analyse();

private:
	list <string> * genome;
};
