#include "Profesor.h"
Profesor::Profesor(string nombre, string id, string num, string email, string gA):Persona(nombre, id, num, email) {

	gradoAcademico = gA;
}
Profesor::Profesor() {
	gradoAcademico = " ";
};

string Profesor::getGradoA()
{
	return gradoAcademico;
}
void Profesor::setGradoA(string gA)
{
	gradoAcademico = gA;
}
string Profesor::mostrarProfe()
{
	stringstream s;
	s << "Nombre:" << getNombre() << endl;
	s << "Id:" << getId() << endl;
	s << "Numero telefonico:" << getTelefono() << endl;
	s << "Correo:" << getEmail() << endl;
	s << "Grado academico:" << getGradoA()<< endl;
	return s.str();
}
;