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



void listaGrupos::insertarGrupo(Grupo* grupo)
{
    Grupo* nuevo = new Grupo(grupo->getNumeroGrupo(), grupo->getCapacidad(), grupo->getHorario(), grupo->getCurso(), grupo->getProfesor());

    nodoEstu* actualEstu = grupo->getListaEstu(); 
    while (actualEstu != nullptr) {
       
        Estudiante* nuevoEstudiante = new Estudiante(*actualEstu->getEstu());
        nuevo->matricularEstudiante(nuevoEstudiante);
        actualEstu = actualEstu->getSig();
    }

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
}

string listaGrupos::mostrarLG()
{
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
        s << "---------------------------"<<endl
		  << actual->mostrarGrupo() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}
