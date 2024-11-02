#ifndef PERIODO_H
#define PERIODO_H
#include "listaCursos.h"
#include "listaGrupos.h"
class Periodo
{
private:
	int numPeriodo;
	string mesInicio;
	string mesFinal;
	listaCursos* cursos;
public:
	Periodo(int, string, string);
	Periodo();
	~Periodo();
	int getNumPeriodo();
	void agregarCurso(Curso* );
	listaCursos* getlistaCursos();
	string mostrarPeriodo();
	string mostrarCursosP();
};
#endif // !PERIODO_H



