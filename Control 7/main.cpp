#include "Arbin.h"
#include <iostream>
#include <string>
#include <algorithm>


// ALUMNOS: Fabrizio Alcaraz Escobar & David Del Cerro Dominguez		GRUPO: D02

using namespace std;

// Implementar aquí la funciones auxiliares que se consideren necesarias

int suma(Arbin<int> a) {
	if (a.esVacio()) return 0;
	else {
		return a.raiz() + suma(a.hijoDer()) + suma(a.hijoIz());
	}
}

int altura(Arbin<int> a, int alt) {			// Recorre el arbol descendiendo, y devuelve la maxima altura alcanzada
	if (!a.esVacio()) {
		int derecha, izquierda;
		derecha = altura(a.hijoDer(), alt + 1);
		izquierda = altura(a.hijoIz(), alt + 1);
		if (derecha < izquierda) alt = izquierda;
		else alt = derecha;
	}
	
	return alt;
}


// Función principal a implementar, que determina si
// el árbol dado como entrada es o no zurdo (devuelve true si es
// zurdo, false en otro caso)
bool es_zurdo(Arbin<int> a) {
	// A implementar
	bool zurdo = false;
	if (!a.esVacio()) {
		int sumaDer, sumaIz;

		sumaDer = suma(a.hijoDer());
		sumaIz = suma(a.hijoIz());

		if ((sumaIz - sumaDer) >= (altura(a,0)-1)) zurdo = true;
	}

	return zurdo;
}


//-----------------------------------------------------------------------
// Código que se encarga de la e/s: no tocar
//

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


/**
La entrada al programa consiste de líneas formadas por árboles de enteros
codificados de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con  
    v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
    con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada línea leida, escribe en la salida estádar
ZURDO si el árbol es zurdo, y NO_ZURDO en otro caso

Ejemplo de entrada:
#
[5]
([17]5([2]1[3]))
(([2]1[3])5[17])

Salida asociada:
NO_ZURDO
ZURDO
ZURDO
NO_ZURDO


*/

int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);
		string resto_linea;
		getline(cin, resto_linea);
		if (es_zurdo(a)) cout << "ZURDO";
		else cout << "NO_ZURDO";
		cout << endl;
	}
	return 0;
}
