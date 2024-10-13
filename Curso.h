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
	string precio;
	bool estado;
	Curso* siguiente;

public:
	Curso(string, string, string, string, bool);
	Curso();
	~Curso();
	void setNombre(string);
	void setId(string);
	void setHoras(string);
	void setPrecio(string);
	void setEstado(bool);
	void setsiguiente(Curso*);
	string getNombre();
	string getId();
	string getHoras();
	string getPrecio();
	bool getEstado();
	Curso* getsiguiente();
	string mostrarCurso();


};
#endif // !CURSO_H



