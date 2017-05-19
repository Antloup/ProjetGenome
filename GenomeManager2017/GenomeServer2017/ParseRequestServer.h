#pragma once
#include <string>
#include <list>

using namespace std;

class ParseRequestServer
{
public:
	ParseRequestServer();
	~ParseRequestServer();

private:
	list<string> genome;
	string maladie;
};

