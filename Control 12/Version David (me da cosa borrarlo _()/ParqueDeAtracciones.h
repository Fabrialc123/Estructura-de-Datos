/*
Nº GRUPO:02
NOMBRES Y APELLIDOS DE LAS PERSONAS QUE HAN REALIZADO EL CONTROL:
		David del Cerro Domínguez & Fabricio Alcaraz Escobar
*/

#ifndef _PARQUE_ATRACCIONES_H
#define _PARQUE_ATRACCIONES_H
#include <string>

// Realizar los 'include' adicionales
// que se estimen oportuno.
#include "cola.h"
#include "lista.h"
#include "DiccionarioHash.h"

using namespace std;

class EAtraccionYaExiste {};

class ENinioYaRegistrado {};

class EAtraccionNoExiste {};

class ENinioNoRegistrado {};

class EAccesoAtraccion {};

class EConsultaNumViajes {};


class ParqueDeAtracciones {
public:
   ParqueDeAtracciones();
   void an_atraccion(const string& nombre_atraccion);
   void an_ninio(const string& nombre_ninio);
   void poner_en_fila(const string& nombre_ninio, const string& nombre_atraccion);
   void avanzar(const string& nombre_atraccion);
   Lista<string> atracciones_visitadas(const string& nombre_ninio) const;
   int numero_visitas(const string& nombre_ninio,const string& nombre_atraccion) const;

 
private:
	class ninio {
	public:Lista<string> atrac_visitadas;
	public:bool estaEnCola;

	public:ninio() {
		estaEnCola = false;
	}

	public:void saleDeCola() {
		estaEnCola = false;
	}
	public:void entraEnCola() {
		estaEnCola = true;
	}
	};

		
	DiccionarioHash<string, Cola<string>> atracciones;
	DiccionarioHash<string, ninio> ninios;



	void anadirAtraccionVisitada(const string& nombre_ninio, const string& nombre_atraccion);


	
	// Definir la representación que se estime oportuna, así como declarar los métodos
   // auxiliares que se consideren oportunos (si se estima necesario). 
   
  
};

#endif