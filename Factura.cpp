#include "Factura.h"
#include <sstream>

Factura::Factura(listaCursos* curs, Estudiante* estu,listaPeriodos* per, float iv, float desc, float subto, float tot)
{
	cursos = curs;
	estudiante = estu;
	periodos = per;
	iva = iv;
	descuento = desc;
	subtotal = subto;
	totalAPagar = tot;
}

Factura::Factura()
{
	cursos = nullptr;
	estudiante = nullptr;
	periodos = nullptr;
	iva = 1.13;
	descuento = 0.0;
	subtotal = 0.0;
	totalAPagar = 0.0;
}
Factura::Factura( Estudiante* estu,listaPeriodos* listaper,listaCursos* listacur)
{
	cursos = listacur;
	estudiante = estu;
	periodos = listaper;
	iva = 1.13;
	descuento = 0.0;
	subtotal = 0.0;
	totalAPagar = 0.0;
}

Factura::~Factura()
{
}



float Factura::aplicarDescuento()//////////////////////////////
{
	subtotal = calcularSubtotal();  // Calcula el subtotal primero
	descuento = 0.0;  // Inicializa el descuento en cero

	// Descuento por cantidad de cursos en el mismo periodo
	int cantidadCursos = cursos->cantidadCursos();
	if (cantidadCursos >= 2) {
		descuento = subtotal * 0.15;  // Aplica el 15% de descuento
		
	}

	// Descuento adicional por cantidad de cursos en todo el año
	if (periodos != nullptr) {
		int cantidadCursosEnElAno = periodos->contarCursos();
		if (cantidadCursosEnElAno >= 4) {
			float descuentoAdicional = subtotal * 0.25;
			descuento += descuentoAdicional;  // Suma el 25% de descuento adicional
			
		}
	}

	return descuento;
}

float Factura::calcularSubtotal()
{
		subtotal = 0.0;
		Curso* actual = cursos->getPrimero();
		while (actual != nullptr) {
			subtotal += actual->getPrecio();
			actual = actual->getsiguiente();
		}
		return subtotal;
}

float Factura::calcularTotal()
{
	
		subtotal = calcularSubtotal();
		aplicarDescuento();
		float subtotalConDescuento = subtotal - descuento;
		totalAPagar = subtotalConDescuento * iva; 
		return totalAPagar;
}

string Factura::mostrarFactura()
{
	stringstream s;
	s << "Factura para el estudiante: " << estudiante->getNombre() << endl
		<< "Matriculado en los siguientes " << cursos->cantidadCursos() << " cursos" << endl<<endl
		<<cursos->mostrarLC()<<endl
		<< "Subtotal:" << calcularSubtotal() << endl
		<< "Total:" << calcularTotal() << endl;
	return s.str();
}


