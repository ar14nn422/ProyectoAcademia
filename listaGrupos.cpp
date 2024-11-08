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
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }

    actual = primero;  
    while (actual != nullptr) {
        f << actual->getNumeroGrupo() << ","
            << actual->getCapacidad() << ","
            << actual->getCantidadAlumnos() << ","
            << actual->getCurso()->getNombre() << ","  
            << actual->getProfesor()->getNombre() << endl;  

        actual = actual->getSiguiente();  
    }

    f.close();
    
}

void listaGrupos::cargarDesdeArchivo(string nombreArchivo) {
    ifstream f(nombreArchivo);

    if (!f.is_open()) {
        cerr << "No se encontro el archivo de datos. Comenzando con una lista vacia." << endl;
        return;
    }

    string linea;
    while (getline(f, linea)) {
        stringstream s(linea);

        int numeroGrupo, capacidad, cantidadAlumnos;
        string nombreCurso, nombreProfesor, idCurso;

        getline(s, nombreCurso, ',');
        getline(s, idCurso, ',');
        getline(s, nombreProfesor, ',');
        s >> numeroGrupo >> capacidad >> cantidadAlumnos;

        Curso* curso = new Curso(nombreCurso, idCurso);
        Profesor* profesor = new Profesor(nombreProfesor);

        Grupo* grupo = new Grupo(numeroGrupo, capacidad, Horario(), curso);
        grupo->asignarProfesor(profesor);

        insertarGrupo(grupo);  
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
     actual = primero;  // Suponiendo que tienes un nodo inicial llamado 'primero'

    // Recorrer todos los grupos en la lista
    while (actual != nullptr) {
        // Mostrar el nombre del grupo
        s << "Grupo: " << actual->getNumeroGrupo() << "\n";

        // Mostrar el nombre del curso asignado a este grupo
        if (actual->getCurso() != nullptr) {
            s << "Curso: " << actual->getCurso()->getNombre() << "\n";
        }
        else {
            s << "No hay curso asignado a este grupo.\n";
        }

        // Mostrar otros detalles del grupo si es necesario (como la cantidad de estudiantes, profesor, etc.)
        // Por ejemplo, si el grupo tiene un número de estudiantes:
        s << "Número de estudiantes en el grupo: " << actual->getCantidadAlumnos() << "\n";

        // Continuar con el siguiente grupo
        actual = actual->getSiguiente();
    }

    return s.str();
}

string listaGrupos::mostrarGruposPorCurso(Curso* curso) {
    stringstream s;
    actual = primero;  // Inicia desde el primer grupo de la lista

    // Recorre todos los grupos de la lista
    while (actual != nullptr) {
        // Verifica si el grupo está asociado al curso seleccionado
        if (actual->getCurso() == curso) {
            s << "Grupo: " << actual->getNumeroGrupo() << endl;

        }
        actual = actual->getSiguiente();  // Pasa al siguiente nodo
    }

    // Si no se encontraron grupos asociados, se indica en el string
    if (actual == nullptr) {
        s << "No se encontraron grupos asociados al curso seleccionado." << endl;
    }

    return s.str();  // Retorna el string con la información de los grupos
}