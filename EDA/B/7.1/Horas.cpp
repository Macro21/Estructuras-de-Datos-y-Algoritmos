#include <iostream>
#include <iomanip>
using namespace std;

#include "Horas.h"


Horas:: Horas(int horas, int minutos, int segundos){
	this->horas = horas;
	this->minutos = minutos;
	this->segundos = segundos;
	if (!horaCorrecta()) throw exception();
}

Horas::Horas() {
}

Horas::Horas(const Horas & h){
	horas = h.horas;
	minutos = h.minutos;
	segundos = h.segundos;
}


bool Horas::operator< (const Horas & h1) const {
	bool resultado;
	if (this->horas == h1.horas) {
		if (this->minutos == h1.minutos) {
			if (this->segundos >= h1.segundos) {
				resultado = false;
			}
			else { 
				resultado = true;
			}
		}
		else if (this->minutos > h1.minutos) {
			resultado = false;
		}
		else {
			resultado = true;
		}
	}
	else if (this->horas > h1.horas) {
		resultado = false;
	}
	else {
		resultado = true;
	}
	return resultado;
}

bool Horas::operator==(const Horas & h) const {
	bool resultado;
	if (horas == h.horas && minutos == h.minutos && segundos == h.segundos) {
		resultado = true;
	}
	else {
		resultado = false;
	}
	return resultado;
}


int Horas::getHoras() const {
	return this->horas;
}

int Horas::getMinutos() const {
	return this->minutos;
}

int Horas::getSegundos() const {
	return this->segundos;
}


bool Horas::horaCorrecta() const{
	bool correcta = false;
	if ((horas <= 23 && horas >= 0) && (minutos >= 0 && minutos <= 59) && (segundos >= 0 && segundos <= 59)){
		correcta = true;
	}
	return correcta;
}

void Horas::setHoras(const int & horas) {
	this->horas = horas;
}

void Horas::setMinutos(const int & minutos) {
	this->minutos = minutos;
}

void Horas::setSegundos(const int & segundos) {
	this->segundos = segundos;
}

Horas& Horas::operator+(const Horas & h) {
	
	int ho;
	int m;
	int s;

	ho = this->horas + h.getHoras();
	m = this->minutos + h.getMinutos();
	s = this->segundos + h.getSegundos();
	
	normalizarMinutos(m,ho);

	while (s >= 60) {
		s = s%60;
		m++;
		normalizarMinutos(m, ho);
	}

	try {
		*this = Horas(ho, m, s);
	}
	catch (const exception&) {
		throw exception();
	}
	return *this;
}

void Horas::normalizarMinutos(int & m, int & ho) {
	while (m >= 60) {
		m = m % 60;
		ho++;
	}
}