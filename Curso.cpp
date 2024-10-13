#include "Curso.h"
#include <sstream>
Curso::Curso(string nom, string i, string hrs, string prec, bool est)
{
	nombre = nom;
	id = i;
	horas = hrs;
	precio = prec;
	estado = est;
	siguiente=nullptr;
}

Curso::Curso()
{
	nombre = " ";
	id = " ";
	horas = " ";
	precio = " ";
	estado = true;
	siguiente=nullptr;
}

Curso::~Curso()
{
}

void Curso::setNombre(string nom)
{
	nombre = nom;
}

void Curso::setId(string i)
{
	id = i;
}

void Curso::setHoras(string hrs)
{
	horas = hrs;
}

void Curso::setPrecio(string prec)
{
	precio = prec;
}

void Curso::setEstado(bool est)
{
	estado = est;
}

void Curso::setsiguiente(Curso * cur) {
	siguiente = cur;
}

Curso * Curso::getsiguiente() {
	return siguiente;
}

string Curso::getNombre()
{
	return nombre;
}

string Curso::getId()
{
	return id;
}

string Curso::getHoras()
{
	return horas;
}

string Curso::getPrecio()
{
	return precio;
}

bool Curso::getEstado()
{
	return estado;
}

string Curso::mostrarCurso()
{
	stringstream s;
	s << "Nombre del curso:" << nombre << endl;
	s << "Id del curso:" << id << endl;
	s << "Horas:" <<horas<< endl;
	s << "Precio:" <<precio<< endl;
	s << "Estado:" << estado << endl;
	return s.str();
}
