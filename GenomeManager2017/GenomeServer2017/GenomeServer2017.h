
// GenomeServer2017.h�: fichier d'en-t�te principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CGenomeServer2017App�:
// Consultez GenomeServer2017.cpp pour l'impl�mentation de cette classe
//

class CGenomeServer2017App : public CWinApp
{
public:
	CGenomeServer2017App();

// Substitutions
public:
	virtual BOOL InitInstance();

// Impl�mentation

	DECLARE_MESSAGE_MAP()
};

extern CGenomeServer2017App theApp;