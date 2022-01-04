// Alumnos: Fabrizio Alcaraz Escobar & David Del Cerro Dominguez    GRUPO: 02

#include <iostream>
#include <string>
#include "pila.h"
using namespace std;



bool esEquilibrada(const string& cadena) {
	// A IMPLEMENTAR
    bool equilibrado = true;
    Pila<char> pil;
    char car;
    try {
        for (int i = 0; i < cadena.length(); i++) {
            car = cadena[i];
            if (car == '(' || car == '[' || car == '{') {
                pil.apila(car);
            }
            else if (car == ')' || car == ']' || car == '}') {
                char aux = pil.cima();
                if ((aux == '(' && car == ')') || (aux == '[' && car == ']') || (aux == '{' && car == '}')) {
                    pil.desapila();
                }
                else equilibrado = false;
            }
        }
    }
    catch (EPilaVacia) {
        equilibrado = false;
    }

    return equilibrado && pil.esVacia();
}


int main() {
	string cadena;
    while(getline(cin, cadena)) {
      if(esEquilibrada(cadena))
        cout << "EQUILIBRADA" << endl;
      else
        cout << "NO_EQUILIBRADA" << endl;		  
	}
	return 0;
}	
