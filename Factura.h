#include "Estudiante.h"
#include "listaCursos.h"
#include "listaPeriodos.h"

class Factura {
private:
	listaCursos* cursos;
	Estudiante* estudiante;
	listaPeriodos* periodos;
	float iva;
	float descuento;
	float subtotal;
	float totalAPagar;

public:
	Factura(listaCursos*, Estudiante*,listaPeriodos* , float, float, float, float);
	Factura();
	Factura(Estudiante*,listaPeriodos*,listaCursos*);
	~Factura();
	float aplicarDescuento();
	float calcularSubtotal();
	float calcularTotal();
	string mostrarFactura();

};
