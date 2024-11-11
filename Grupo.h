#ifndef GRUPO_H
#define GRUPO_H


#include "listaEstu.h"
#include "Horario.h"
#include "Profesor.h"
#include "Estudiante.h"
#include "nodoEstu.h"
#include "Curso.h"

class Grupo {
private:
    int numeroGrupo;
    int capacidad;
    int cantidadAlumnos;
    Horario horario;
    Curso* curso;
    string idCurso;
    listaEstu* listaEstudiantes;
    Profesor* profesor;
    Grupo* siguiente;
public:
    Grupo(int , int , Horario ,Curso* );
    Grupo(int, int);
    Grupo();
    ~Grupo();

    int getNumeroGrupo();
    int getCapacidad();
    int getCantidadAlumnos();
    void setCantidadAlumnos(int);
    Horario getHorario();
    void setHorario(Horario&);
    Profesor* getProfesor();
    void setProfesor(Profesor*);
    listaEstu* getListaEstu();
    Grupo* getGrupo();

    bool incrementarAlumnos();
    void decrementarAlumnos();
    bool matricularEstudiante(Estudiante*);
    bool desmatricularEstudiante(Estudiante*);
    string mostrarEstudiantes();
    bool asignarProfesor(Profesor*);
    Curso* getCurso();
    void setCurso(Curso*);
    Grupo* getSiguiente();
    void setSiguiente(Grupo*);
    string mostrarGrupo();
    bool estaEstudianteMatriculadoCurso(Estudiante*, Curso*);
    bool estaEstudianteMatriculado(Estudiante* estudiante);
};


#endif //GRUPO_H