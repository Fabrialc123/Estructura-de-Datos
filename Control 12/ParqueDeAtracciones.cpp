/*
Nº GRUPO:02
NOMBRES Y APELLIDOS DE LAS PERSONAS QUE HAN REALIZADO EL CONTROL:
	David del Cerro Domínguez & Fabrizio Alcaraz Escobar
*/

#include "ParqueDeAtracciones.h"

ParqueDeAtracciones::ParqueDeAtracciones() {
	  // A IMPLEMENTAR	
}

void ParqueDeAtracciones::an_atraccion(const string& nombre_atraccion) {
	if (atracciones.contiene(nombre_atraccion)) {
		throw EAtraccionYaExiste();
	}
	else {
		atracciones.inserta(nombre_atraccion,Cola<string>());
	}
}

void ParqueDeAtracciones::an_ninio(const string& nombre_ninio) {
	if (ninios.contiene(nombre_ninio)) {
		throw ENinioYaRegistrado();
	}
	else {
		ninios.inserta(nombre_ninio, ninio());
	}
}

void ParqueDeAtracciones::poner_en_fila(const string& nombre_ninio, const string& nombre_atraccion) {
		DiccionarioHash<string, Cola<string>>::Iterator iend = atracciones.end();
		DiccionarioHash<string, Cola<string>>::Iterator ininio = atracciones.busca(nombre_atraccion);
		if (iend == ininio || !ninios.contiene(nombre_ninio)) {
			throw EAccesoAtraccion();
		}
		else {
			DiccionarioHash<string, ninio>::Iterator it = ninios.busca(nombre_ninio);
			if (it.valor().estaEnCola) {
				throw EAccesoAtraccion();
			}
			else {
				ininio.valor().pon(nombre_ninio);
				it.valor().entraEnCola();
			}
		}
}	

void ParqueDeAtracciones::avanzar(const string& nombre_atraccion) {
		DiccionarioHash<string, Cola<string>>::Iterator iend = atracciones.end();
		DiccionarioHash<string, Cola<string>>::Iterator avanza = atracciones.busca(nombre_atraccion);

		if (iend == avanza) {
			throw EAtraccionNoExiste();
		}
		else {
			if (!(avanza.valor().esVacia())) {
				string nom_ninio = avanza.valor().primero();
				anadirAtraccionVisitada(nom_ninio,nombre_atraccion);
				avanza.valor().quita();
				DiccionarioHash<string, ninio>::Iterator it = ninios.busca(nom_ninio);
				it.valor().saleDeCola();
	
			}
		}
}


Lista<string> ParqueDeAtracciones::atracciones_visitadas(const string& nombre_ninio) const {
	DiccionarioHash<string, ninio>::ConstIterator nino = ninios.cbusca(nombre_ninio);
	DiccionarioHash<string, ninio>::ConstIterator end = ninios.cend();

	if ( nino == end) {
		throw ENinioNoRegistrado();
	}
	else {
		Lista<string> lista;
		Diccionario<string, int>::ConstIterator ini = nino.valor().atrac_visitadas.cbegin();
		Diccionario<string, int>::ConstIterator fin = nino.valor().atrac_visitadas.cend();

		while (ini != fin) {
			lista.pon_final(ini.clave());
			ini.next();

		}
		return lista;
	}
}
   
int ParqueDeAtracciones::numero_visitas(const string& nombre_ninio, const string& nombre_atraccion) const {
	DiccionarioHash<string, ninio>::ConstIterator numVisitas = ninios.cbusca(nombre_ninio);
	DiccionarioHash<string, ninio>::ConstIterator end = ninios.cend();
	int num = 0;
	if (numVisitas == end || !atracciones.contiene(nombre_atraccion)) {
		throw EConsultaNumViajes();
	}
	else if (numVisitas.valor().atrac_visitadas.contiene(nombre_atraccion)) {
		num = numVisitas.valor().atrac_visitadas.valorPara(nombre_atraccion);
	}
	return num;
}

void ParqueDeAtracciones::anadirAtraccionVisitada(const string& nombre_ninio,const string& nombre_atraccion) {
	DiccionarioHash<string, ninio>::Iterator anade = ninios.busca(nombre_ninio);
	int numVeces = 1;
	if (anade.valor().atrac_visitadas.contiene(nombre_atraccion)) numVeces = anade.valor().atrac_visitadas.valorPara(nombre_atraccion) + 1;

	anade.valor().atrac_visitadas.inserta(nombre_atraccion, numVeces);
	
}


   
 