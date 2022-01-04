/*
Nº GRUPO:D02

NOMBRE Y APELLIDOS DE LOS COMPONENTES QUE HAN REALIZADO EL CONTROL:	Fabrizio Alcaraz Escobar & David Del Cerro Dominguez

*/

#include "diccionario.h"
#include "lista.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
  public:
    string alumno;
    int nota;	
	Puntuacion(const string& nombre, int puntuacion): alumno(nombre), nota(puntuacion) {}
};

void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	  // A IMPLEMENTAR
	Diccionario<string,int> alumnos;
	Lista<string>::ConstIterator iBien = bien.cbegin();
	Lista<string>::ConstIterator finBien = bien.cend();

	Lista<string>::ConstIterator iMal = mal.cbegin();
	Lista<string>::ConstIterator finMal = mal.cend();

	Diccionario<string, int>::Iterator iDi = alumnos.begin();
	Diccionario<string, int>::Iterator finDi = alumnos.end();

	bool enc;

	while (iBien != finBien) {
		enc = false;
		iDi = alumnos.begin();
		while (!enc && iDi != finDi) {
			if (iDi.clave() == iBien.elem()) {
				iDi.setVal(iDi.valor() + 1);
				enc = true;
			}
			iDi.next();
		}
		if (!enc)	alumnos.inserta(iBien.elem(), 1);
		iBien.next();
	}

	while (iMal != finMal) {
		enc = false;
		iDi = alumnos.begin();
		while (!enc && iDi != finDi) {
			if (iDi.clave() == iMal.elem()) {
				iDi.setVal(iDi.valor() - 1);
				enc = true;
			}
			iDi.next();
		}
		if (!enc)	alumnos.inserta(iMal.elem(), -1);
		iMal.next();
	}

	iDi = alumnos.begin();
	while (iDi != finDi) {
		if (iDi.valor() != 0) listado.pon_final(Puntuacion(iDi.clave(), iDi.valor()));
		iDi.next();
	}


}

void imprimePuntuaciones(Lista<Puntuacion>& listado) {
  Lista<Puntuacion>::ConstIterator i = listado.cbegin();
  Lista<Puntuacion>::ConstIterator e = listado.cend();
  while (i != e) {
	  cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
      i.next();	  
  }  
  cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
  string comienzo;
  while (cin >> comienzo) {
	 Lista<string> bien;
	 Lista<string> mal;
	 Lista<Puntuacion> listado;
	 leeResultados(bien, mal);
	 califica(bien, mal,listado);
	 imprimePuntuaciones(listado);
  }
  return 0;   
}