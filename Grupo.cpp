

#include "Grupo.h"
Grupo::Grupo(int num, int cap, Horario hor, Curso* cur, Profesor* prof) {
    numeroGrupo = num;
    capacidad = cap;
    cantidadAlumnos = 0;
    horario = hor;
    curso = cur;
    profesor = prof;
    listaEstudiantes = nullptr;
    siguiente = nullptr;
}



int Grupo::getNumeroGrupo() {
    return numeroGrupo;
}

int Grupo::getCapacidad() {
    return capacidad;
}

int Grupo::getCantidadAlumnos() {
    return cantidadAlumnos;
}

Horario Grupo::getHorario() {
    return  horario;
}

Profesor * Grupo::getProfesor() {
    return profesor;
}

bool Grupo::incrementarAlumnos() {
    if (cantidadAlumnos < capacidad) {
        cantidadAlumnos++;
        return true;
    }
    return false;
}

void Grupo::decrementarAlumnos() {
    if (cantidadAlumnos > 0)
        cantidadAlumnos--;
}

bool Grupo::matricularEstudiante(Estudiante *estudiante) {
    if (cantidadAlumnos < capacidad) {
        nodoEstu* nuevoNodo = new nodoEstu(estudiante, nullptr);
        if (listaEstudiantes == nullptr) {
            listaEstudiantes = nuevoNodo;
        } else {
            nodoEstu* temp = listaEstudiantes;
            while (temp->getSig() != nullptr) {
                temp = temp->getSig();
            }
            temp->setSig(nuevoNodo);
        }
        cantidadAlumnos++;
        return true;
    }
    return false;
}

void Grupo::mostrarEstudiantes() {
    nodoEstu* temp = listaEstudiantes;
    while (temp != nullptr) {
        cout << temp->mostrarNodoE() << endl;
        temp = temp->getSig();
    }
}

Grupo * Grupo::getSiguiente() {
    return siguiente;
}

void Grupo::setSiguiente(Grupo *siguiente) {
    siguiente = siguiente;
}
