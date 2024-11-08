#include "Interfaz.h"
#include "SistemaAcademia.h"
#include <iostream>
int main() {
    Interfaz* interfaz = new SistemaAcademia();
    interfaz->cargarArchivos(); 
    interfaz->mostrarMenu();
    delete interfaz;
    return 0;
}