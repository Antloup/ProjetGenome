#pragma once
#include <string>
#include <list>
#include <fstream>

using namespace std;

class Analyse
{
public:
	Analyse();
	Analyse(ifstream fichier);
	~Analyse();

private:
	list <string> * genome;
};

