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
        cout << "Menu Principal\n";
        cout << "1- Submenu Administracion\n";
        cout << "2- Submenu Matricula\n";
        cout << "3- Submenu Busquedas e Informes\n";
        cout << "4- Guardar los Datos en Archivos\n";
        cout << "5- Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");
            subMenuAdministracion();
            break;
        case 2:
            subMenuMatricula();
            break;
        case 3:
            subMenuBusquedasInformes();
            break;
        case 4:
           // guardarDatos();
            break;
        case 5:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
        system("cls");
    } while (opcion != 5);
}

void SistemaAcademia::subMenuAdministracion()
{
    int opcion;

    do {
        cout << "Submenu Administracion General\n";
        cout << "(1) Ingresar Profesor\n";
        cout << "(2) Ingresar Estudiante\n";
        cout << "(3) Ingresar Bloque o Periodo\n";
        cout << "(4) Ingresar Curso\n";
        cout << "(5) Ingresar Grupo\n";
        cout << "(6) Asignar Profesor a Grupo\n";
        cout << "(0) Regresar al Menu Principal\n";
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
            cout << "Ingrese el numero de telefono: " << endl;
            cin >> num;
            cout << "Ingrese el email: " << endl;
            cin >> email;
            cout << "Ingrese el grado academico: " << endl;
            cin >> gradoAcademico;
            Profesor* profe = new Profesor(nombre, id, num, email, gradoAcademico);
            listaProfes->insertarProfesor(profe);
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
            cout << "Ingrese el numero de telefono: " << endl;
            cin >> num;
            cout << "Ingrese el email: " << endl;
            cin >> email;
            cout << "Ingrese la especialidad: " << endl;
            cin >> especialidad;
            Estudiante* estu = new Estudiante(nombre, id, num, email, especialidad);
            listaEst->insertarEstu(estu);
            system("pause");
        }
            break;
        case 3:
        {
            int num;
            string mInicio,mFinal;
            system("cls");
            cout << "Ingrese el numero del periodo: " << endl;
            cin >> num;
            cout << "Ingrese el mes en que inicia este periodo: " << endl;
            cin >> mInicio;
            cout << "Ingrese el mes en que finaliza el periodo: " << endl;
            cin >> mFinal;
            Periodo* per = new Periodo(num, mInicio, mFinal);
            listaPer->insertarPeriodos(per);
            system("pause");
        }
           // if (la cantidad de periodos es mayor a 4 mensaje que diga que ya no puede ingresar mas  );
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
            cout << "Ingrese la cantidad de horas: " << endl;
            cin >> horas;
            cout << "Ingrese el precio del curso: " << endl;
            cin >> precio;
            cout << "Disponibilidad(1:Disponible  0:No disponible): " << endl;
            cin >> estado;

            Curso* curs = new Curso(nombre, id, horas,precio,estado);

            listaCursosTotal->insertarCurso(curs);
            cout << listaCursosTotal->mostrarLC();
            system("pause");
            

        }
            break;
        case 5:
        {
            string idCurso, dia, horaInicio, horaFin;
            int numG, capacidad, numPeriodo;
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
            Periodo* periodo = listaPer->buscarPeriodoPorNum(numPeriodo);//
           

            if (curso && periodo && curso->getEstado()==true) {
                    Horario horario(dia, horaInicio, horaFin);
                    Grupo* grupo = new Grupo(numG,capacidad,horario,curso,nullptr);
                    periodo->agregarGrupo(grupo);
                    listaG->insertarGrupo(grupo);
                    cout << "Grupo ingresado.\n";
                }
            else {
                   cout << "Curso y/o Periodo no encontrados o Curso no disponible.\n";
                }
           // cout << "Grupos que hay en el " << periodo->getNumPeriodo() << periodo->mostrarGruposP();
           // cout << curso->mostrarGruposDelCurso() << endl;////se cae con small string las dos listas de grupo
            system("pause");
        }
            break;
        case 6:{ 
            system("cls");
            string idProfesor ,idCurso;
            int nGrupo;
            cout << "Ingrese el ID del profesor: " << endl;
            cin >> idProfesor;
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
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
        system("cls");
    } while (opcion != 0);
}

void SistemaAcademia::subMenuMatricula()
{
    int opcion;

    do {
        cout << "Submenu Matricula\n";
        cout << "(1) Matricular Estudiante\n";
        cout << "(2) Desmatricular Estudiante\n";
        cout << "(0) Regresar al Menu Principal\n";
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            system("cls");
            string idEstudiante, idCurso, fecha;
            int numeroGrupo, nFactura;
            cout << "Ingrese el ID del estudiante que desea matricular: " << endl;
            cin >> idEstudiante;
            Estudiante* estu = listaEst->buscarEstuPorId(idEstudiante);
            if (!estu) {
                cout << "No se ha encontrado el estudiante: " << endl;
            }
            cout << "Seleccione un periodo ingresando el numero: " << endl;
            cout << listaPer->mostrarLP();

            int nPeriodo;
            cin >> nPeriodo;
            Periodo* periodo = listaPer->buscarPeriodoPorNum(nPeriodo);
            if (periodo == nullptr) {
                cout << "Periodo no encontrado.\n";
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
                     << grupo->getNumeroGrupo() << " del curso " << curso->getNombre() << "." << endl<<endl;
                
                cout << "Si DESEA la factura del estudiante ingrese 1 si NO LA DESEA ingrese 0: " << endl;
                cin >> nFactura;
                if (nFactura == 1) {
                Factura* facturaEstudiante = new Factura(estu,listaPer,listaCursosEstu);
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
            
            cout << "Funcionalidad para desmatricular estudiante.\n";
           
            break;
        }

        case 0:
            return;

        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
            break; 
        }

        system("cls"); 

    } while (opcion != 0);
}

void SistemaAcademia::subMenuBusquedasInformes()
{
    int opcion;

    do {
        cout << "Busquedas e Informes\n";
        cout << "(1) Informe profesores regristrados\n";
        cout << "(2) Informe estudiantes registrados\n";
        cout << "(3) Informes cursos matriculados por un estudiante\n";
        cout << "(4) Informe profesor especifico\n";
        cout << "(5) Informe periodos habilitados para el anno\n";
        cout << "(6) Informe grupo especifico\n";
        cout << "(0) Regresar al Menu Principal\n";
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
            system("cls");
        case 1: {
            cout<<listaProfes->mostrarProfesoresSinGrupo(listaG) << endl;
            system("pause");
            break;
        }

        case 2: {

            cout << "Funcionalidad para desmatricular estudiante.\n";

            break;
        }

        case 0:
            return;

        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
            break;
        }

        system("cls");

    } while (opcion != 0);
}

