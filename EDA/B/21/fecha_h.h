#ifndef fecha_h
#define fecha_h

#include <iostream>
#include <string>
using namespace std;

class fecha {

private:
	size_t dia;
	size_t hora;
	size_t minuto;

public:

	fecha(size_t dia = 0, size_t hora = 0, size_t minuto = 0) {
		this->dia = dia;
		this->hora = hora;
		this->minuto = minuto;
	}

	size_t getDia() const {
		return this->dia;
	}

	size_t getHora() const {
		return this->hora;
	}

	size_t getMinuto() const {
		return this->minuto;
	}


	bool operator<(const fecha & a) const {
		size_t diaA = a.getDia();
		if (diaA > this->dia)
			return true;
		else if (diaA < this->dia)
			return false;
		else {
			size_t horaA = a.getHora();
			if (horaA > this->hora)
				return true;
			else if (horaA < this->hora)
				return false;
			else {
				size_t minutoA = a.getMinuto();
				if (minutoA > this->minuto)
					return true;
				else if (minutoA < this->minuto)
					return false;
				else
					return false;
			}
		}
	}

	bool operator==(const fecha & a) const {
		return a.getDia() == this->dia && a.getHora() == this->hora && a.getMinuto() == this->minuto;
	}

	/*fecha operator=(const fecha& f) // copy assignment
	{
		this->dia = f.getDia();
		this->hora = f.getHora();
		this->minuto = f.getMinuto();
		return *this;
	}*/
};

#endif