#include "listaProf.h"
#include "Profesor.h"
#include "listaEstu.h"
#include "Estudiante.h"
#include "Curso.h"
#include "listaCursos.h"
#include "Grupo.h"
#include "listaGrupos.h"
#include "Horario.h"
#include <iostream>
int main() {
	Horario h1("12", "3", "Viernes");
	Profesor* p1 = new Profesor("Mario", "742834u2874", "84845157", "mario@jfsj", "Bachiller");
	Profesor* p2 = new Profesor("Carla", "475834", "87646467", "carla@", "Lic");
	listaProf* l1=new listaProf();
	Estudiante* e1 = new Estudiante("Mar", "475834", "87646467", "mar@", "Dibujo");
	listaEstu* l2 = new listaEstu();
	Curso* c1 = new Curso("Mate", "64747", "12-1", "20000", true);
	Grupo* g1 = new Grupo(03, 30, h1, c1, p2);
	g1->matricularEstudiante(e1);
	listaCursos* l3 = new listaCursos();
	l3->insertarCurso(c1);
	l1->insertarProfesor(p1);
	l1->insertarProfesor(p2);
	l2->insertarEstu(e1);
	cout << "Lista de profesores:" << endl;
	cout<<l1->mostrarLP();
	cout << "Lista de estudiantes:" << endl;
	cout<<l2->mostrarLE();
	cout << "Lista de cursos:" << endl;
	cout << l3->mostrarLC();
	cout << "Grupo:" << endl;
	cout << g1->mostrarGrupo();
	return 0;
}