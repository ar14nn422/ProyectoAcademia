#include "Periodo.h"

Periodo::Periodo(string num, string inicio, string fin)
{
	numPeriodo = num;
	mesInicio = inicio;
	mesFinal = fin;
	grupos = new listaGrupos();
	cursos = new listaCursos();
}

Periodo::Periodo()
{
	numPeriodo = " ";
	mesInicio = " ";
	mesFinal = " ";
	grupos = nullptr;
	cursos = nullptr;
}

Periodo::~Periodo()//
{
}

string Periodo::getNumPeriodo()
{
	return numPeriodo;
}

string Periodo::getInicio()
{
	return mesInicio;
}

string Periodo::getFinal()
{
	return mesFinal;
}

int Periodo::contarCursos()
{
	return grupos->cantidadCursos();
}

void Periodo::agregarGrupo(Grupo* nuevoGrupo)
{
	grupos->insertarGrupo(nuevoGrupo);
}

void Periodo::setlistaGrupos(listaGrupos* grupo)
{
	grupos = grupo;
}



listaGrupos* Periodo::getlistaGrupos()
{
	return grupos;
}

string Periodo::mostrarPeriodo()
{
	stringstream s;
	s << "Periodo numero " << numPeriodo << endl
		<< "Mes de inicio: " << mesInicio << endl
		<< "Mes de finalizacion: " << mesFinal << endl;
	return s.str();
}

string Periodo::mostrarGruposP()
{
	stringstream s;
	s << "Lista de grupos del periodo indicado" << endl
		<< "-------------------------------------"<<endl
	    << grupos->mostrarLG() << endl;
	return s.str();
}

string Periodo::mostrarGruposEstudiantePorPeriodo(Estudiante* estudiante, Periodo* periodo) {
	stringstream s;
	 

	bool estaMatriculado = false;
	Grupo* actualGrupo = periodo->getlistaGrupos()->getPrimero();  

	while (actualGrupo != nullptr) {
		if (actualGrupo->estaEstudianteMatriculado(estudiante)) {
			s << "Grupo ID: " << actualGrupo->getNumeroGrupo() << " - " << actualGrupo->getCurso()->getNombre() << endl;
			estaMatriculado = true;
		}
		actualGrupo = actualGrupo->getSiguiente();  
	}

	if (!estaMatriculado) {
		s << "El estudiante no está matriculado en ningun grupo en este periodo." << endl;
	}
	return s.str();
}


