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
};
#endif // !LISTAGRUPOS_H



