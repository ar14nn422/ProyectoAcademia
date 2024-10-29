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
#include "listaPeriodos.h"
#include "Matricula.h"
#include "Factura.h"
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

	Curso* c1 = new Curso("Mate", "64747", "3horas", 20000, true);
	Curso* c2 = new Curso("Español", "98083", "3horas", 20000, true);
	Grupo* g1 = new Grupo(01, 30, h1, c1, p2);
	Grupo* g2 = new Grupo(02, 30, h2, c1, p1);


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


	Periodo* P1 = new Periodo(1, "Enero", "Marzo");
	Periodo* P2 = new Periodo(2, "Abril", "Junio");

	P1->agregarCurso(c1);
	P2->agregarCurso(c2);
	listaPeriodos* listaper = new listaPeriodos();
	listaper->insertarPeriodos(P1);
	listaper->insertarPeriodos(P2);
	cout << listaper->mostrarLP();
	
	listaCursos* listaCursosEstudiante = new listaCursos();

	if (g1->matricularEstudiante(e1)&& g2->matricularEstudiante(e1)) {
		Matricula* m1 = new Matricula(e1, g1, P1, "03-01-2024");
		Matricula* m2 = new Matricula(e1, g2, P1, "03-01-2024");
		listaCursosEstudiante->insertarCurso(c1);
		listaCursosEstudiante->insertarCurso(c2);
		Factura* f1 = new Factura(e1,listaper,listaCursosEstudiante);
		cout << f1->mostrarFactura();
	}
	else {
		cout << "No se pudo matricular en " << c1->getNombre() << endl;
	}

	return 0;
}