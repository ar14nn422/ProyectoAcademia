#include "listaCursos.h"
#include <sstream>

listaCursos::listaCursos(Curso* act, Curso* prim)
{
	actual = act;
	primero = prim;

}

listaCursos::listaCursos()
{
	actual = nullptr;
	primero = nullptr;

}

listaCursos::~listaCursos()
{
	while (primero != NULL) {
		actual = primero;
		primero = primero->getsiguiente();
		delete actual;
	}
}

Curso* listaCursos::getPrimero()
{
	return primero;
}


int listaCursos::cantidadCursos()
{
	int totalCursos = 0;
	actual = primero; 

	while (actual != nullptr) { 
		totalCursos++;
		actual = actual->getsiguiente(); 
	}

	return totalCursos;
}



void listaCursos::insertarCurso(Curso* curso)
{
	Curso* nuevo = new Curso(curso->getNombre(), curso->getId(), curso->getHoras(), curso->getPrecio(), curso->getEstado());

	if (primero == nullptr) {
		primero = nuevo;
	}
	else {
		actual = primero;
		while (actual->getsiguiente() != nullptr) {
			actual = actual->getsiguiente();
		}
		actual->setsiguiente(nuevo);
	}
}

string listaCursos::mostrarLC()
{
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->mostrarCurso() << endl
		  << "-----------------------------" << endl;
		actual = actual->getsiguiente();
	}
	return s.str();
}
