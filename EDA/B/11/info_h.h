#ifndef info_h
#define info_h

#include <iostream>
using namespace std;

class Info {
private:
		size_t altura;
		size_t nrNodos;
		size_t nrHojas;
public:

	Info(size_t altura = 0, size_t nrNodos = 0, size_t nrHojas = 0) {
		this->altura = altura;
		this->nrNodos = nrNodos;
		this->nrHojas = nrHojas;
	}

	size_t getNrNodos() const {
		return this->nrNodos;
	}

	size_t getNrHojas() const {
		return this->nrHojas;
	}

	size_t getAltura() const {
		return this->altura;
	}

	void setAltura(size_t alt) {
		this->altura = alt;
	}

	void setNodos(size_t nodos) {
		this->nrNodos = nodos;
	}

	void setHojas(size_t hojas) {
		this->nrHojas = hojas;
	}

	Info& operator+=(const Info& data) {
		this->altura += data.getAltura();
		this->nrNodos += data.getNrNodos();
		this->nrHojas += data.getNrHojas();
		return *this;
	}
};


#endif
