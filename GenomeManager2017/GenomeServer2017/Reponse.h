#pragma once
#include <list>
#include "Maladie.h"
using namespace std;
class Reponse
{
public:
	virtual ~Reponse();

protected:
	Reponse(string _client) {};
	string client;
};

