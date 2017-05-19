#include "stdafx.h"
#include "RequestHandler.h"
#include "SocketS2C.h"

RequestHandler::RequestHandler(SocketServer* ss, CGenomeServer2017Dlg* w)
{
	this->window = w;
	this->ssc = new SocketS2C(this);
	bool bResult = ss->Accept(*this->ssc);
}

RequestHandler::~RequestHandler()
{
}

CGenomeServer2017Dlg* RequestHandler::getWindow(){
	return window; 
}