#ifndef HORARIO_H
#define HORARIO_H

using namespace std;
#include <iostream>
#include <string>
#include <sstream>

class Horario {
private:
    string horaInicio;
    string horaFin;
    string diaSemana;

public:
    Horario(string inicio, string fin, string dia);
    Horario();
    ~Horario();
    void setHoraInicio(string);
    void setHoraFin(string);
    void setDiaSemana(string);
    string getHoraInicio();
    string getHoraFin();
    string getDiaSemana();
    string mostrarHorario();


};



#endif //HORARIO_H