#ifndef LISTAPERIODOS_H
#define LISTAPERIODOS_H
#include "nodoPeriodo.h"
class listaPeriodos
{
private:
	nodoPeriodo* actual;
	nodoPeriodo* primero;
public:
	listaPeriodos(nodoPeriodo*, nodoPeriodo*);
	listaPeriodos();
	void insertarPeriodos(Periodo*);
	nodoPeriodo* getPrimero();
	int contarCursos();
	Periodo* buscarPeriodoPorNum(int);
	string mostrarLP();
	~listaPeriodos();

};


#endif // !LISTAPERIODOS_H



