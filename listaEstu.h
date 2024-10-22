#ifndef NODOESTU_H
#define NODOESTU_H
#include "nodoEstu.h"
class listaEstu
{
private:
	nodoEstu* actual;
	nodoEstu* primero;
public:
	listaEstu(nodoEstu*,nodoEstu*);
	listaEstu();
	~listaEstu();
	void insertarEstu(Estudiante*);
	string mostrarLE();
};
#endif // !NODOESTU_H



