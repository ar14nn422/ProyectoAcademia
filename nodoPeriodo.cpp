#include "nodoPeriodo.h"

nodoPeriodo::nodoPeriodo(Periodo* per, nodoPeriodo* sg)
{
	periodo = per;
	sig = sg;
}

nodoPeriodo::nodoPeriodo()
{
	periodo = nullptr;
	sig = nullptr;
}

Periodo* nodoPeriodo::getPeriodo()
{
	return periodo;
}

nodoPeriodo* nodoPeriodo::getSig()
{
	return sig;
}

void nodoPeriodo::setPeriodo(Periodo* per)
{
	periodo = per;
}

void nodoPeriodo::setSig(nodoPeriodo* sg)
{
	sig = sg;
}

string nodoPeriodo::mostrarNodo()
{
	return periodo->mostrarPeriodo();
}

nodoPeriodo::~nodoPeriodo()
{
	delete periodo;
}
