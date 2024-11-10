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
	void eliminarEstudiante(Estudiante*);
	nodoEstu* getPrimero();
	void setPrimero(nodoEstu*);
	string mostrarLE();
	Estudiante* buscarEstuPorId(string);
	bool verificarDuplicadoAlumno(string);
	void guardarEnArchivo(string );
	void cargarDesdeArchivo(string);
};
#endif // !NODOESTU_H



