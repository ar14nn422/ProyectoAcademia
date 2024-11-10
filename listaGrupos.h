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
	Grupo* seleccionarGrupoPorNumero(int);
	bool existeProfesorEnGrupos(Profesor*);
	void guardarEnArchivo(string);
	void cargarDesdeArchivo(string, listaEstu*);
	string mostrarCursosYGruposPorProfesor(Profesor* );
	string mostrarCursosYGrupos();
	string mostrarGruposPorCurso(Curso*);
	bool hayGruposConMismoNum(int);
};
#endif // !LISTAGRUPOS_H



