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

Grupo::Grupo()
{
    numeroGrupo = 0;
    capacidad = 0;
    cantidadAlumnos = 0;
    curso = nullptr;
    profesor = nullptr;
    listaEstudiantes = nullptr;
    siguiente = nullptr;

}

Grupo::~Grupo()//
{
    
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

Curso* Grupo::getCurso()
{
    return curso;
}

Profesor* Grupo::getProfesor() {
    return profesor;
}

nodoEstu* Grupo::getListaEstu()
{
    return listaEstudiantes;
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

bool Grupo::matricularEstudiante(Estudiante* estudiante) {
    if (cantidadAlumnos < capacidad) {
        nodoEstu* nuevoNodo = new nodoEstu(estudiante, nullptr);
        if (listaEstudiantes == nullptr) {
            listaEstudiantes = nuevoNodo;
        }
        else {
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

string Grupo::mostrarEstudiantes() {
    stringstream s;
    nodoEstu* actual = listaEstudiantes;
    s << "Estudiantes matriculados en el grupo " << numeroGrupo << ":"<< endl;
    while (actual != nullptr) {
        s << actual->getEstu()->getNombre() << endl; 
        actual = actual->getSig(); 
    }
    return s.str();
}

Grupo* Grupo::getSiguiente() {
    return siguiente;
}

void Grupo::setSiguiente(Grupo* sig) {
    siguiente = sig;
}

string Grupo::mostrarGrupo()
{
    stringstream s;    
    s << "Curso:" << curso->mostrarCurso() << endl;
    s << "Numero de grupo:" << numeroGrupo << endl;
    s << "Capacidad:" << capacidad << endl;
    s << "Cantidad de alumnos:" << cantidadAlumnos << endl;
    s << "Horario:" << horario.mostrarHorario() << endl;
    s << "Profesor" << profesor->mostrarProfe() << endl;
    s<<mostrarEstudiantes();
    return s.str();
}
