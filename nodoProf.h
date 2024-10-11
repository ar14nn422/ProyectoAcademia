#include "Profesor.h"
class nodoProf
{
private:
	Profesor* profe;
	nodoProf* sig;
public:
	nodoProf(Profesor*, nodoProf*);
	nodoProf();
	Profesor* getProfe();
	nodoProf* getSig();
	void setProfe(Profesor*);
	void setSig(nodoProf*);
	string mostrarNodo();
	~nodoProf();
};

