#include "listaProf.h"
#include "Profesor.h"
#include <iostream>
int main() {
	Profesor* p1 = new Profesor("Mario", "742834u2874", "84845157", "mario@jfsj", "Bachiller");
	listaProf* l1=new listaProf();
	l1->insertarProfesor(p1);
	cout << "Lista de profesores:" << l1->mostrarLP();
	delete p1;
	delete l1;
	return 0;
}