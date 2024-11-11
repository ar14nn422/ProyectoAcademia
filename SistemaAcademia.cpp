#include "SistemaAcademia.h"

SistemaAcademia::SistemaAcademia()
{
	listaCursosEstu = new listaCursos();
    listaCursosTotal = new listaCursos();
	listaPer = new listaPeriodos();
	listaProfes = new listaProf();
	listaEst = new listaEstu();
	listaG = new listaGrupos();
    matricular = new Matricula();
    listaM = new listaMatriculas();
}

void SistemaAcademia::mostrarMenu()
{
    
    int opcion;
    do {
        cout << "Menu Principal"<<endl;
        cout << "1- Submenu Administracion"<<endl;
        cout << "2- Submenu Matricula"<<endl;
        cout << "3- Submenu Busquedas e Informes"<<endl;
        cout << "4- Guardar los Datos en Archivos"<<endl;
        cout << "5- Salir"<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");
            subMenuAdministracion();
            break;
        case 2:
            system("cls");
            subMenuMatricula();
            break;
        case 3:
            system("cls");
            subMenuBusquedasInformes();
            break;
        case 4:
           
            guardarArchivos();
            break;
        case 5:
            cout << "Saliendo..."<<endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo."<<endl;
        }
        system("cls");
    } while (opcion != 5);
}

void SistemaAcademia::subMenuAdministracion()
{
    int opcion;

    do {
        cout << "Submenu Administracion General"<<endl;
        cout << "(1) Ingresar Profesor"<<endl;
        cout << "(2) Ingresar Estudiante"<<endl;
        cout << "(3) Ingresar Bloque o Periodo"<<endl;
        cout << "(4) Ingresar Curso"<<endl;
        cout << "(5) Ingresar Grupo"<<endl;
        cout << "(6) Asignar Profesor a Grupo"<<endl;
        cout << "(0) Regresar al Menu Principal"<<endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {    
            string nombre;
            string id;
            string num;
            string email;
            string gradoAcademico;
            system("cls");
            cout << "Ingrese el nombre del profesor: " << endl;
            cin >> nombre;
            cout << "Ingrese el id: " << endl;
            cin >> id;
            if (listaProfes->verificarDuplicadoProfesor(id) == false) {
            cout << "Ingrese el numero de telefono: " << endl;
            cin >> num;
            cout << "Ingrese el email: " << endl;
            cin >> email;
            cout << "Ingrese el grado academico: " << endl;
            cin >> gradoAcademico;
            Profesor* profe = new Profesor(nombre, id, num, email, gradoAcademico);
            listaProfes->insertarProfesor(profe);
            }
            else {
                cout << "Ya exixste un profesor con el id ingresado" << endl;
            }

            system("pause");
        }
            break;

        case 2:
        {
            string nombre;
            string id;
            string num;
            string email;
            string especialidad;
            system("cls");
            cout << "Ingrese el nombre del estudiante: " << endl;
            cin >> nombre;
            cout << "Ingrese el id: " << endl;
            cin >> id;
            if (listaEst->verificarDuplicadoAlumno(id) == false) {
              cout << "Ingrese el numero de telefono: " << endl;
              cin >> num;
              cout << "Ingrese el email: " << endl;
              cin >> email;
              cout << "Ingrese la especialidad: " << endl;
              cin >> especialidad;
              Estudiante* estu = new Estudiante(nombre, id, num, email, especialidad);
              listaEst->insertarEstu(estu);
            }
            else {
                cout << "Ya existe un alumno con este id" << endl;
            }

            system("pause");
        }
            break;
        case 3:
        {
            string mInicio,mFinal, num;
            system("cls");
            cout << "Ingrese el numero del periodo: " << endl;
            cin >> num;
            if (listaPer->existePeriodoNum(num) == false) {
              cout << "Ingrese el mes en que inicia este periodo: " << endl;
              cin>>mInicio;
              cout << "Ingrese el mes en que finaliza el periodo: " << endl;
              cin>>mFinal;
              Periodo* per = new Periodo(num, mInicio, mFinal);
              listaPer->insertarPeriodos(per);
              cout<<listaPer->mostrarLP();
            }
            else {
                cout << "Ya existe el periodo " << num << endl;
            }
 

            system("pause");
        }
            break;
        case 4:
        {
            string nombre;
            string id;
            string horas;
            int precio;
            bool estado;
            system("cls");
            cout << "Ingrese el nombre del curso: " << endl;
            cin.ignore();
            cin >> nombre;
            cout << "Ingrese el id: " << endl;
            cin >> id;
            if (listaCursosTotal->verificarDuplicadoCurso(id) == false) {
            cout << "Ingrese la cantidad de horas: " << endl;
            cin >> horas;
            cout << "Ingrese el precio del curso: " << endl;
            cin >> precio;
            cout << "Disponibilidad(1:Disponible  0:No disponible): " << endl;
            cin >> estado;

            Curso* curs = new Curso(nombre, id, horas,precio,estado);

            listaCursosTotal->insertarCurso(curs);
            cout << listaCursosTotal->mostrarLC();//
            }
            else {
                cout << "Ya exixte un curso con este id" << endl;
            }

            system("pause");
            

        }
            break;
        case 5:
        {
            string idCurso, dia, horaInicio, horaFin,numPeriodo;
            int numG, capacidad;
            system("cls");
            cout << "Ingrese el numero de grupo: " << endl;
            cin >> numG;
            cout << "Ingrese la capacidad del grupo: " << endl;
            cin >> capacidad;
            cout << "Ingrese el dia en que se imparte: "<<endl;
            cin>>dia;
            cout << "Ingrese la hora de inicio del grupo (HH:MM): "<<endl;
            cin>>horaInicio;
            cout << "Ingrese la hora de fin del grupo (HH:MM): "<<endl;
            cin>>horaFin;
            cout << "Ingrese el ID del curso al que pertenece el grupo: "<<endl;
            cin>>idCurso;
            cout << "Ingrese el numero del periodo al que pertenece el grupo: " << endl;
            cin>>numPeriodo;

            Curso* curso = listaCursosTotal->buscarCursoPorId(idCurso);
            Periodo* periodo = listaPer->buscarPeriodoPorNum(numPeriodo);
           

            if (curso && periodo && curso->getEstado()==true) {
                    Horario horario(horaInicio, horaFin, dia);
                    Grupo* grupo = new Grupo(numG,capacidad,horario,curso);
                    grupo->setCurso(curso);
                    periodo->agregarGrupo(grupo);
                    listaG->insertarGrupo(grupo);
                    cout << "Grupo ingresado."<<endl;            
                    cout << listaG->mostrarLG() << endl;//
                }
            else {
                   cout << "Curso y/o Periodo no encontrados o Curso no disponible."<<endl;
                }

           
            system("pause");
        }
            break;
        case 6:{ 
            system("cls");
            string idProfesor ,idCurso;
            int nGrupo;
            cout << "Ingrese el ID del profesor: " << endl;
            cin >> idProfesor;
            cout<<listaG->mostrarLG();
            cout << "Ingrese el numero del grupo: " << endl;
            cin >> nGrupo;
            cout << "Ingrese el ID del curso: " << endl;
            cin >> idCurso;
            Profesor* profe = listaProfes->buscarProfePorId(idProfesor);
            Curso* curso = listaCursosTotal->buscarCursoPorId(idCurso);

            
            if (curso == nullptr) {
                cout << "Curso no encontrado." << endl;
                system("pause");
                return; 
            }

            Grupo* grupo = listaG->buscarGrupoPorNumYCurso(nGrupo, idCurso);
            if (grupo == nullptr) {
                cout << "Grupo no encontrado en el curso especificado." << endl;
            }
            else {
                grupo->asignarProfesor(profe); 
                cout << "Profesor asignado al grupo " << nGrupo << " del curso " << idCurso << "." << endl;
            }

            system("pause");
           }

            break;
        case 0:
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo."<<endl;
        }
        system("cls");
    } while (opcion != 0);
}

void SistemaAcademia::subMenuMatricula()
{
    int opcion;

    do {
        cout << "Submenu Matricula"<<endl;
        cout << "(1) Matricular Estudiante"<<endl;
        cout << "(2) Desmatricular Estudiante"<<endl;
        cout << "(0) Regresar al Menu Principal"<<endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            system("cls");
            string idEstudiante, idCurso, fecha;
            string numeroPeriodo;
            int numeroGrupo, nFactura;
            cout << "Ingrese el ID del estudiante que desea matricular: " << endl;
            cin >> idEstudiante;
            Estudiante* estu = listaEst->buscarEstuPorId(idEstudiante);
            if (!estu) {
                cout << "No se ha encontrado el estudiante: " << endl;
                return;
            }
            cout << "Seleccione un periodo ingresando el numero: " << endl;
            cout << listaPer->mostrarLP();

            cin >> numeroPeriodo;

            Periodo* periodo = listaPer->buscarPeriodoPorNum(numeroPeriodo);
            if (periodo == nullptr) {
                cout << "Periodo no encontrado."<<endl;
                return;
            }

            cout << "Ingrese el ID del curso: " << endl;
            cin >> idCurso;


            Curso* curso = listaCursosTotal->buscarCursoPorId(idCurso);
            if (curso == nullptr) {
                cout << "Curso no encontrado." << endl;
                system("pause");
                return;
            }

            cout << matricular->mostrarGruposPorCursoYPeriodo(periodo, curso) << endl;

            cout << "Ingrese el numero del grupo al que desea matricularse: ";
            cin >> numeroGrupo;

            Grupo* grupo = periodo->getlistaGrupos()->buscarGrupoPorNumYCurso(numeroGrupo, idCurso);
            if (grupo == nullptr) {
                cout << "Grupo no encontrado para el curso especificado en el periodo." << endl;
                system("pause");
                return;
            }

            Curso* cursoGrupo = grupo->getCurso();
            if (cursoGrupo == nullptr) {
                cout << "El grupo no tiene un curso asociado." << endl;
                system("pause");
                return;
            }
            if (listaM->validarMatriculaCurso(estu, curso)) {
                cout << "El estudiante ya esta matriculado en un grupo del curso " << curso->getNombre() << "." << endl;
                system("pause");
                return;
            }

            cout << "Ingrese la fecha en la que se esta matriculando: " << endl;
            cin >> fecha;
            if (grupo->matricularEstudiante(estu)) {
                Matricula* nuevaMatricula = new Matricula(estu, curso, periodo, fecha);
                listaM->insertarMatricula(nuevaMatricula);
                listaCursosEstu->insertarCurso(curso);
                cout << "El estudiante " << estu->getNombre() << " ha sido matriculado en el grupo "
                    << grupo->getNumeroGrupo() << " del curso " << curso->getNombre() << "." << endl << endl;

                cout << "Si DESEA la factura del estudiante ingrese 1 si NO LA DESEA ingrese 0: " << endl;
                cin >> nFactura;
                if (nFactura == 1) {
                    Factura* facturaEstudiante = new Factura(estu, listaPer, listaCursosEstu);
                    cout << facturaEstudiante->mostrarFactura();
                }
                else {
                    break;
                }


            }
            else {
                cout << "No se pudo matricular al estudiante en el grupo." << endl;
                system("pause");
            }


            system("pause");

            break;
        }

        case 2: {
            string idEstu, numPeriodo, idCurso;
            int nGrupo;
            cout << "Ingrese el ID del estudiante a desmatricular: " << endl;
            cin >> idEstu;
            Estudiante* estu = listaEst->buscarEstuPorId(idEstu);
            if (!estu) {
                cout << "El estudiante no se ha encontrado" << endl;
                return;
            }
            cout << "Ingrese el periodo del cual desea ver los grupos: " << endl;
            cin >> numPeriodo;
            Periodo* per = listaPer->buscarPeriodoPorNum(numPeriodo);
            if (!per) {
                cout << "El periodo no fue encontrado" << endl;
                return;
            }
            cout << per->mostrarGruposEstudiantePorPeriodo(estu, per);
            cout << "Ingrese el numero de grupo que desmatriculara:" << endl;
            cin >> nGrupo;
            if (per->getlistaGrupos()->hayGruposConMismoNum(nGrupo)) {
                cout << "Hay mas de un grupo con el mismo numero " << nGrupo << " Ingrese el ID del curso: " << endl;
                cin >> idCurso;
                Grupo* grupoSeleccionado = per->getlistaGrupos()->buscarGrupoPorNumYCurso(nGrupo, idCurso);
                Curso* cursoSeleccionado = listaCursosTotal->buscarCursoPorId(idCurso);
                if (grupoSeleccionado != nullptr) {
                    grupoSeleccionado->desmatricularEstudiante(estu);
                    cout << "Estudiante desmatriculado del grupo " << grupoSeleccionado->getNumeroGrupo() << " del curso " << cursoSeleccionado->getNombre() << endl;
                    listaCursosEstu->eliminarCursoPorId(idCurso);
                }
                else {
                    cout << "Grupo o curso no encontrado" << endl;
                }
            }
            else {
                Grupo* grupoSeleccionado = per->getlistaGrupos()->seleccionarGrupoPorNumero(nGrupo);

                if (grupoSeleccionado != nullptr) {
                    grupoSeleccionado->desmatricularEstudiante(estu);
                    cout << "Estudiante desmatriculado del grupo " << grupoSeleccionado->getNumeroGrupo();
                    listaCursosEstu->eliminarCursoPorId(grupoSeleccionado->getCurso()->getId());
                }
            }
            system("pause");
            break;
        }

        case 0:
            return;

        default:
            cout << "Opcion no valida. Intente de nuevo."<<endl;
            break;
        }

        system("cls");

    } while (opcion != 0);
}

void SistemaAcademia::cargarArchivos()
{
    system("cls");
        listaEst->cargarDesdeArchivo("Estudiantes.txt");
        listaG->cargarDesdeArchivo("Grupos.txt");
        listaPer->cargarDesdeArchivo("Periodos.txt");
        listaCursosTotal->cargarDesdeArchivo("Cursos.txt");
        listaCursosEstu->cargarDesdeArchivo("CursosEstu.txt");
        listaProfes->cargarDesdeArchivo("Profesores.txt");
     
}

void SistemaAcademia::guardarArchivos()
{
    system("cls");
    listaEst->guardarEnArchivo("Estudiantes.txt");
    listaG->guardarEnArchivo("Grupos.txt");
    listaPer->guardarEnArchivo("Periodos.txt");
    listaCursosTotal->guardarEnArchivo("Cursos.txt");
    listaCursosEstu->guardarEnArchivo("CursosEstu.txt");
    listaProfes->guardarEnArchivo("Profesores.txt");
}

void SistemaAcademia::subMenuBusquedasInformes()
{
    int opcion;

    do {
        cout << "Busquedas e Informes"<<endl;
        cout << "(1) Informe profesores regristrados"<<endl;
        cout << "(2) Informe estudiantes registrados"<<endl;
        cout << "(3) Informes cursos matriculados por un estudiante"<<endl;
        cout << "(4) Informe profesor especifico"<<endl;
        cout << "(5) Informe periodos habilitados para el anno"<<endl;
        cout << "(6) Informe grupo especifico"<<endl;
        cout << "(0) Regresar al Menu Principal"<<endl;
        cout << "Ingrese la opcion: "<<endl;
        cin >> opcion;

        switch (opcion) {
            system("cls");
        case 1: {
            cout<<listaProfes->mostrarLP() << endl;
            system("pause");
            break;
        }

        case 2: {
        
            cout <<listaEst->mostrarLE();
            system("pause"); 

            break;
        }

        case 3: {
            string idEstudiante;
            cout << "Ingrese el ID del estudiante: " << endl;
            cin >> idEstudiante;
            Estudiante* estu = listaEst->buscarEstuPorId(idEstudiante);
            cout<<listaCursosEstu->mostrarLC();
            system("pause");
        }
            break;
        case 4: {
            string idProfe;
            cout << listaProfes->mostrarLP() << endl;
            cout << "Ingrese el ID del profesor del que desea el informe: " << endl;
            cin >> idProfe;
            Profesor* profe = listaProfes->buscarProfePorId(idProfe);
            cout<<listaG->mostrarCursosYGruposPorProfesor(profe)<<endl;
            system("pause");
           
        }
              break;
        case 5: {
            system("cls");
            cout<<listaPer->mostrarPeriodosYGrupos();
            system("pause");
        }
              break;
        case 6: {
            string idCurso;
            int numGrupo;
            cout << listaCursosTotal->mostrarLC();
            cout << "Ingrese el ID del curso del cual desea el informe: " << endl;
            cin >> idCurso;
            Curso* cursoSeleccionado= listaCursosTotal->buscarCursoPorId(idCurso);
            if (cursoSeleccionado == nullptr) {
                cout << "El ID ingresado no es valido" << endl;
            }
            cout << "Grupos del curso: " << cursoSeleccionado->getNombre() << endl;
            cout << listaG->mostrarGruposPorCurso(cursoSeleccionado) << endl;

            cout << "Ingrese el numero del grupo del cual desea el informe: " << endl;
            cin >> numGrupo;
            
            Grupo* grupoSeleccionado = listaG->buscarGrupoPorNumYCurso(numGrupo, idCurso);
            if (grupoSeleccionado != nullptr) {
            }

            system("pause");

        }
              break;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
            break;
        }

        system("cls");

    } while (opcion != 0);

   

}

