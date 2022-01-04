/*
Nº GRUPO:02
NOMBRES Y APELLIDOS DE LAS PERSONAS QUE HAN REALIZADO EL CONTROL:
	David del Cerro Domínguez & Fabricio Alcaraz Escobar
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
			DiccionarioHash<string, ninio>::ConstIterator it = ninios.cbusca(nombre_ninio);
			if (it.valor().estaEnCola) {
				throw EAccesoAtraccion();
			}
			else {
				ininio.valor().pon(nombre_ninio);
				DiccionarioHash<string, ninio>::Iterator it = ninios.busca(nombre_ninio);
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
	DiccionarioHash<string, ninio>::ConstIterator lista = ninios.cbusca(nombre_ninio);
	DiccionarioHash<string, ninio>::ConstIterator end = ninios.cend();

	if (lista == end) {
		throw ENinioNoRegistrado();
	}
	else {
		return lista.valor().atrac_visitadas;
	}
}
   
int ParqueDeAtracciones::numero_visitas(const string& nombre_ninio, const string& nombre_atraccion) const {
	DiccionarioHash<string, ninio>::ConstIterator numVisitas = ninios.cbusca(nombre_ninio);
	DiccionarioHash<string, ninio>::ConstIterator end = ninios.cend();
	int num = 0;
	if (numVisitas == end) {
		throw EConsultaNumViajes();
	}
	else {
		Lista<string>::ConstIterator it = numVisitas.valor().atrac_visitadas.cbegin();
		Lista<string>::ConstIterator end = numVisitas.valor().atrac_visitadas.cend();

		while (it != end) {
			if (it.elem() == nombre_atraccion) {
				num++;
			}
			it.next();
		}
	}
	return num;
}

void ParqueDeAtracciones::anadirAtraccionVisitada(const string& nombre_ninio,const string& nombre_atraccion) {
	DiccionarioHash<string, ninio>::Iterator anade = ninios.busca(nombre_ninio);
	Lista<string>::Iterator nuevaAtraccion = anade.valor().atrac_visitadas.begin();
	Lista<string>::Iterator end = anade.valor().atrac_visitadas.end();

	bool encontrado = false;

	
	while (nuevaAtraccion != end && !encontrado) {
		if (nuevaAtraccion.elem().compare(nombre_atraccion) < 0) {
			if (anade.valor().atrac_visitadas.longitud() != 1) {
				nuevaAtraccion.next();
			}
		}
		else {
			encontrado = true;
		}

	}
		anade.valor().atrac_visitadas.insertar(nombre_atraccion, nuevaAtraccion);
	
}


   
 