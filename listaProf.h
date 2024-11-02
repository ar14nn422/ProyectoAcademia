#include "nodoProf.h"
class listaProf
{
private:
	nodoProf* actual;
	nodoProf* primero;
public:
	listaProf(nodoProf*, nodoProf*);
	listaProf();
	void insertarProfesor(Profesor*);
	Profesor* buscarProfePorId(string);
	string mostrarLP();
	~listaProf();

};

