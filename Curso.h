#ifndef CURSO_H
#define CURSO_H
#include <iostream>
using namespace std;
class Curso
{
private:
	string nombre;
	string id;
	string horas;	
	int precio;
	bool estado;
	Curso* siguiente;

public:
	Curso(string, string, string, int, bool);
	Curso();
	~Curso();
	void setNombre(string);
	void setId(string);
	void setHoras(string);
	void setPrecio(int);
	void setEstado(bool);
	void setsiguiente(Curso*);
	string getNombre();
	string getId();
	string getHoras();
	int getPrecio();
	bool getEstado();
	Curso* getsiguiente();
	string mostrarCurso();

};
#endif // !CURSO_H



