#pragma once
#include "GenomeManager2017Dlg.h"

class ResponseHandler
{
public:
	ResponseHandler(CGenomeManager2017Dlg* w);
	~ResponseHandler();
	CGenomeManager2017Dlg* getWindow();
private:
	CGenomeManager2017Dlg* window;
};

