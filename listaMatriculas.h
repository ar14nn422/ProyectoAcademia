#include "nodoMatricula.h"
class listaMatriculas
{
private:
	nodoMatricula* actual;
	nodoMatricula* primero;
public:
	listaMatriculas(nodoMatricula*, nodoMatricula*);
	listaMatriculas();
	~listaMatriculas();
	void insertarMatricula(Matricula*);
	Matricula* buscarMatriculaPorEstudianteYCurso(Estudiante*, Curso*);
	void eliminarMatricula(Matricula*);
	Matricula* getPrimero();
	string mostrarListaMatriculas();
	bool validarMatriculaCurso(Estudiante*, Curso*);
};

