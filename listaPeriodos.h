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
	Periodo* buscarPeriodoPorNum(string);
	string mostrarLP();
	~listaPeriodos();
	bool existePeriodoNum(string);
	void guardarEnArchivo(string);
	void cargarDesdeArchivo(string);
	string mostrarPeriodosYGrupos();

};


#endif // !LISTAPERIODOS_H



