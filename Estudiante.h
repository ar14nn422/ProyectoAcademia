#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Persona.h"
class Estudiante:public Persona
{
private:
	string especialidad;
public:
	Estudiante(string, string, string, string, string);
	Estudiante();
	~Estudiante();
	void setEsp(string);
	string getEsp();
	string mostrarEstu();

};
#endif // !ESTUDIANTE_H



