#include "listaGrupos.h"

listaGrupos::listaGrupos(Grupo* act, Grupo* prim)
{
	actual = act;
	primero = prim;
}

listaGrupos::listaGrupos()
{
	actual = nullptr;
	primero = nullptr;
}

listaGrupos::~listaGrupos()
{
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

/*void listaGrupos::insertarGrupo(Grupo* grupo)
{
	Grupo* nuevo = new Grupo(grupo->getNumeroGrupo(), grupo->getCapacidad(), grupo->getHorario(), grupo->getCurso(), grupo->getProfesor());

	if (primero == nullptr) {
		primero = nuevo;
	}
	else {
		actual = primero;
		while (actual->getSiguiente() != nullptr) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
}*/

string listaGrupos::mostrarLG()
{
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->mostrarGrupo() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}
