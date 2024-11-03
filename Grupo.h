#ifndef GRUPO_H
#define GRUPO_H


#include "listaEstu.h"
#include "Curso.h" 
#include "Horario.h"
#include "Profesor.h"
#include "Estudiante.h"
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
    Grupo(int , int , Horario , Curso* , Profesor* );
    Grupo();
    ~Grupo();

    int getNumeroGrupo();
    int getCapacidad();
    int getCantidadAlumnos();
    Horario getHorario();
    Curso* getCurso();
    Profesor* getProfesor();
    nodoEstu* getListaEstu();

    bool incrementarAlumnos();
    void decrementarAlumnos();
    bool matricularEstudiante(Estudiante*);
    string mostrarEstudiantes();
    bool asignarProfesor(Profesor*);

    Grupo* getSiguiente();
    void setSiguiente(Grupo*);
    string mostrarGrupo();

};


#endif //GRUPO_H