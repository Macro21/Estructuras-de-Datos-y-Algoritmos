#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

#include "Horas.h"

ostream& operator<<(ostream & os, const Horas & hora);
istream& operator>> (istream& is, Horas & hora);
int buscarHoras(const vector<Horas> & horario_trenes, const Horas & hora);


//Andrei Ionut Vaduva, E60

int main(){

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	vector<Horas> horario_trenes;

	Horas hora;
	int trenes;
	int nrHoras;
	
	cin >> trenes;
	cin >> nrHoras;

	while (trenes != 0 || nrHoras != 0){
		horario_trenes = vector<Horas>();
		
		for (int i = 0; i < trenes; i++) { // relleno los horarios
			cin >> hora;
			horario_trenes.push_back(hora);
		}
		for (int i = 0; i < nrHoras; i++) { // relleno las horas a buscar
			try {
				cin >> hora;
				int sol = buscarHoras(horario_trenes, hora);
				if (sol == -1) {
					cout << "NO" << endl;
				}
				else {
					cout << horario_trenes[sol] << endl;
				}
			}
			catch (const exception&) {
				cout << "ERROR" << endl;
			}
		}
		cout << "---" << endl;

		cin >> trenes;
		cin >> nrHoras;
	}
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}

ostream& operator << (ostream &o, const Horas & h) {
	if (h.getHoras() >= 0 && h.getMinutos() >= 0 && h.getSegundos() >= 0 && h.getHoras() < 24 && h.getMinutos() < 60 && h.getSegundos() < 60) {
		o << setfill('0') << setw(2) << h.getHoras() << ":" << setfill('0') << setw(2) << h.getMinutos() << ":" << setfill('0') << setw(2) << h.getSegundos();
	}
	return o;
}

istream& operator>> (istream& is, Horas & hora){
	int horas;
	int minutos;
	int segundos;
	is >> horas;
	is.ignore();
	is >> minutos;
	is.ignore();
	is >> segundos;
	hora = Horas(horas, minutos, segundos);
	return is;
}


/*El coste de esta funcion es de O(nlog(n)) donde n hace referencia al tamaño del vector horario trenes. El coste es lineal
porque se utiliza una busqueda binaria y al mirar el elemento del medio se discrimina una mitad del vector*/
int buscarHoras(const vector<Horas> & horario_trenes, const Horas & hora){
	//horario en orden y correctas seguro

	bool encontrado = false;
	

	int ini = 0, fin = horario_trenes.size(), mitad = 0;

	while (ini < fin && !encontrado) {
		mitad = (ini + fin - 1) / 2;
		if (horario_trenes[mitad] == hora) encontrado = true;
		else if (horario_trenes[mitad] < hora) ini = mitad + 1;
		else fin = mitad;
	}

	if (horario_trenes[mitad] < hora) {
		if (mitad + 1 < horario_trenes.size()) {
			if (hora < horario_trenes[mitad + 1]) {
				mitad++;
			}
		}
		else {
			mitad = -1;
		}
	}

	return mitad;
}

