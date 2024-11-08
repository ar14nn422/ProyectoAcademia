#ifndef PERIODO_H
#define PERIODO_H
#include "listaCursos.h"
#include "listaGrupos.h"
#include "listaCursos.h"
class Periodo
{
private:
	string numPeriodo;
	string mesInicio;
	string mesFinal;
	listaGrupos* grupos;
	listaCursos* cursos;
public:
	Periodo(string, string, string);
	Periodo();
	~Periodo();
	string getNumPeriodo();
	string getInicio();
	string getFinal();
	int contarCursos();
	void agregarGrupo(Grupo* );
	void setlistaGrupos(listaGrupos*);
	listaGrupos* getlistaGrupos();
	string mostrarPeriodo();
	string mostrarGruposP();
};
#endif // !PERIODO_H



