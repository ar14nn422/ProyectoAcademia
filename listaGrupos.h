#ifndef LISTAGRUPOS_H
#define LISTAGRUPOS_H
#include "Grupo.h"
class listaGrupos
{
private:
	Grupo* actual;
	Grupo* primero;
public:
	listaGrupos(Grupo*, Grupo*);
	listaGrupos();
	~listaGrupos();
	void insertarGrupo(Grupo*);
	Grupo* getPrimero();
	string mostrarLG();
	int cantidadCursos();
	Grupo* buscarGrupoPorNumYCurso(int,string);
	bool existeProfesorEnGrupos(Profesor*);
	void guardarEnArchivo(string);
	void cargarDesdeArchivo(string);
	string mostrarCursosYGruposPorProfesor(Profesor* profesor);
	string mostrarCursosYGrupos();
	string mostrarGruposPorCurso(Curso*);
};
#endif // !LISTAGRUPOS_H



