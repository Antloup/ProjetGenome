#include "stdafx.h"
#include "ResponseHandler.h"
#include "SocketClient.h"

ResponseHandler::ResponseHandler(CGenomeManager2017Dlg * w)
{
	window = w;
	SocketClient* sc = new SocketClient(this);
	//Traiter demande
	sc->Send("Demande Analyse", strlen("Demande Analyse"));
}


ResponseHandler::~ResponseHandler()
{
}

CGenomeManager2017Dlg* ResponseHandler::getWindow()
{
	return window;
}
