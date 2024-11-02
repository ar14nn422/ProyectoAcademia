#include "Periodo.h"

Periodo::Periodo(int num, string inicio, string fin)
{
	numPeriodo = num;
	mesInicio = inicio;
	mesFinal = fin;
	cursos = new listaCursos();
}

Periodo::Periodo()
{
	numPeriodo = 0;
	mesInicio = " ";
	mesFinal = " ";
	cursos = nullptr;
}

Periodo::~Periodo()//
{
}

int Periodo::getNumPeriodo()
{
	return numPeriodo;
}

void Periodo::agregarCurso(Curso* nuevoCurso)
{
	cursos->insertarCurso(nuevoCurso);
}

listaCursos* Periodo::getlistaCursos()
{
	return cursos;
}

string Periodo::mostrarPeriodo()
{
	stringstream s;
	s << "Periodo numero" << numPeriodo << endl
		<< "Mes de inicio: " << mesInicio << endl
		<< "Mes de finalizacion: " << mesFinal << endl;
	return s.str();
}

string Periodo::mostrarCursosP()
{
	stringstream s;
	s << "Lista de cursos del periodo indicado" << endl
		<< "-------------------------------------"<<endl
	    << cursos->mostrarLC() << endl;
	return s.str();
}

