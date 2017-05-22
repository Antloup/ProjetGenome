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
	list<string> getGenome();

private:
	list<string> genome;
	string maladie;
	bool type; //false pour CHECK ALL et true pour CHECK DESEASE
};

