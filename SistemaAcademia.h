#include "Interfaz.h"
#include "listaCursos.h"
#include "listaEstu.h"
#include "listaGrupos.h"
#include "listaPeriodos.h"
#include "listaProf.h"
#include "PersistenciaDatos.h"
#include "Matricula.h"

class SistemaAcademia:public Interfaz
{
private:
    listaCursos* listaCursosEstu;
    listaCursos* listaCursosTotal;
    listaPeriodos* listaPer;
    listaProf* listaProfes;
    listaEstu* listaEst;
    listaGrupos* listaG;
    Matricula* matricular;
  //  PersistenciaDatos persistencia;
public:
    SistemaAcademia();
    void mostrarMenu();
    void subMenuAdministracion();
    void subMenuMatricula();
    void subMenuBusquedasInformes();
};

