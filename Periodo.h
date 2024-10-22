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
	void agregarCurso(Curso* nuevoCurso);
	listaCursos* getlistaCursos();
	string mostrarPeriodo();
};

