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
string listaProf::mostrarProfesoresSinGrupo(listaGrupos* listaG) {
	stringstream s;
	actual=primero;  
	s << "Profesores sin grupo asignado:\n";

	while (actual != nullptr) {
		bool estaAsignado = listaG->existeProfesorEnGrupos(actual->getProfe());

		if (!estaAsignado) {
			s << "ID: " << actual->getProfe()->getId() << " - Nombre: " << actual->getProfe()->getNombre() << endl;
		}
		actual = actual->getSig();  
	}
	return s.str();
}

void listaProf::guardarEnArchivo(string nombreArchivo) {
	ofstream f(nombreArchivo);

	if (!f.is_open()) {
		cerr << "Error al abrir el archivo para guardar los datos." << endl;
		return;
	}

	actual = primero;
	while (actual != nullptr) {
		Profesor* profe = actual->getProfe();
		f << profe->getNombre() << ","
			<< profe->getId() << ","
			<< profe->getTelefono() << ","
			<< profe->getEmail() << ","
			<< profe->getGradoA() << endl;

		actual = actual->getSig();
	}

	f.close();
}


void listaProf::cargarDesdeArchivo(string nombreArchivo) {
	ifstream f(nombreArchivo);

	if (!f.is_open()) {
		cerr << "No se encontro un archivo de datos.Comenzando con una lista vacia." << endl;
		return;
	}


	string linea;
	while (getline(f, linea)) {
		stringstream s(linea);
		string id, nombre, num, email, gradoAcademico;


		getline(s, id, ',');
		getline(s, nombre, ',');
		getline(s, num, ',');
		getline(s, email, ',');
		getline(s, gradoAcademico, ',');


		Profesor* profe = new Profesor(nombre, id, num, email, gradoAcademico);
		insertarProfesor(profe);
	}

	f.close();
}
