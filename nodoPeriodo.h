#ifndef NODOPERIODO_H
#define NODOPERIODO_H
#include "Periodo.h"
class nodoPeriodo
{
private:
	Periodo* periodo;
	nodoPeriodo* sig;
public:
	nodoPeriodo(Periodo*, nodoPeriodo*);
	nodoPeriodo();
	Periodo* getPeriodo();
	nodoPeriodo* getSig();
	void setPeriodo(Periodo*);
	void setSig(nodoPeriodo*);
	string mostrarNodo();
	~nodoPeriodo();
};

#endif // !NODOPERIODO_H




