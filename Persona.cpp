#include "Persona.h"

Persona::Persona(std::string nom, std::string i, std::string tel, std::string mail)
	: nombre(nom), id(i), telefono(tel), email(mail) {}

Persona::Persona()
{
	nombre = " ";
	id = " ";
	telefono = " ";
	email = " ";
}

string Persona::getNombre()
{
	return nombre; 
}

string Persona::getId()
{
	return id;
}

string Persona::getTelefono()
{
	return telefono;
}

string Persona::getEmail()
{
	return email;
}

void Persona::setNombre(string nom)
{
	nombre = nom; 
}

void Persona::setId(string i)
{
	id = i; 
}

void Persona::setEmail(string mail)
{
	email = mail; 
}

void Persona::setTel(string tel)
{
	telefono = tel;
}
