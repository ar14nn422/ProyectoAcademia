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
	listaGrupos* grupos;
public:
	Periodo(int, string, string);
	Periodo();
	~Periodo();
	int getNumPeriodo();
	int contarCursos();
	void agregarGrupo(Grupo* );
	listaGrupos* getlistaGrupos();
	string mostrarPeriodo();
	string mostrarGruposP();
};
#endif // !PERIODO_H



