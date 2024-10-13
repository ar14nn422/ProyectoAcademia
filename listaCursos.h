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

