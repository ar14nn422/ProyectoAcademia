#include "listaEstu.h"
#include <sstream>
listaEstu::listaEstu(nodoEstu* ac, nodoEstu* prim)
{
	actual = ac;
	primero = prim;
}

listaEstu::listaEstu()
{
	actual = nullptr;
	primero = nullptr;
}

listaEstu::~listaEstu()
{
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}

void listaEstu::insertarEstu(Estudiante* estu)
{
	nodoEstu* nuevo = new nodoEstu(estu, nullptr);

	if (primero == nullptr) {
		primero = nuevo;
	}
	else {
		actual = primero;
		while (actual->getSig() != nullptr) {
			actual = actual->getSig();
		}
		actual->setSig(nuevo);
	}
}

string listaEstu::mostrarLE()
{
	actual = primero;
	stringstream s;
	while (actual != nullptr) {
		s << actual->mostrarNodoE() << endl;
		actual = actual->getSig();
	}
	return s.str();
}

Estudiante* listaEstu::buscarEstuPorId(string idEst)
{
	actual = primero;
	while (actual != nullptr) {
		if (actual->getEstu()->getId() == idEst) {
			return actual->getEstu();
		}
		actual = actual->getSig();
	}
	return nullptr;
}
