#include "nodoProf.h"
#include "listaGrupos.h"
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
	bool verificarDuplicadoProfesor(string);
	void guardarEnArchivo(string);
	void cargarDesdeArchivo(string);

};

