#include "stdafx.h"
#include "AnalysePartielle.h"
#include "Analyse.h"

AnalysePartielle::AnalysePartielle(list<string> * listeMaladies, string nomFichier): Analyse(nomFichier)
{
	maladies = listeMaladies;
}

AnalysePartielle::~AnalysePartielle()
{
}