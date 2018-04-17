#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//Andrei Ionut Vaduva E60

int resuelveCaso(const int & N, int nrJefes) {
	int sol = 0;
	int aux = 0;
	int nodo;
	cin >> nodo;

	if (nodo > 0) {
		nrJefes++;
		for (int i = 0; i < nodo; i++) {
			sol += resuelveCaso(N,nrJefes);
		}
	}
	else {
		if (nrJefes >= N) {
			sol = 1;
		}
		else
			sol = 0;
	}
	return sol;
}



int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	int nJefes;
	int cont = 0;
	while (cin >> nJefes) {
		cout << resuelveCaso(nJefes,cont) << endl;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


