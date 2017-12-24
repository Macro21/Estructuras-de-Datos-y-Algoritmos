#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


int resuelve(const vector<int> & datos, int ini, int fin, bool & encontrado, const int & cantado) {
	int sol = -1;

	if (!encontrado) {
		if (ini == fin) {//vector vacio
			if (datos[ini] == cantado + ini) {
				encontrado = true;
				return datos[ini];
			}
		}
		else if (ini + 1 == fin) {
			if (datos[ini] == cantado + ini) {
				encontrado = true;
				return datos[ini];
			}
			else if (datos[fin] == cantado + fin) {
				encontrado = true;
				return datos[fin];
			}
		}
		else {
			int m = (ini+fin) / 2;
			sol = resuelve(datos,ini,m,encontrado,cantado);
			if (!encontrado) {//si no lo ha encontrado miro la otra mitad
				sol = resuelve(datos, m + 1, fin, encontrado, cantado);
			}
		}
	}
	return sol;
}



void resuelveCaso() {
	int dato;
	int nrPorCarton;
	int nrCantado;
	int sol;

	vector<int> datos;
	bool encontrado = false;

	cin >> nrPorCarton >> nrCantado;
	
	for (int i = 0; i < nrPorCarton; i++) {
		cin >> dato;
		datos.push_back(dato);
	}

	sol = resuelve(datos, 0, datos.size() - 1, encontrado, nrCantado);

	if (sol == -1)
		cout << "NO" << endl;
	else
		cout << sol << endl;
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