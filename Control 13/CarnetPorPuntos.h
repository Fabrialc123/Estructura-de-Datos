/**
NOMBRE Y APELLIDOS:	Fabrizio Alcaraz Escobar && David del Cerro Dominguez
GRUPO : D02
*/
#ifndef _CARNET_POR_PUNTOS_H
#define _CARNET_POR_PUNTOS_H

#include "lista.h"
#include <string>
#include "DiccionarioHash.h"
using namespace std;

const static int PUNTOS_MAX = 15;
typedef Lista<string>::Iterator tPosicionPorPuntos;

class EConductorDuplicado {};
class EConductorNoExiste {};
class EPuntosNoValidos {};

class CarnetPorPuntos {
public:
   void nuevo(const string& dni);
   void quitar(const string& dni, unsigned int puntos);
   void recuperar(const string& dni, unsigned int puntos);
   unsigned int consultar(const string& dni) const;
   unsigned int cuantos_con_puntos(unsigned int puntos) const;
   const Lista<string>& lista_por_puntos(unsigned int puntos) const;
private:
   // A COMPLETAR
	class InfoConductor {
		public:	int _puntos;
		public:	tPosicionPorPuntos _pos;
		public:	InfoConductor(const int& puntos, const tPosicionPorPuntos& pos_espera) : _puntos(puntos), _pos(pos_espera) {};
	};

	DiccionarioHash<string, InfoConductor> _conductores;
	Lista<string> _listadoPorPuntos[PUNTOS_MAX + 1];
};

#endif