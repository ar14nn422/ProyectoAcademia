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
		s << actual->getPeriodo()->mostrarPeriodo() << endl;
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

bool listaPeriodos::existePeriodoNum(string num) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getPeriodo()->getNumPeriodo() == num) {
			return true; 
		}
		actual = actual->getSig();
	}
	return false; 
}

void listaPeriodos::guardarEnArchivo(string nombreArchivo) {
	ofstream f(nombreArchivo);
	if (!f.is_open()) {
		cerr << "Error al abrir el archivo para guardar datos." << endl;
		return;
	}

	actual = primero;
	while (actual != nullptr) {
		f << "Periodo numero " << actual->getPeriodo()->getNumPeriodo() << endl
			<< "Mes de inicio: " << actual->getPeriodo()->getInicio() << endl
			<< "Mes de finalizacion: " << actual->getPeriodo()->getFinal() << endl;

		listaGrupos* grupos = actual->getPeriodo()->getlistaGrupos();
		if (grupos != nullptr) {
			f << grupos->mostrarLG();  
		}

		if (actual->getSig() != nullptr) {
			f << "---------------------------"<<endl;
		}

		actual = actual->getSig();
	}

	f.close();
}


	

void listaPeriodos::cargarDesdeArchivo(string nombreArchivo) {
	ifstream f(nombreArchivo);
	if (!f.is_open()) {
		cerr << "Error al abrir el archivo para cargar datos." << endl;
		return;
	}

	string linea;
	while (getline(f, linea)) {
		if (linea.empty() || linea == "---------------------------") continue;

		if (linea.find("Periodo numero") != string::npos) {
			string numPeriodo, mesInicio, mesFinal;

			numPeriodo = linea.substr(linea.find("numero") + 7); 

			getline(f, linea);  
			mesInicio = linea.substr(linea.find(":") + 1); 

			getline(f, linea);  
			mesFinal = linea.substr(linea.find(":") + 1); 

			Periodo* periodo = new Periodo(numPeriodo, mesInicio, mesFinal);
			insertarPeriodos(periodo);

			while (getline(f, linea) && linea != "---------------------------") {
				
				if (linea.find("Numero de grupo:") != string::npos) {
					int numGrupoStr = 0;
					int capacidad = 0, cantidadAlumnos = 0;
					string horaInicio, horaFin, diaSemana;

					
					getline(f, linea);  
					numGrupoStr = stoi(linea.substr(linea.find(":") + 1));

					
					getline(f, linea); 
					capacidad = stoi(linea.substr(linea.find(":") + 1));

					
					getline(f, linea);  
					cantidadAlumnos = stoi(linea.substr(linea.find(":") + 1));

					
					getline(f, linea);  
					horaInicio = linea.substr(linea.find(":") + 1);

					
					getline(f, linea);  
					horaFin = linea.substr(linea.find(":") + 1);

					
					getline(f, linea);  
					diaSemana = linea.substr(linea.find(":") + 1);

					Horario h1(horaInicio, horaFin, diaSemana);

					Grupo* grupo = new Grupo(numGrupoStr, capacidad);
					grupo->setCantidadAlumnos(cantidadAlumnos);
					grupo->setHorario(h1);

					periodo->agregarGrupo(grupo);
				}
			}
		}
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
