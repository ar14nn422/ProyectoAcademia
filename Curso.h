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

public:
	Curso(string, string, string, string, bool);
	Curso();
	~Curso();
	void setNombre(string);
	void setId(string);
	void setHoras(string);
	void setPrecio(string);
	void setEstado(bool);
	string getNombre();
	string getId();
	string getHoras();
	string getPrecio();
	bool getEstado();
	string mostrarCurso();


};

