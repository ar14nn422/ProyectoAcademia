#ifndef INTERFAZ_H
#define INTERFAZ_H
class Interfaz
{
public:
    virtual void mostrarMenu() = 0;
    virtual void subMenuAdministracion() = 0;
    virtual void subMenuMatricula() = 0;
    virtual void subMenuBusquedasInformes() = 0;
    virtual void cargarArchivos() = 0;
   
};
#endif // !INTERFAZ_H



