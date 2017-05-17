#pragma once
#include <string>
#include <list>

class ParseRequestServer
{
public:
	ParseRequestServer();
	~ParseRequestServer();

private:
	list<string> genome;
	string maladie;
};

