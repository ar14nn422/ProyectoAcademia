#ifndef GRUPO_H
#define GRUPO_H
#include "Estudiante.h"
#include "Profesor.h"
#include "Horario.h"
#include <iostream>
#include "Curso.h"
#include "nodoEstu.h"

class Grupo {
private:
    int numeroGrupo;
    int capacidad;
    int cantidadAlumnos;
    Horario horario;
    Curso* curso;
    nodoEstu* listaEstudiantes;
    Profesor* profesor;
    Grupo* siguiente;
public:
    Grupo(int num, int cap, Horario hor, Curso* cur, Profesor* prof);
    Grupo();
    ~Grupo();

    int getNumeroGrupo();
    int getCapacidad();
    int getCantidadAlumnos();
    Horario getHorario();
    Curso* getCurso();
    Profesor* getProfesor();


    bool incrementarAlumnos();
    void decrementarAlumnos();
    bool matricularEstudiante(Estudiante* estudiante);
    void mostrarEstudiantes();

    Grupo* getSiguiente();
    void setSiguiente(Grupo* sig);
    string mostrarGrupo();

};


#endif //GRUPO_H