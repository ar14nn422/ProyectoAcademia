#include "Persona.h"
#include <sstream>
class Profesor : public Persona {
private:
	string gradoAcademico;
public:
	Profesor(string, string, string, string, string);
	Profesor();
	string getGradoA();
	void setGradoA(string);
	string mostrarProfe();
};
