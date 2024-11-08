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

Periodo* listaPeriodos::buscarPeriodoPorNum(string numPeriodo)
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

void listaPeriodos::guardarEnArchivo(string nombreArchivo) {
	ofstream f(nombreArchivo);

	if (!f.is_open()) {
		cerr << "Error al abrir el archivo para guardar datos." << endl;
		return;
	}

	actual = primero;
	while (actual != nullptr) {
		f << actual->getPeriodo()->getNumPeriodo() << ","
			<< actual->getPeriodo()->getInicio() << ","
			<< actual->getPeriodo()->getFinal() << endl;

		listaGrupos* grupos = actual->getPeriodo()->getlistaGrupos();
		if (grupos != nullptr) {
			f << grupos->mostrarLG() << endl;
		}

		actual = actual->getSig();
	}

	f.close();
}
	

void listaPeriodos::cargarDesdeArchivo(string nombreArchivo) {
	ifstream f(nombreArchivo);  

	if (!f.is_open()) { 
		cerr << "No se encontro el archivo de datos. Comenzando con una lista vacia." << endl;
		return;
	}

	string linea;
	while (getline(f, linea)) {  
		if (linea == "") {
			continue;  
		}

		stringstream s(linea);
		string numPeriodo, mesInicio, mesFinal;

		getline(s, numPeriodo, ',');  
		getline(s, mesInicio, ',');  
		getline(s, mesFinal, ','); 

		//s << numPeriodo  << mesInicio  << mesFinal << endl;

		Periodo* periodo = new Periodo(numPeriodo, mesInicio, mesFinal);

		insertarPeriodos(periodo);  
	}

	f.close();  
}

string listaPeriodos::mostrarPeriodosYGrupos() {
	stringstream s;
	actual = primero;  

	while (actual != nullptr) {
		s << "Periodo " << actual->getPeriodo()->getNumPeriodo() << ": "
			<< actual->getPeriodo()->getInicio() << " - "
			<< actual->getPeriodo()->getFinal() << endl;

		listaGrupos* listaGruposPeriodo = actual->getPeriodo()->getlistaGrupos();

		if (listaGruposPeriodo != nullptr) {
			s << listaGruposPeriodo->mostrarCursosYGrupos(); 
		}
		else {
			s << "No hay grupos asignados a este periodo."<<endl;
		}

		actual = actual->getSig();  
	}
	return s.str();
}
