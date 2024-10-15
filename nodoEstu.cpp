#include "nodoEstu.h"
#include <iostream>
nodoEstu::nodoEstu(Estudiante* est, nodoEstu* sg)
{
	estu = est;
	sig = sg;
}

nodoEstu::nodoEstu()
{
	estu = nullptr;
	sig = nullptr;
}


void nodoEstu::setEstu(Estudiante* est)
{
	estu = est;
}

void nodoEstu::setSig(nodoEstu* sg)
{
	sig = sg;
}

Estudiante* nodoEstu::getEstu()
{

	return estu;
}

nodoEstu* nodoEstu::getSig()
{
	return sig;
}

string nodoEstu::mostrarNodoE()
{
	return estu->mostrarEstu();
}
nodoEstu::~nodoEstu()
{
	delete estu;
}