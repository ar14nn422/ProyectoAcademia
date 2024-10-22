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
	void insertarCurso(Curso*);
	string mostrarLC();
};
#endif // !LISTACURSOS_H



