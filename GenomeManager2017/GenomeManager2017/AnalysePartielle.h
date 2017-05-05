#pragma once
#include "Analyse.h"
class AnalysePartielle :
	public Analyse
{
public:
	AnalysePartielle();
	~AnalysePartielle();

private:
	list <string> * maladies;
};

