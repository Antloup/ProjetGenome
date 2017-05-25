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

private:
	string request;
	string genome;
	const string const_path = "C:\\Users\\Augustin\\Source\\Repos\\ProjetGenome\\GenomeManager2017\\";
};
