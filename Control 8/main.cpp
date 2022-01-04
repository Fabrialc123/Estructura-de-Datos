#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>


// ALUMNOS: FABRIZIO ALCARAZ ESCOBAR & DAVID DEL CERRO DOMINGUEZ			GRUPO: D02
using namespace std;

int cuentaTramos(const Arbin<int>& cuenca, int & cuenta) {		// Funcion que va acumulando la afluencia de los rios que le llegan a cada nodo
	int rioDerecha = 0;
	int rioIzquierda = 0;

	if (cuenca.esVacio()) {
		return 0;
	}

	else if (cuenca.hijoDer().esVacio() && cuenca.hijoIz().esVacio()) {	// Es decir, si es hoja.
		return 1;
	}

	else {
		rioDerecha = cuentaTramos(cuenca.hijoDer(), cuenta);
		if (rioDerecha < 0) rioDerecha = 0;						// En caso de que el embalse haya quitado más caudal del que tenia el rio

		rioIzquierda = cuentaTramos(cuenca.hijoIz(), cuenta);
		if (rioIzquierda < 0) rioIzquierda = 0;


		if (rioDerecha >= 3) cuenta++;
		if (rioIzquierda >= 3) cuenta++;

		return rioDerecha + rioIzquierda + cuenca.raiz();
	}

}


int numeroTramosNavegables(const Arbin<int>& cuenca) {
	int cuenta = 0;
	
	cuentaTramos(cuenca, cuenta);

	return cuenta;
}

Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF)  {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}