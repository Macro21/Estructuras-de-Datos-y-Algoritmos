#include <iostream>
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

