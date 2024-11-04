#include "nodoMatricula.h"

nodoMatricula::nodoMatricula(Matricula* matri, nodoMatricula* sg)
{
	matricula = matri;
	sig = sg;
}

nodoMatricula::nodoMatricula()
{
	matricula = nullptr;
	sig = nullptr;
}

Matricula* nodoMatricula::getMatricula()
{
	return matricula;
}

nodoMatricula* nodoMatricula::getSig()
{
	return sig;
}

void nodoMatricula::setMatricula(Matricula* matri)
{
	matricula = matri;
}

void nodoMatricula::setSig(nodoMatricula* sg)
{
	sig = sg;
}

string nodoMatricula::mostrarNodo()
{
	return matricula->mostrarMatricula();
}

nodoMatricula::~nodoMatricula()
{
	delete matricula;
}
