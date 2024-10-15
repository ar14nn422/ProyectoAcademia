#ifndef NODOESTUDIANTE_H
#define NODOESTUDIANTE_H
#include "Estudiante.h"
class nodoEstu
{
private:
	Estudiante* estu;
	nodoEstu* sig;
public:
	nodoEstu(Estudiante*, nodoEstu*);
	nodoEstu();
	void setEstu(Estudiante*);
	void setSig(nodoEstu*);
	Estudiante* getEstu();
	nodoEstu* getSig();
	string mostrarNodoE();	
	~nodoEstu();
};
#endif // !NODOESTUDIANTE_H



