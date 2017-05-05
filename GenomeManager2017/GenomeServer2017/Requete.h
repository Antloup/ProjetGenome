#pragma once
#include <string>
using namespace std;
class Requete
{
public:
	virtual ~Requete();

protected:
	string source;
	Requete(string source);


};

