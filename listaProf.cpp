#include "ListaProf.h"

listaProf::listaProf(nodoProf* act, nodoProf* prim)
{
	actual = act;
	primero = prim;
}

listaProf::listaProf()
{
	actual = nullptr;
	primero = nullptr;
}

void listaProf::insertarProfesor(Profesor* profe)
{
	nodoProf* nuevo = new nodoProf(profe, nullptr); 

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

Profesor* listaProf::buscarProfePorId(string idProfe)
{
	nodoProf* actual = primero;
	while (actual != nullptr) {
		if (actual->getProfe()->getId() == idProfe) {
			return actual->getProfe();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

string listaProf::mostrarLP()
{
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->mostrarNodo() << endl;
		actual = actual->getSig();
	}
	return s.str();
}

listaProf::~listaProf()
{
	while (primero != NULL) { 
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}
