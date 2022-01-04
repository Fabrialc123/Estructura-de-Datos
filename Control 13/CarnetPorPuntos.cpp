/**
NOMBRE Y APELLIDOS: FABRIZIO ALCARAZ ESCOBAR & DAVID DEL CERRO DOMINGUEZ
GRUPO: D02

*/

#include "CarnetPorPuntos.h"


/**
Implementa aquí los métodos de las clases adicionales
*/

 
/**
Debes completar la implementación de las operaciones de CarnetPorPuntos,
y justificar la complejidad de las mismas.
*/ 

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
	 La complejidad es O(1) debido a que se consulta un diccionario y se hacen dos insercciones de coste lineal.
*/
void CarnetPorPuntos::nuevo(const string& dni) {
	if (_conductores.contiene(dni)) throw EConductorDuplicado();
	else {
		_listadoPorPuntos[PUNTOS_MAX].pon_ppio(dni);
		_conductores.inserta(dni, InfoConductor(PUNTOS_MAX, _listadoPorPuntos[PUNTOS_MAX].begin()));
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
	La complejidad es O(1) debido a que se realiza una búsqueda en un diccionarioHash que es de complejidad O(1), y luego se hacen operaciones de inserccion en una lista doblemente enlazada.
*/
void CarnetPorPuntos::quitar(const string& dni, unsigned int puntos) {
	DiccionarioHash<string, InfoConductor>::Iterator i = _conductores.busca(dni);
	DiccionarioHash<string, InfoConductor>::Iterator end = _conductores.end();

	if (i == end) throw EConductorNoExiste();
	else {
		if (i.valor()._puntos != 0 && puntos > 0) {			// Se debe a que si un conductor ya tenia 0 puntos o se le resta 0 puntos, no influye en nada ya que es lo mínimo que tiene
			int puntosRestantes = i.valor()._puntos - puntos;
			if (puntosRestantes < 0) puntosRestantes = 0;

			
			_listadoPorPuntos[i.valor()._puntos].eliminar(i.valor()._pos);
			i.valor()._puntos = puntosRestantes;
			_listadoPorPuntos[puntosRestantes].pon_ppio(dni);
			i.valor()._pos = _listadoPorPuntos[puntosRestantes].begin();
		}
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
	La complejidad es O(1) debido a que se realiza una búsqueda en un diccionarioHash que es de complejidad O(1), y luego se hacen operaciones basicas(eliminar e inserccion) en una lista doblemente enlazada.
*/
void CarnetPorPuntos::recuperar(const string& dni, unsigned int puntos) {
	DiccionarioHash<string, InfoConductor>::Iterator i = _conductores.busca(dni);
	DiccionarioHash<string, InfoConductor>::Iterator end = _conductores.end();

	if (i == end) throw EConductorNoExiste();
	else {
		if (i.valor()._puntos != PUNTOS_MAX && puntos > 0) {			// Razones análogas a quitar()
			int puntosRestantes = i.valor()._puntos + puntos;
			if (puntosRestantes > PUNTOS_MAX) puntosRestantes = PUNTOS_MAX;

			_listadoPorPuntos[i.valor()._puntos].eliminar(i.valor()._pos);
			i.valor()._puntos = puntosRestantes;
			_listadoPorPuntos[puntosRestantes].pon_ppio(dni);
			i.valor()._pos = _listadoPorPuntos[puntosRestantes].begin();
		}
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
	La complejidad es O(1), ya que se realiza una busqueda en un diccionario hash.
*/
unsigned int CarnetPorPuntos::consultar(const string& dni) const {
	DiccionarioHash<string, InfoConductor>::ConstIterator i = _conductores.cbusca(dni);
	DiccionarioHash<string, InfoConductor>::ConstIterator end = _conductores.cend();

	int consulta = 0;

	if (i == end) throw EConductorNoExiste();
	else {
		consulta = i.valor()._puntos;
	}

	return consulta;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
	La complejidad es O(1) ya que se hace un acceso a una lista.
*/
unsigned int CarnetPorPuntos::cuantos_con_puntos(unsigned int puntos) const {
	int cuantos = 0;

	if (!(puntos >= 0 && puntos <= PUNTOS_MAX)) throw EPuntosNoValidos();
	else {
		cuantos = _listadoPorPuntos[puntos].longitud();
	}

	return cuantos;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
	La complejidad es O(1) ya que se hace un acceso a una lista.
*/
const Lista<string>& CarnetPorPuntos::lista_por_puntos(unsigned int puntos) const {;

	if (!(puntos >= 0 && puntos <= PUNTOS_MAX)) throw EPuntosNoValidos();
	else {
		return _listadoPorPuntos[puntos];
	}
}

