#include "SistemaAcademia.h"

SistemaAcademia::SistemaAcademia()
{
	listaCursosEstu = new listaCursos();
    listaCursosTotal = new listaCursos();
	listaPer = new listaPeriodos();
	listaProfes = new listaProf();
	listaEst = new listaEstu();
	listaG = new listaGrupos();
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
           // subMenuMatricula(opcion);
            break;
        case 3:
           // subMenuBusquedasInformes(opcion);
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
        std::cout << "Submenu Administracion General\n";
        std::cout << "(1) Ingresar Profesor\n";
        std::cout << "(2) Ingresar Estudiante\n";
        std::cout << "(3) Ingresar Bloque o Periodo\n";
        std::cout << "(4) Ingresar Curso\n";
        std::cout << "(5) Ingresar Grupo\n";
        std::cout << "(6) Asignar Profesor a Grupo\n";
        std::cout << "(0) Regresar al Menu Principal\n";
        std::cout << "Ingrese la opcion: ";
        std::cin >> opcion;

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
           // periodo  no entiendo si se supone que ya estan definidos entonces para que 
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
                    Grupo* grupo = new Grupo(numG,capacidad,horario,curso,nullptr);//
                    listaG->insertarGrupo(grupo);
                    cout << "Grupo ingresado.\n";
                }
            else {
                   cout << "Curso y/o Periodo no encontrados o Curso no disponible.\n";
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
            cout << "Ingrese el numero del grupo: " << endl;
            cin >> nGrupo;
            cout << "Ingrese el ID del curso: " << endl;
            cin >> idCurso;
           /*Profesor* profe = listaProfes->buscarProfePorId(idProfesor);
            Curso* curso = listaCursosTotal->buscarCursoPorId(idCurso);
            Grupo* grupo = curso->get;*/ 
                system("pause");//////encontrar el grupo y hacer que no se confundan los numeros de grupo
           }

            break;
        case 0:
            return;
        default:
            cout << "Opción no valida. Intente de nuevo.\n";
        }
        system("cls");
    } while (opcion != 0);
}

void SistemaAcademia::subMenuMatricula()
{
}

void SistemaAcademia::subMenuBusquedasInformes()
{
}

