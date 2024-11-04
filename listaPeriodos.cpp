#include "listaPeriodos.h"

listaPeriodos::listaPeriodos(nodoPeriodo* act, nodoPeriodo* prim)
{
	actual = act;
	primero = prim;
}

listaPeriodos::listaPeriodos()
{
	actual = nullptr;
	primero = nullptr;
}

void listaPeriodos::insertarPeriodos(Periodo* nuevoPeriodo)
{

	nodoPeriodo* nuevo = new nodoPeriodo(nuevoPeriodo, nullptr);

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
nodoPeriodo* listaPeriodos::getPrimero()
{
	return primero;
}

int listaPeriodos::contarCursos() {
	int totalCursos = 0;
	actual = primero;

	while (actual != nullptr) {
		totalCursos += actual->getPeriodo()->contarCursos(); 
		actual = actual->getSig();
	}

	return totalCursos;
}

Periodo* listaPeriodos::buscarPeriodoPorNum(int numPeriodo)
{
	actual = primero; 
	while (actual != nullptr) {
		
		if (actual->getPeriodo()->getNumPeriodo() == numPeriodo) {
			return actual->getPeriodo(); 
		}
		actual = actual->getSig(); 
	}
	return nullptr;
}

string listaPeriodos::mostrarLP()
{
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->mostrarNodo() << endl;
		actual = actual->getSig();
	}
	return s.str();
}

listaPeriodos::~listaPeriodos()
{
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}
