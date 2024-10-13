#include "Estudiante.h"
#include "sstream"

Estudiante::Estudiante(string nom, string id, string num, string email, string esp)
{
	setNombre(nom);
	setId(id);
	setTel(num);
	setEmail(email);
	especialidad = esp;
}

Estudiante::Estudiante()
{
	especialidad = " ";
}

Estudiante::~Estudiante()
{
}

void Estudiante::setEsp(string esp)
{
	especialidad = esp;
}

string Estudiante::getEsp()
{
	return especialidad;
}

string Estudiante::mostrarEstu()
{
	stringstream s;
	s << "Nombre:" << getNombre() << endl;
	s << "Id:" << getId() << endl;
	s << "Numero telefonico:" << getTelefono() << endl;
	s << "Correo:" << getEmail() << endl;
	s << "Especialidad:" << especialidad << endl;
	return s.str();
}
