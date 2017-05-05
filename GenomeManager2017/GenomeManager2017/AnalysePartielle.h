#pragma once
#include "Analyse.h"

class AnalysePartielle :
	public Analyse
{
public:
	AnalysePartielle(list<string> * listeMaladies, string nomFichier);
	~AnalysePartielle();

private:
	list <string> * maladies;
};