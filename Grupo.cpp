#include "Grupo.h"
Grupo::Grupo(int num, int cap, Horario hor,Curso* curs) {
    numeroGrupo = num;
    capacidad = cap;
    cantidadAlumnos = 0;
    horario = hor;
    curso = curs;
    idCurso = " ";
    profesor = nullptr;
    listaEstudiantes = new listaEstu();
    siguiente = nullptr;
}

Grupo::Grupo(int num, int cap)
{
    numeroGrupo = num;
    capacidad = cap;
    cantidadAlumnos = 0;
    curso = nullptr;
    idCurso = " ";
    profesor = nullptr;
    listaEstudiantes = new listaEstu();
    siguiente = nullptr;
}

Grupo::Grupo()
{
    numeroGrupo = 0;
    capacidad = 0;
    cantidadAlumnos = 0;
    curso = nullptr;
    idCurso = " ";
    profesor = nullptr;
    listaEstudiantes = new listaEstu();
    siguiente = nullptr;
}

Grupo::~Grupo()//
{
    delete listaEstudiantes;
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

void Grupo::setCantidadAlumnos(int cA)
{
    cantidadAlumnos = cA;
}

Horario Grupo::getHorario() {
    return  horario;
}

void Grupo::setHorario(Horario& hor) {
    horario = hor;
}

Profesor* Grupo::getProfesor() {
    return profesor;
}

void Grupo::setProfesor(Profesor* profe)
{
    if (profe != nullptr) {
        profesor = profe;
    }
}

listaEstu* Grupo::getListaEstu()
{
    return listaEstudiantes;
}

Grupo* Grupo::getGrupo()
{
    return this;
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
        listaEstudiantes->insertarEstu(estudiante);  
        cantidadAlumnos++;
        return true;
    }
    return false;
}
bool Grupo::desmatricularEstudiante(Estudiante* estudiante) {
    if (listaEstudiantes != nullptr) {
        listaEstudiantes->eliminarEstudiante(estudiante);  
        cantidadAlumnos--;  
        return true;
    }
    return false;
}
string Grupo::mostrarEstudiantes() {
    stringstream s;
    nodoEstu* actual = listaEstudiantes->getPrimero();  
    while (actual != nullptr) {
        s << actual->getEstu()->getNombre() << endl;
        actual = actual->getSig();  
    }
    return s.str();
}

bool Grupo::asignarProfesor(Profesor* profesorAsign)
{
    if (profesor != nullptr) {
        return false;
    }
    else {
        profesor = profesorAsign;
        return true;
    }
}

Curso* Grupo::getCurso()
{
    return curso;
}

void Grupo::setCurso(Curso* cr)
{
    curso = cr;
}



Grupo* Grupo::getSiguiente() {
    return siguiente;
}

void Grupo::setSiguiente(Grupo* sig) {
    siguiente = sig;
}

string Grupo::mostrarGrupo() {
    stringstream s;

    
    s << "Numero de grupo: " << numeroGrupo << endl
        << "Capacidad: " << capacidad << endl
        << "Cantidad de alumnos: " << cantidadAlumnos << endl;
        if (curso != nullptr) {
            s << "Curso: " << curso->getId() << endl; 
        }
        else {
            s << "Curso no asignado." << endl;
        }
        s<< "Horario:" << endl
        << horario.mostrarHorario() << endl; 
    if (profesor != nullptr) {
        s << "Profesor: " << profesor->mostrarProfe() << endl; 
    }
    else {
        s << "Profesor no asignado." << endl;
    }

    s << mostrarEstudiantes(); 

    return s.str(); 
}


bool Grupo::estaEstudianteMatriculadoCurso(Estudiante* estudiante, Curso* curso)
{
    nodoEstu* actualEstu = listaEstudiantes->getPrimero(); 
    while (actualEstu != nullptr) {
        if (actualEstu->getEstu() == estudiante) {  
            return true;  
        }
        actualEstu = actualEstu->getSig();  
    }
    return false;
}
bool Grupo::estaEstudianteMatriculado(Estudiante* estudiante)
{
    nodoEstu* actualEstu = listaEstudiantes->getPrimero();
    while (actualEstu != nullptr) {
        if (actualEstu->getEstu() == estudiante) {
            return true;
        }
        actualEstu = actualEstu->getSig();
    }
    return false;
}

