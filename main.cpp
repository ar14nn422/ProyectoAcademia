#include "listaProf.h"
#include "Profesor.h"
#include "listaEstu.h"
#include "Estudiante.h"
#include "Curso.h"
#include "listaCursos.h"
#include "Grupo.h"
#include "listaGrupos.h"
#include "Horario.h"
#include "listaGrupos.h"
#include "Periodo.h"
#include "Matricula.h"
#include <iostream>
int main() {
	Horario h1("12", "3", "Viernes");
	Horario h2("7", "10", "Lunes");
	Profesor* p1 = new Profesor("Mario", "742834u2874", "84845157", "mario@jfsj", "Bachiller");
	Profesor* p2 = new Profesor("Carla", "475834", "87646467", "carla@", "Lic");

	listaProf* l1=new listaProf();

	Estudiante* e1 = new Estudiante("Mar", "475834", "87646467", "mar@", "Dibujo");
	Estudiante* e2 = new Estudiante("Simon", "292382", "848462773", "simon@", "Arqui");
	Estudiante* e3 = new Estudiante("Jose Pablo", "929393", "88124782", "jose@", "Meca");
	listaEstu* l2 = new listaEstu();

	Curso* c1 = new Curso("Mate", "64747", "3horas", "20000", true);
	Curso* c2 = new Curso("Español", "98083", "3horas", "20000", true);

	Grupo* g1 = new Grupo(01, 30, h1, c1, p2);
	Grupo* g2 = new Grupo(01, 30, h2, c1, p1);


	listaGrupos* l4 = new listaGrupos();
	g1->matricularEstudiante(e1);
	g2->matricularEstudiante(e2);
	g1->matricularEstudiante(e3);
	l4->insertarGrupo(g1);
	l4->insertarGrupo(g2);
	listaCursos* l3 = new listaCursos();
	l3->insertarCurso(c1);
	l3->insertarCurso(c2);
	l1->insertarProfesor(p1);
	l1->insertarProfesor(p2);
	l2->insertarEstu(e1);
	l2->insertarEstu(e3);
	//cout << "Lista de profesores:" << endl;
	//cout<<l1->mostrarLP();
	//cout << "Lista de estudiantes:" << endl;
	//cout<<l2->mostrarLE();
	//cout << "Lista de cursos:" << endl;
	//cout << l3->mostrarLC();
	//cout << "Grupo:" << endl;
	//cout << g1->mostrarGrupo();
	cout << "lISTA DE GRUPOS PARA EL CURSO:" << endl;
	cout<<c1->getNombre() << endl;
	cout << l4->mostrarLG();
	Periodo* P1 = new Periodo(1, "Enero", "Marzo");
	Periodo* P2 = new Periodo(2, "Abril", "Junio");
	Periodo* P3 = new Periodo(3, "Julio", "Setiembre");
	Periodo* P4 = new Periodo(4, "Octubre", "Diciembre");
	P1->agregarCurso(c1);
	//cout << P1->mostrarPeriodo() << endl;
	//cout << P2->mostrarPeriodo() << endl;
	//cout << P3->mostrarPeriodo() << endl;
	//cout << P4->mostrarPeriodo() << endl;
	
	Matricula* matricula = new Matricula(e1, g1, P1, "10-03-24");

	// Mostrar la información de la matrícula
	//cout << matricula->mostrarMatricula() << endl;
	return 0;
}