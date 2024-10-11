#include "NodoProf.h"

nodoProf::nodoProf(Profesor* pr, nodoProf* sg)
{
	profe = pr;
	sig = sg;
}

nodoProf::nodoProf()
{
	profe = nullptr;
	sig = nullptr;
}

Profesor* nodoProf::getProfe()
{
	return profe;
}

nodoProf* nodoProf::getSig()
{
	return sig;
}

void nodoProf::setProfe(Profesor* pr)
{
	profe = pr;
}

void nodoProf::setSig(nodoProf* sg)
{
	sig = sg;
}

string nodoProf::mostrarNodo()
{
	return profe->mostrarProfe();
}



nodoProf::~nodoProf()
{
	delete profe;
}
