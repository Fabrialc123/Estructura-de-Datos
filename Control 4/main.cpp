// ALUMNOS: Fabrizio Alcaraz Escobar & David Del Cerro Dominguez		GRUPO: 02



#include <iostream>
#include "cola.h"
using namespace std;

unsigned int afortunado(unsigned int n, unsigned int m) { //n>=1  m>=2 
	Cola<int> alumnos;
	for (int i = 1; i <= n; i++) {
		alumnos.pon(i);
	}
	int alumnoAfortunado;
	try {
		while (!alumnos.esVacia()) {
			alumnoAfortunado = alumnos.primero();
			for (int i = 1; i < m; i++) {
				alumnos.pon(alumnos.primero());
				alumnos.quita();
			}
			alumnos.quita();
		}
	}
	catch (EColaVacia) {

	}
	
	return alumnoAfortunado;
}


int main() {
    int n,m;
	while((cin >> n)) {
	   cin >> m;
       cout << afortunado(n,m) << endl;	   
	}
	return 0;
}	
