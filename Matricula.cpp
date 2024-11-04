#include "Matricula.h"

Matricula::Matricula(Estudiante* est, Curso* curs, Periodo* per, string feMa)
{
	estu = est;
	curso=curs;
	periodo = per;
	fechaMatricula = feMa;
}

Matricula::Matricula()
{
	estu = nullptr;
	curso = nullptr;
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

Curso* Matricula::getCurso()
{
	return curso;
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
		//<< "En el grupo: " <<  << " del curso: " << curso->mostrarCurso() << endl
		<< "En la fecha: " << fechaMatricula << " para el " << periodo->mostrarPeriodo() << endl;
	return s.str();
}

string Matricula::mostrarGruposPorCursoYPeriodo(Periodo* periodo, Curso* curso) {
    stringstream s;
	 
		if (curso == nullptr || periodo == nullptr) {
			s << "Curso o periodo no definido." << endl;
		}

		listaGrupos* gruposDelPeriodo = periodo->getlistaGrupos(); 
		Grupo* grupoActual = gruposDelPeriodo->getPrimero();

		cout << "Grupos disponibles para el curso: " << curso->getNombre() << " en el periodo " << periodo->getNumPeriodo() << ":" << endl;

		while (grupoActual != nullptr) {
			if (grupoActual->getCurso()->getId() == curso->getId()) { 
				s << "Grupo " << grupoActual->getNumeroGrupo()
					<< ": Capacidad " << grupoActual->getCapacidad() << endl; 
			}
			grupoActual = grupoActual->getSiguiente();
		}
		return s.str();
}