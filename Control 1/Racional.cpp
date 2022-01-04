
// Alumnos: Fabrizio Alcaraz Escobar & David Del Cerro Dominguez		Grupo: D02

#include "Racional.h"
#include <cmath>

  //Metodos publicos

  	//**** COMPLETAR
	//  Deben implementarse los metodos publicos de la clase
	//****


Racional::Racional() {
	_numer = 0;
	_denom = 1;
	}

Racional::Racional(long n, long d) {

	if (d == 0) throw EDenominadorCero();
	_numer = n;
	_denom = d;
	reduce();
}

Racional Racional::suma(Racional sumando)
{
	Racional a = Racional((_numer * (mcm(_denom, sumando._denom) / _denom)) + sumando._numer * ((mcm(_denom, sumando._denom) / sumando._denom)), mcm(_denom, sumando._denom));
	return a;
}

Racional Racional::operator-(const Racional& r) const
{
	long maxcm = mcm(_denom, r._denom);
	Racional a = Racional(((_numer * maxcm) / _denom) - ((r._numer * maxcm) / r._denom), maxcm);
	return a;
}

Racional Racional::operator*=(const Racional& r)
{
	_numer = _numer * r._numer;
	_denom = _denom * r._denom;
	reduce();
	return *this;
}

Racional Racional::divideYActualiza(Racional& r)
{
	if (r._numer == 0 && r._denom == 1) {
		throw EDivisionPorCero();
	}
	else {
		_numer = _numer * r._denom;
		_denom = _denom * r._numer;
		reduce();
		return *this;
	}
}

bool Racional::operator==(const Racional& r)
{
	return(_numer == r._numer && _denom == r._denom);
}
 
  
  // Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

 // Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

