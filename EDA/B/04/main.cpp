#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "Polinomio.h"

//Andrei Ionut Vaduva E60

void resuelveCaso(int c) {
	bool ok = true;
	int e, n, x;
	Polinomio pol = Polinomio();
	while (cin >> e && !(c == 0 && e==0)){
		pol.insertarMonomio(c,e);
		cin >> c;
	}

	cin >> n;

	for (int i = 0; i < n - 1;i++) {
		cin >> x;
		cout << pol.evaluacionX(x) << " ";
	}

	cin >> x;
	cout << pol.evaluacionX(x) << endl;
}


int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int c;
	while (cin >> c) {
		resuelveCaso(c);
	}


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}