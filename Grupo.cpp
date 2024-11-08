#include "Grupo.h"
Grupo::Grupo(int num, int cap, Horario hor,Curso* curs) {
    numeroGrupo = num;
    capacidad = cap;
    cantidadAlumnos = 0;
    horario = hor;
    curso = curs;
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
    profesor = nullptr;
    listaEstudiantes = new listaEstu();
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



Profesor* Grupo::getProfesor() {
    return profesor;
}

listaEstu* Grupo::getListaEstu()
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
        listaEstudiantes->insertarEstu(estudiante);  
        cantidadAlumnos++;
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

Grupo* Grupo::getSiguiente() {
    return siguiente;
}

void Grupo::setSiguiente(Grupo* sig) {
    siguiente = sig;
}

string Grupo::mostrarGrupo()
{
    stringstream s;
    s << "Numero de grupo:" << numeroGrupo << endl
     << "Capacidad:" << capacidad << endl
     << "Cantidad de alumnos:" << cantidadAlumnos << endl
     << "Horario:" << horario.mostrarHorario() << endl;
    if (profesor != nullptr) {
        s << "Profesor: " << endl
            << profesor->mostrarProfe() << endl;
    }
    else {
        s << "Profesor no asignado." << endl;
    }
    s<<mostrarEstudiantes();
    return s.str();
}

bool Grupo::estaEstudianteMatriculado(Estudiante* estudiante, Curso* curso)
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

void Grupo::guardarEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::app);  
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para guardar los grupos." << endl;
        return;
    }

 
    archivo << numeroGrupo << ","
        << capacidad << ","
        << cantidadAlumnos << ","
        << curso->getId() << "," 
        << horario.getHoraInicio() << "," << horario.getHoraFin() << "," 
        << profesor->getId() << "," 
        << listaEstudiantes->mostrarLE();  

    archivo.close();
    cout << "Datos del grupo guardados correctamente." << endl;
}

//void Grupo::cargarDesdeArchivo(const string& nombreArchivo) {
//    ifstream archivo(nombreArchivo);
//    if (!archivo.is_open()) {
//        cout << "No se encontro un archivo de grupos. Comenzando con una lista vacia." << endl;
//        return;
//    }
//
//    string linea;
//    while (getline(archivo, linea)) {
//        stringstream ss(linea);
//        string numGrupo, cap, cantAlumnos, codCurso, horaInicio, horaFin, idProfesor;
//
//        getline(ss, numGrupo, ',');
//        getline(ss, cap, ',');
//        getline(ss, cantAlumnos, ',');
//        getline(ss, codCurso, ',');
//        getline(ss, horaInicio, ',');
//        getline(ss, horaFin, ',');
//        getline(ss, idProfesor, ',');
//
//        // Convertir las cadenas en los tipos adecuados
//        int numeroGrupo = stoi(numGrupo);
//        int capacidad = stoi(cap);
//        int cantidadAlumnos = stoi(cantAlumnos);
//        int horaInicioInt = stoi(horaInicio);
//        int horaFinInt = stoi(horaFin);
//
//        // Buscar el curso por código, profesor por ID, etc.
//        Curso* curso = buscarCursoPorCodigo(codCurso);
//        Profesor* profesor = buscarProfesorPorId(idProfesor);
//        Horario horario(horaInicioInt, horaFinInt);
//
//        // Crear un nuevo grupo con los datos cargados
//        Grupo* nuevoGrupo = new Grupo(numeroGrupo, capacidad, horario, curso);
//        nuevoGrupo->asignarProfesor(profesor);
//
//        // Cargar los estudiantes (si los hay)
//        listaEstu* estudiantes = new listaEstu();
//        string idEstudiante;
//        while (getline(ss, idEstudiante, ',')) {
//            Estudiante* estudiante = buscarEstudiantePorId(idEstudiante);
//            if (estudiante != nullptr) {
//                estudiantes->insertarEstu(estudiante);
//            }
//        }
//        nuevoGrupo->setListaEstu(estudiantes);
//
//        // Insertar el grupo en la lista de grupos (o manejarlo según tu implementación)
//        insertarGrupo(nuevoGrupo);
//    }
//
//    archivo.close();
//    cout << "Datos de los grupos cargados correctamente." << endl;
//}


