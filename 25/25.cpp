#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


void resuelve(const vector<int> & datos, int ini, int fin, int & min) {
	
	//No estoy seguro de si de esta forma estara bien. De esta manera se mira todo el vector
	//pero podrian obiarse ciertas divisiones sabiendo que una mitad es creciente
	if (ini == fin) {
		if (datos[ini] < min) {
			min = datos[ini];
		}
	}
	else if (ini + 1 == fin) {
		if (min > datos[ini]) {
			min = datos[ini];
		}
		if (min > datos[fin]) {
			min = datos[fin];
		}
	}
	else {
		int m = (ini + fin) / 2;
		resuelve(datos, ini, m, min);
		resuelve(datos, m + 1, fin, min);
	}
	
}



void resuelveCaso(const int & tamDatos) {
	int dato;
	vector<int> datos;
	bool seguir = true;

	for (int i = 0; i < tamDatos; i++) {
		cin >> dato;
		datos.push_back(dato);
	}
	int min = datos[0];
	resuelve(datos, 0, datos.size() - 1, min);
	cout << min << endl;
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int tamDatos;
	
	while (cin >> tamDatos){
		resuelveCaso(tamDatos);
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}