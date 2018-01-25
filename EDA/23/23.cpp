#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


void resuelve(const vector<char> & datos, int ini, int fin, bool & encontrado, char & sol, const char & datoIni, const char & datoFin) {

	if (!encontrado) {
		if (ini == fin) {
			if (datos[ini] - datos[fin - 1] != 1) {
				encontrado = true;
				sol = datos[ini] - 1;
			}
			else if (datos[fin + 1] - datos[ini] != 1) {
				encontrado = true;
				sol = datos[ini] + 1;
			}
		}
		else if (ini + 1 == fin) {
			if (datos[fin] - datos[ini] > 1) {
				sol = datos[ini] + 1;//devuelvo la que falta
				encontrado = true;
			}
		}
		else {
			int m = (ini + fin) / 2;
			resuelve(datos, ini, m, encontrado, sol, datoIni, datoFin);
			if (!encontrado) {
				if (datos[m + 1] - datos[m] == 1) {
					resuelve(datos, m + 1, fin, encontrado, sol, datoIni, datoFin);
				}
				else {
					encontrado = true;
					sol = datos[m] + 1;
				}
			}
		}
	}
}


void resuelveCaso() {
	char dato;
	char datoIni;
	char datoFin;
	char sol;
	vector<char> datos;
	bool encontrado = false;

	cin >> datoIni >> datoFin;
	int n = datoFin - datoIni;
	for (int i = 0; i < n; i++){
		cin >> dato;
		datos.push_back(dato);
	}
	if (datos[0] - datoIni != 0)
		sol = datoIni;
	else if (datos[datos.size()-1] - datoFin != 0)
		sol = datoFin;
	else
		resuelve(datos, 0, datos.size() - 1, encontrado, sol, datoIni, datoFin);

	cout << sol  << endl;
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}