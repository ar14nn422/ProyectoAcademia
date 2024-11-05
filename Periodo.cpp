#include "Periodo.h"

Periodo::Periodo(int num, string inicio, string fin)
{
	numPeriodo = num;
	mesInicio = inicio;
	mesFinal = fin;
	grupos = new listaGrupos();
}

Periodo::Periodo()
{
	numPeriodo = 0;
	mesInicio = " ";
	mesFinal = " ";
	grupos = nullptr;
}

Periodo::~Periodo()//
{
}

int Periodo::getNumPeriodo()
{
	return numPeriodo;
}

int Periodo::contarCursos()
{
	return grupos->cantidadCursos();
}

void Periodo::agregarGrupo(Grupo* nuevoGrupo)
{
	grupos->insertarGrupo(nuevoGrupo);
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




