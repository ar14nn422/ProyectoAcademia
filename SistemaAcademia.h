#include "Interfaz.h"
#include "listaCursos.h"
#include "listaEstu.h"
#include "listaGrupos.h"
#include "listaPeriodos.h"
#include "listaProf.h"
#include "PersistenciaDatos.h"
#include "Matricula.h"
#include "listaMatriculas.h"
#include "Factura.h"

class SistemaAcademia:public Interfaz
{
private:
    listaCursos* listaCursosEstu;
    listaCursos* listaCursosTotal;
    listaPeriodos* listaPer;
    listaProf* listaProfes;
    listaEstu* listaEst;
    listaGrupos* listaG;
    listaMatriculas* listaM;
    Matricula* matricular;
  //  PersistenciaDatos persistencia;
public:
    SistemaAcademia();
    void mostrarMenu();
    void subMenuAdministracion();
    void subMenuMatricula();
    void cargarArchivos();
    void guardarArchivos();
    void subMenuBusquedasInformes();
};

