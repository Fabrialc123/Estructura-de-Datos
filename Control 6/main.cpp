#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
#include "pila.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS



// ALUMNOS : FABRIZIO ALCARAZ ESCOBAR & DAVID DEL CERRO DOMINGUEZ							GRUPO: D02
 

bool esVocal(char v) {
	return v == 'a' || v == 'A' || v == 'e' || v == 'E' || v == 'i' || v == 'I' || v == 'o' || v == 'O' || v == 'u' || v == 'U';
}


void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	// A IMPLEMENTAR
	Lista<char>::Iterator it = mensaje.begin();
	Lista<char>::Iterator fin = mensaje.end();
	Pila<char> aInvertir;
	Lista<char>::Iterator aux = it;

	while (it != fin){
		if (esVocal(it.elem())) {
			while (aux != it && !aInvertir.esVacia()) {
				aux.set(aInvertir.cima());		// Invierte el orden
				aInvertir.desapila();
				aux.next();
			}
			aux.next();
		}
		else {
			aInvertir.apila(it.elem());		// Va apilando los elementos
		}
		it.next();
	}

	while (!aInvertir.esVacia()) {		// Para cuando acabe de recorrer, el ultimo tramo se invierta
		aux.set(aInvertir.cima());		
		aInvertir.desapila();
		aux.next();
	}
}


 
  // Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	Lista<char>::ConstIterator it = l.cbegin();
	while (it != l.cend()) {
		cout << it.elem();
		it.next();
	}
	cout << endl;
}




// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();    // Esta operacion debe ser implementada como
	                      // un nuevo metodo de Lista
}

  // Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for(unsigned int i=0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);  
}

int main() {
	string linea;
	while(getline(cin,linea)) {
	   Lista<char> mensaje;
	   construyeMensaje(linea,mensaje);
       codifica(mensaje);
	   imprime(mensaje);
	}
	return 0;
}	
