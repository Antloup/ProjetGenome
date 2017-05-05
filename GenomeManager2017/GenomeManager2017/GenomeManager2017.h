
// GenomeManager2017.h : fichier d'en-tête principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CGenomeManager2017App :
// Consultez GenomeManager2017.cpp pour l'implémentation de cette classe
//

class CGenomeManager2017App : public CWinApp
{
public:
	CGenomeManager2017App();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern CGenomeManager2017App theApp;