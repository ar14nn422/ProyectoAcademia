#include "Matricula.h"
class nodoMatricula
{
private:
	Matricula* matricula;
	nodoMatricula* sig;
public:
	nodoMatricula(Matricula*, nodoMatricula*);
	nodoMatricula();
	Matricula* getMatricula();
	nodoMatricula* getSig();
	void setMatricula(Matricula*);
	void setSig(nodoMatricula*);
	string mostrarNodo();
	~nodoMatricula();
};

