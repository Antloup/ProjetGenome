#pragma once
#include <string>
#include <list>
#include <fstream>

using namespace std;

class BuildRequestClient
{
public:

	BuildRequestClient(string nomFichier);
	~BuildRequestClient();
	string getRequest();
	void requestDiseases();
	void requestFullAnalysis();
	void requestSpecificAnalysis(string maladie);

private:
	string request;
	string genome;
};
