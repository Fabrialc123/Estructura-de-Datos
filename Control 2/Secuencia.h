
// Alumnos = Fabrizio Alcaraz Escobar & David Del Cerro Dominguez		GRUPO: 02


using namespace std;

#ifndef _SECUENCIA_H_
#define _SECUENCIA_H_

/// Excepción de elemento inexistente
class ElementoInvalido {};


template<class T>
class Secuencia {
public:
	Secuencia() {
		_t = new T[2];
		_cont = 0;
		_cap = 2;

	}


	void pon(const T& e) {
		// A IMPLEMENTAR
		T* t_aux;
		if (_cont == _cap) {
			_cap = _cap * 2;
			t_aux = new T[_cap];
			for (int i = 0; i < _cont; i++) {
				t_aux[i] = _t[i];
			}
			delete[] _t;
			_t = t_aux;

		}
		_t[_cont] = e;
		_cont++;
	}

	const T& elem(int i) {
		// A IMPLEMENTAR
		if (i >= _cont || i < 0) {
			throw ElementoInvalido();
		}
		else {
			return _t[i];
		}
	}

	int num_elems() const {
		// A IMPLEMENTAR
		return _cont;
	}

	Secuencia(const Secuencia& s) {
		_cont = s._cont;
		_cap = s._cap;
		_t = new T[_cap];
		for (int i = 0; i < _cont; i++) {
			_t[i] = s._t[i];
		}
	}
	Secuencia& operator=(const Secuencia& sec) {
		_cont = sec._cont;
		_cap = sec._cap;
	
		T* t_aux = new T[sec._cap];
		for (int i = 0; i < sec._cont; i++) {
			t_aux[i] = sec._t[i];
		}
		delete[] _t;							// borra los elementos anteriores
		_t = t_aux;								// ahora _t apunta a los elementos de aux 
		
		return *this;
	}

	~Secuencia() {
		delete[] _t;
	}

     // DEBEN INCLUIRSE E IMPLEMENTARSE 
	 // LAS OPERACIONES ADICIONALES
	 // NECESARIAS PARA GARANTIZAR EL CORRECTO
	 // FUNCIONAMIENTO DEL TAD


private:
  // INCLUIR DETALLES DE REPRESENTACION Y OPERACIONES AUXILIARES
	T* _t;
	int _cont;
	int _cap;
};


#endif


