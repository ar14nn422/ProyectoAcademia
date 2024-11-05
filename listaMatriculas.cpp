#include "listaMatriculas.h"

listaMatriculas::listaMatriculas(nodoMatricula* act, nodoMatricula* prim)
{
	actual = act;
	primero = prim;
}

listaMatriculas::listaMatriculas()
{
	actual = nullptr;
	primero = nullptr;
}

listaMatriculas::~listaMatriculas()
{
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}

void listaMatriculas::insertarMatricula(Matricula* nuevaMatricula)
{
	nodoMatricula* nuevo = new nodoMatricula(nuevaMatricula, nullptr);

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

Matricula* listaMatriculas::getPrimero()
{
	return primero->getMatricula();
}

string listaMatriculas::mostrarListaMatriculas()
{
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << "---------------------------" << endl
			<< actual->mostrarNodo()<< endl;
		actual = actual->getSig();
	}
	return s.str();
}
bool listaMatriculas::validarMatriculaCurso(Estudiante* estudiante, Curso* curso)//
{
	actual=primero; 
	while (actual != nullptr) {
		if (actual->getMatricula()->getEstudiante() == estudiante && actual->getMatricula()->getCurso() == curso) {
			return true;  
		}
		actual = actual->getSig();  
	}
	return false;
}


