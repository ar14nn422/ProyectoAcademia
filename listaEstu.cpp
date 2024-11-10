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
void listaEstu::eliminarEstudiante(Estudiante* estudiante) {
	actual=primero;  
	nodoEstu* anterior = nullptr;

	while (actual != nullptr) {
		if (actual->getEstu() == estudiante) {  
			if (anterior == nullptr) {  
				setPrimero(actual->getSig());  
			}
			else {
				anterior->setSig(actual->getSig());  
			}
			delete actual;  
			return;  
		}
		anterior = actual;
		actual = actual->getSig();  
	}
}


nodoEstu* listaEstu::getPrimero()
{
	return primero;
}

void listaEstu::setPrimero(nodoEstu* prim)
{
	primero = prim;
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

bool listaEstu::verificarDuplicadoAlumno(string id) {
	actual = primero; 
	while (actual != nullptr) {
		if (actual->getEstu()->getId() == id) {
			return true;  
		}
		actual = actual->getSig(); 
	}
	return false; 
}

void listaEstu::guardarEnArchivo(string nombreArchivo) {
	ofstream f(nombreArchivo); 

	if (!f.is_open()) {
		cerr << "Error al abrir el archivo para guardar los datos." << endl;
		return;
	}

	actual = primero;
	while (actual != nullptr) {
		Estudiante* estu = actual->getEstu();
		f << estu->getId() << ","
			<< estu->getNombre() << ","
			<< estu->getTelefono() << ","
			<< estu->getEmail() << ","
			<< estu->getEsp()<< endl;

		actual = actual->getSig();
	}

	f.close();
}


void listaEstu::cargarDesdeArchivo( string nombreArchivo) {
	ifstream f(nombreArchivo); 

	if (!f.is_open()) {
	cerr << "No se encontro un archivo de datos.Comenzando con una lista vacia." << endl;
		return;
	}
	

	string linea;
	while (getline(f, linea)) {
		stringstream s(linea);
		string id, nombre, num, email, especialidad;

		
		getline(s, id, ',');
		getline(s, nombre, ',');
		getline(s, num, ',');
		getline(s, email, ',');
		getline(s, especialidad, ',');

		
		Estudiante* estu = new Estudiante(nombre, id, num, email, especialidad);
		insertarEstu(estu);
	}

	f.close();
}

