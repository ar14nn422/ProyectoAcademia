#include "listaCursos.h"
#include <sstream>
#include <fstream>

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

void listaCursos::eliminarCursoPorId(string idCurso) {
	actual=primero;
	Curso* cursoAnterior = nullptr;

	while (actual != nullptr) {
		if (actual->getId() == idCurso) {
			if (cursoAnterior == nullptr) {
				primero = actual->getsiguiente();
			}
			else {
				cursoAnterior->setSiguiente(actual->getsiguiente());
			}

			
			return;  
		}

		cursoAnterior = actual;
		actual= actual->getsiguiente();
	}

	
}

Curso* listaCursos::buscarCursoPorId(string idCurso)
{
	actual = primero;
	while (actual != nullptr) {
		if (actual->getId() == idCurso) {
			return actual;
		}
		actual = actual->getsiguiente();
	}
	return nullptr;
}

bool listaCursos::verificarDuplicadoCurso(string id) {
	actual = primero; 
	while (actual != nullptr) {
		if (actual->getId() == id) {
			return true;  
		}
		actual = actual->getsiguiente();  
	}
	return false;  
}


void listaCursos::guardarEnArchivo(string nombreArchivo) {
	ofstream f(nombreArchivo);

	if (!f.is_open()) {
		cerr << "Error al abrir el archivo para guardar datos." << endl;
		return;
	}

	actual = primero;
	while (actual != nullptr) {
		f << actual->getNombre() << ","
			<< actual->getId() << ","
			<< actual->getPrecio() << ","
			<< actual->getHoras() << ","
			<< actual->getEstado() << endl;

		

		actual = actual->getsiguiente();
	}

	f.close();
}


void listaCursos::cargarDesdeArchivo(string nombreArchivo) {
	ifstream f(nombreArchivo);

	if (!f.is_open()) {
		cerr << "No se encontro el archivo de datos. Comenzando con una lista vacia." << endl;
		return;
	}

	string linea;
	while (getline(f, linea)) {
		if (linea.empty()) {
			continue;
		}

		stringstream s(linea);
		string nombreCurso, idCurso, horas;
		int precio = 0;
		bool estado = true; 

		getline(s, nombreCurso, ',');
		getline(s, idCurso, ',');
		getline(s, horas, ',');
		s >> precio;

		Curso* curso = new Curso(nombreCurso, idCurso, horas, precio, estado);
		insertarCurso(curso);
	}

	f.close();
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
