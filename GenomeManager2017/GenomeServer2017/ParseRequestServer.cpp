#include "stdafx.h"
#include "ParseRequestServer.h"


ParseRequestServer::ParseRequestServer(string genome_string)
{
	genome = new list<string>();

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
			type = 0;
			size_t pos = genome_string.find(delimiter);
			string mot = genome_string.substr(0, pos);
			genome_string.erase(0, pos + delimiter.length());
			maladie = mot;
		}
		else if(mot == "GET DISEASES")
		{
			type = 1;
		}
		else
		{
			type = 2;
		}
		delimiter = ";";
		while ((pos = genome_string.find(delimiter)) != std::string::npos)
		{
			string mot = genome_string.substr(0, pos);
			genome_string.erase(0, pos + delimiter.length());
			if (mot != "")
			{
				genome->push_back(mot);
			}
		}
	}
}

string ParseRequestServer::getMaladie()
{
	return maladie;
}

list<string>* ParseRequestServer::getGenome()
{
	return genome;
}

int ParseRequestServer::getType()
{
	return type;
}

ParseRequestServer::~ParseRequestServer()
{
}
