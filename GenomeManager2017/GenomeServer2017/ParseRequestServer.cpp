#include "stdafx.h"
#include "ParseRequestServer.h"


ParseRequestServer::ParseRequestServer(string genome_string)
{
	string delimiter = "\r\n";
	size_t pos = genome_string.find(delimiter);
	string mot = genome_string.substr(0, pos);
	genome_string.erase(0, pos + delimiter.length());

	if (mot != "MA v1.0")
	{
		cerr << "Ce n'est pas une requête.\r\n" << endl;
	}
	else
	{
		size_t pos = genome_string.find(delimiter);
		string mot = genome_string.substr(0, pos);
		genome_string.erase(0, pos + delimiter.length());
		if (mot == "CHECK DISEASE")
		{
			type = true;
			size_t pos = genome_string.find(delimiter);
			string mot = genome_string.substr(0, pos);
			genome_string.erase(0, pos + delimiter.length());
			maladie = mot;
		}
		else
		{
			type = false;
		}
		while ((pos = genome_string.find(delimiter)) != std::string::npos)
		{
			string mot = genome_string.substr(0, pos);
			genome_string.erase(0, pos + delimiter.length());
			if (mot != "")
			{
				genome.push_back(mot);
			}
		}
	}
}

string ParseRequestServer::getMaladie()
{
	return maladie;
}

list<string> ParseRequestServer::getGenome()
{
	return genome;
}

ParseRequestServer::~ParseRequestServer()
{
}
