#include "listaGrupos.h"

listaGrupos::listaGrupos(Grupo* act, Grupo* prim)
{
	actual = act;
	primero = prim;
}

listaGrupos::listaGrupos()
{
	actual = nullptr;
	primero = nullptr;
}

listaGrupos::~listaGrupos()
{
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}



void listaGrupos::insertarGrupo(Grupo* grupo)
{
    Grupo* nuevo = new Grupo(grupo->getNumeroGrupo(), grupo->getCapacidad(),  grupo->getHorario(),grupo->getCurso());

    nodoEstu* actualEstu = grupo->getListaEstu()->getPrimero(); 
    while (actualEstu != nullptr) {
       
        Estudiante* nuevoEstudiante = new Estudiante(*actualEstu->getEstu());
        nuevo->matricularEstudiante(nuevoEstudiante);
        actualEstu = actualEstu->getSig();
    }

    if (primero == nullptr) {
        primero = nuevo;
    }
    else {
        actual = primero;
        while (actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
}

Grupo* listaGrupos::getPrimero()
{
    return primero;
}

string listaGrupos::mostrarLG()
{
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
        s << "---------------------------"<<endl
		  << actual->mostrarGrupo() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}

int listaGrupos::cantidadCursos()
{
    int contador = 0;
    actual = primero; 

    while (actual != nullptr) {
        contador++;
        actual = actual->getSiguiente(); 
    }

    return contador;
}

Grupo* listaGrupos::buscarGrupoPorNumYCurso(int numGrupo,string idCurso)
{
   actual = primero; 
    while (actual != nullptr) {
       
        if (actual->getNumeroGrupo() == numGrupo && actual->getCurso() != nullptr && actual->getCurso()->getId() == idCurso) {
            return actual; 
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

Grupo* listaGrupos::seleccionarGrupoPorNumero(int numeroGrupo) {
    actual=primero; 
    while (actual != nullptr) {
        if (actual->getNumeroGrupo() == numeroGrupo) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr; 
}

bool listaGrupos::existeProfesorEnGrupos(Profesor* profesor) {
    actual=primero;  

    while (actual != nullptr) {
        if (actual->getProfesor() == profesor) {
            return true;  
        }
        actual = actual->getSiguiente();  
    }
    return false;  
}

void listaGrupos::guardarEnArchivo(string nombreArchivo) {
    ofstream f(nombreArchivo);
    if (!f.is_open()) {
        cerr << "Error al abrir el archivo para guardar datos." << endl;
        return;
    }

    actual = primero;
    while (actual != nullptr) {
        Grupo* grupo = actual->getGrupo(); 

        f << "Numero de grupo: " << grupo->getNumeroGrupo() << endl
            << "Capacidad: " << grupo->getCapacidad() << endl
            << "Cantidad de alumnos: " << grupo->getCantidadAlumnos() << endl;

        Horario horario = actual->getHorario();
        f << "Hora de inicio: " << horario.getHoraInicio() << endl
            << "Hora de fin: " << horario.getHoraFin() << endl
            << "Dia de la semana: " << horario.getDiaSemana() << endl;

        if (grupo->getCurso() != nullptr) {
            f << "Curso: " << grupo->getCurso()->getId() << endl;  
        }
        else {
            f << "Curso no asignado." << endl;
        }

        if (grupo->getProfesor() != nullptr) {
            f << "Profesor: " << grupo->getProfesor()->mostrarProfe() << endl;
        }
        else {
            f << "Profesor no asignado." << endl;
        }

        f << "---------------------------" << endl;

        actual = actual->getSiguiente();
    }

    f.close();
}


void listaGrupos::cargarDesdeArchivo(string nombreArchivo) {
    ifstream f(nombreArchivo);
    if (!f.is_open()) {
        cerr << "Error al abrir el archivo para cargar datos." << endl;
        return;
    }

    string linea;
    while (getline(f, linea)) {
        if (linea.empty() || linea == "---------------------------") continue;

        if (linea.find("Numero de grupo:") != string::npos) {
            int numeroGrupo = stoi(linea.substr(linea.find(":") + 1));
            int capacidad, cantidadAlumnos;
            string horaInicio, horaFin, diaSemana;

            getline(f, linea);
            capacidad = stoi(linea.substr(linea.find(":") + 1));

            getline(f, linea);
            cantidadAlumnos = stoi(linea.substr(linea.find(":") + 1));

            getline(f, linea);  
            horaInicio = linea.substr(linea.find(":") + 1);

            getline(f, linea);  
            horaFin = linea.substr(linea.find(":") + 1);

            getline(f, linea);  
            diaSemana = linea.substr(linea.find(":") + 1);

            Horario* horario = new Horario(horaInicio, horaFin, diaSemana);

            Grupo* grupo = new Grupo(numeroGrupo, capacidad);
            grupo->setCantidadAlumnos(cantidadAlumnos);
            grupo->setHorario(*horario);

            getline(f, linea);
            if (linea.find("Profesor:") != string::npos) {
                string nombreProfesor = linea.substr(linea.find(":") + 1);
                Profesor* profesor = new Profesor(nombreProfesor); 
                grupo->asignarProfesor(profesor);
            }

            insertarGrupo(grupo);
        }
    }

    f.close();
}






string listaGrupos::mostrarCursosYGruposPorProfesor( Profesor* profesor) {//////
    stringstream s;
    actual=primero;

    s<< "Cursos y grupos impartidos por el Profesor " << profesor->getNombre() << endl;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->getProfesor() == profesor) {
            s << "Curso: " << actual->getCurso()->getNombre()
                << " - Grupo: " << actual->getNumeroGrupo() << endl;
            encontrado = true;
        }
        actual = actual->getSiguiente(); 
    }

    if (!encontrado) {
        s << "Este profesor no tiene grupos asignados"<<endl;
    }
    return s.str();
}

string listaGrupos::mostrarCursosYGrupos() {
    stringstream s;
     actual = primero;  

    while (actual != nullptr) {
        s << "Grupo: " << actual->getNumeroGrupo() << endl;

        if (actual->getCurso() != nullptr) {
            s << "Curso: " << actual->getCurso()->getNombre() << endl;
        }
        else {
            s << "No hay curso asignado a este grupo."<<endl;
        }

        s << "Numero de estudiantes en el grupo: " << actual->getCantidadAlumnos() << "\n";

        actual = actual->getSiguiente();
    }

    return s.str();
}

string listaGrupos::mostrarGruposPorCurso(Curso* curso) {
    stringstream s;
    actual = primero;  

    
    while (actual != nullptr) {
        if (actual->getCurso() == curso) {
            s << "Grupo: " << actual->getNumeroGrupo() << endl;

        }
        actual = actual->getSiguiente();  
    }

   
    if (actual == nullptr) {
        s << "No se encontraron grupos asociados al curso seleccionado." << endl;
    }

    return s.str();  
}
bool listaGrupos::hayGruposConMismoNum(int numeroGrupo) {
    actual = primero;
    int contador = 0;

    while (actual != nullptr) {
        if (actual->getNumeroGrupo() == numeroGrupo) {
            contador++;
            if (contador > 1) {
                return true;  
            }
        }
        actual = actual->getSiguiente();
    }

    return false;
}

