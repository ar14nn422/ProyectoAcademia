#include "Estudiante.h"
#include "Grupo.h"
#include "Periodo.h"
class Matricula
{
private:
	Estudiante* estu;
	Curso* curso;
	Periodo* periodo;
	string fechaMatricula;
public:
	Matricula(Estudiante*, Curso*, Periodo*, string);
	Matricula();
	~Matricula();
	Estudiante* getEstudiante();
	Curso* getCurso();
	Periodo* getPeriodo();
	string getfechaMatricula();
	string mostrarMatricula();
	string mostrarGruposPorCursoYPeriodo(Periodo*, Curso*);
};

