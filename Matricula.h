#include "Estudiante.h"
#include "Grupo.h"
#include "Periodo.h"
class Matricula
{
private:
	Estudiante* estu;
	Grupo* grupo;
	Periodo* periodo;
	string fechaMatricula;
public:
	Matricula(Estudiante*, Grupo*, Periodo*, string);
	Matricula();
	~Matricula();
	Estudiante* getEstudiante();
	Grupo* getGrupo();
	Periodo* getPeriodo();
	string getfechaMatricula();
	string mostrarMatricula();
};

