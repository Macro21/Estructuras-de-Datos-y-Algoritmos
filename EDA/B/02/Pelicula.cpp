#include <iostream>

#include "Horas.h"
#include "Pelicula.h"
#include <string>
using namespace std;


Pelicula::Pelicula(){
}

Pelicula::Pelicula(Horas _horaComienzo, Horas _duracion, string _titulo){
	this->_inicio = _horaComienzo;
	this->_duracion = _duracion;
	this->_titulo = _titulo;
	calcularFin();
}

Pelicula::Pelicula(const Pelicula & pelicula) {
	_inicio = pelicula._inicio;
	_duracion = pelicula._duracion;
	_titulo = pelicula._titulo;
	calcularFin();
}

bool Pelicula::operator<(const Pelicula & peli) const { // comparar dos pelis para ver cual dura mas

	if (this->_fin == peli.getFin()) {
		return this->_titulo < peli.getTitulo();
	}
	else if (this->_fin < peli.getFin()) {
		return true;
	}
	return false;
}

bool Pelicula::operator==(const Pelicula & peli) const {
	return false;
}

Horas Pelicula::calcularFin() {
	Horas d = this->_duracion;
	Horas i = this->_inicio;
	this->_fin = d + i;
	return this->_fin;
}

Horas Pelicula::getFin() const {
	return this->_fin;
}

string Pelicula::getTitulo() const {
	return this->_titulo;
}
