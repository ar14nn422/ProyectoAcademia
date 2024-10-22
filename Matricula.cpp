#include "Matricula.h"

Matricula::Matricula(Estudiante* est, Grupo* grup, Periodo* per, string feMa)
{
	estu = est;
	grupo = grup;
	periodo = per;
	fechaMatricula = feMa;
}

Matricula::Matricula()
{
	estu = nullptr;
	grupo = nullptr;
	periodo = nullptr;
	fechaMatricula = " ";
}

Matricula::~Matricula()
{
}

Estudiante* Matricula::getEstudiante()
{
	return estu;
}

Grupo* Matricula::getGrupo()
{
	return grupo;
}

Periodo* Matricula::getPeriodo()
{
	return periodo;
}

string Matricula::getfechaMatricula()
{
	return fechaMatricula;
}

string Matricula::mostrarMatricula()
{
	stringstream s;
	s << "Matricula para el estudiante: " << estu->getNombre() << endl
		<< "En el grupo: " << grupo->getNumeroGrupo() << " del curso: " << grupo->getCurso()->getNombre() << endl
		<< "En la fecha: " << fechaMatricula << " para el " << periodo->mostrarPeriodo() << endl;
	return s.str();
}
