#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "Horas.h"
#include "Pelicula.h"

const int MAX_PELIS = 1000;


ostream& operator<< (ostream &o, Pelicula& p);
istream& operator>> (istream& is, Pelicula& p);
void leeHora(istream & is, Horas & h);

int main() {
	
#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int nPelis;
	Pelicula p;
	vector<Pelicula> cartelera;
	cin >> nPelis;

	while (nPelis != 0) {
		for (int i = 0; i < nPelis; i++) {
			try {
				cin >> p;
				cartelera.push_back(p);
			}
			catch (const exception&) {
				cout << "Error" << endl;
			}
		}
		sort(cartelera.begin(), cartelera.end());
		for (int i = 0; i < nPelis; i++) {
			cout << cartelera[i] << endl;
		}
		cout << "---" << endl;
		cartelera = vector<Pelicula>();
		cin >> nPelis;
	}
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}

ostream& operator << (ostream& o, Pelicula& p) {
	Horas h = p.getFin();
	int horas = h.getHoras();
	int minutos = h.getMinutos();
	int segundos = h.getSegundos();
	if (horas <= 9) {
		o << "0" << horas << ":";
	}
	else {
		o << horas << ":";
	}
	if (minutos <= 9) {
		o << "0" << minutos << ":";
	}
	else {
		o << minutos << ":";
	}
	if (segundos <= 9){
		o << "0" << segundos;
	}
	else {
		o << segundos;
	}
	o << p.getTitulo();
	return o;
}

istream & operator>>(istream & is, Pelicula & p){
	Horas comienzo;
	Horas duracion;
	string titulo;

	leeHora(is,comienzo);
	leeHora(is,duracion);
	getline(is,titulo);
	
	p = Pelicula(comienzo, duracion, titulo);
	return is;
}

void leeHora(istream & is, Horas & h) {
	int aux;
	is >> aux;
	h.setHoras(aux);
	is.ignore();
	is >> aux;
	h.setMinutos(aux);
	is.ignore();
	is >> aux;
	h.setSegundos(aux);
}