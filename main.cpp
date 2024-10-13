#include "listaProf.h"
#include "Profesor.h"
#include "listaEstu.h"
#include "Estudiante.h"
#include <iostream>
int main() {
	Profesor* p1 = new Profesor("Mario", "742834u2874", "84845157", "mario@jfsj", "Bachiller");
	Profesor* p2 = new Profesor("Carla", "475834", "87646467", "carla@", "Lic");
	listaProf* l1=new listaProf();
	Estudiante* e1 = new Estudiante("Mar", "475834", "87646467", "mar@", "Dibujo");
	listaEstu* l2 = new listaEstu();
	l1->insertarProfesor(p1);
	l1->insertarProfesor(p2);
	l2->insertarEstu(e1);
	cout << "Lista de profesores:" << endl;
	cout<<l1->mostrarLP();
	cout << "Lista de estudiantes:" << endl;
	cout<<l2->mostrarLE();

	return 0;
}