#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

class ParseRequestServer
{
public:
	ParseRequestServer(string genome);
	~ParseRequestServer();
	string getMaladie();
	int getType();
	list<string>* getGenome();

public:
	list<string>* genome;
	string maladie;
	int type; //1 pour la liste des maladies du serveur, 2 pour CHECK ALL et 0 pour CHECK DESEASE
};

