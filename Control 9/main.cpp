/**
Nº DE GRUPO: 
NOMBRE Y APELLIDOS DE LOS ALUMNOS QUE HAN REALIZADO EL CONTROL:
*/


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int hojasProfundas(Arbin <int> a, unsigned int k, int altura) {
	if (a.esVacio()) return 0;
	else if (a.hijoDer().esVacio() && a.hijoIz().esVacio()) {
		if (k < altura) return 1;
		else return 0;
	}
	else {
		return hojasProfundas(a.hijoDer(), k, altura + 1) + hojasProfundas(a.hijoIz(), k, altura + 1);
	}

}

unsigned int numero_hojas_mas_profundas_que(Arbin<int> a, unsigned int k) {
	return hojasProfundas(a, k, 1);
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
		Arbin<int> a = lee_arbol(cin);
		int k;
		cin >> k;
		cout << numero_hojas_mas_profundas_que(a,k) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
