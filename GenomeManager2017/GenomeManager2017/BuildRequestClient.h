
#pragma once
#include <string>
#include <list>
#include <fstream>

using namespace std;

class BuildRequestClient
{
public:

	BuildRequestClient();
	~BuildRequestClient();
	string getRequest();
	void createRequest(string nomFichier);
	void requestDiseases();
	void requestFullAnalysis();
	void requestSpecificAnalysis(string maladie);
	void requestError();
	void setGenome(string g);
private:
	string request;
	string genome;
};