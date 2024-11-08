#ifndef NODOESTU_H
#define NODOESTU_H
#include "nodoEstu.h"
#include <fstream>   
#include <iostream>
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
	nodoEstu* getPrimero();
	string mostrarLE();
	Estudiante* buscarEstuPorId(string);
	void guardarEnArchivo(string );
	void cargarDesdeArchivo(string);
};
#endif // !NODOESTU_H



