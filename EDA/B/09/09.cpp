#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//Andrei Ionut Vaduva E60

int resuelveCaso() {
	int alt = 0;
	int aux;
	int nodo;
	cin >> nodo;
	if (nodo > 0) {
		for (int i = 0; i < nodo; i++) {
			aux = resuelveCaso();
			if (aux > alt) {
				alt = aux;
			}
		}
		alt += 1;
	}
	else {
		alt = 1;
	}
	return alt;
}



int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		cout << resuelveCaso() << endl;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


