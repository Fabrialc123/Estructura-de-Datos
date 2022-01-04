/**
  Nº DE GRUPO:	D02
  NOMBRE Y APELLIDOS DE LOS ALUMNOS QUE HAN REALIZADO EL CONTROL:	Fabrizio Alcaraz Escobar & David Del Cerro Dominguez
*/


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

int nodosSingulares(Arbin<int> a, int sumaAnteriores, unsigned int & singulares) {
	if (a.esVacio()) {
		return 0;
	}
	else {

		int sumaSiguientes = nodosSingulares(a.hijoDer(), sumaAnteriores + a.raiz(), singulares) + nodosSingulares(a.hijoIz(), sumaAnteriores + a.raiz(), singulares);

		if (sumaSiguientes == sumaAnteriores) singulares++;

		return sumaSiguientes + a.raiz();		// va regresando lo que seria la suma de los nodos descendientes para los nodos que han llamado  ala funcion
	}
}


unsigned int numero_singulares(Arbin<int> a) {
	unsigned int singulares = 0;
	nodosSingulares(a, 0, singulares);
	return singulares;
}

Arbin<int> lee_arbol(istream& in) {
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
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		cout << numero_singulares(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
