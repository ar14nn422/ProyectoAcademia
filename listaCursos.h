#ifndef LISTACURSOS_H
#define LISTACURSOS_H
#include "Curso.h"

class listaCursos
{
private:
	Curso* actual;
	Curso* primero;

public:
	listaCursos(Curso*, Curso*);
	listaCursos();
	~listaCursos();
	Curso* getPrimero();
	int cantidadCursos();
	void insertarCurso(Curso*);
	Curso* buscarCursoPorId(string);
	string mostrarLC();
};
#endif // !LISTACURSOS_H



