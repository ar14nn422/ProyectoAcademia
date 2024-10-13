#include "Horario.h"

Horario::Horario(string inicio, string fin, string dia) {
    horaInicio = inicio;
    horaFin = fin;
    diaSemana = dia;
}

Horario::Horario() {
    horaInicio = " ";
    horaFin = " ";
    diaSemana = " ";
}

Horario::~Horario() {
}

void Horario::setHoraInicio(string inicio) {
    horaInicio = inicio;

}

void Horario::setHoraFin(string fin) {
    horaFin = fin;
}

void Horario::setDiaSemana(string dia) {
    diaSemana = dia;
}

string Horario::getHoraInicio() {
    return horaInicio;
}

string Horario::getHoraFin() {
    return horaFin;
}

string Horario::getDiaSemana() {
    return diaSemana;
}

string Horario::mostrarHorario() {
    stringstream s;
    s << "Hora de inicio:" << getHoraInicio() << endl;
    s << "Hora de fin:" << getHoraFin() << endl;
    s << "Dia de la semana:" << getDiaSemana() << endl;
    return s.str();
}
