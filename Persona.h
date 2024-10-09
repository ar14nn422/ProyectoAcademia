#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std; 

class Persona {
protected:
    string nombre;
    string id;
    string telefono;
    string email;

public:
   
    Persona(string nom, string i, string tel, string mail);
        

        string getNombre();
        string getId();
        string getTelefono();
        string getEmail();


        void setNombre(string nom);
        void setId(string i);
        void setEmail(string mail);
};

#endif
