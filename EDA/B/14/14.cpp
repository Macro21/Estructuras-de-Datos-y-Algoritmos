#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "bintree_eda.h"
#include "info_h.h"
//Andrei Ionut Vaduva E60
const int VACIO = -1;

Info calcularEquipos(const bintree<int> & arbol) {
	Info sol;
	Info solIzq;
	Info solDer;

	if (arbol.empty()) {
		sol = Info(0,0);
	}
	else if (arbol.left().empty() && arbol.right().empty()) {//hoja
		if (arbol.root() != 0)
			sol = Info(1, arbol.root());
		else
			sol = Info(0, 0);
	}
	else {
		solIzq = calcularEquipos(arbol.left());
		solDer = calcularEquipos(arbol.right());
		int esc = arbol.root();
		if (esc != 0 && solIzq.getSol() == 0 && solDer.getSol() == 0) 
			sol += Info(1, esc);
		else {
			int nrEscIzq = solIzq.getNrExcursionistas();
			int nrEscDer = solDer.getNrExcursionistas();
			if (nrEscIzq > nrEscDer)
				sol += Info(0, nrEscIzq + esc);
			else
				sol += Info(0, nrEscDer + esc);
		}
		sol.setSol(sol.getSol() + solIzq.getSol() + solDer.getSol());
	}

	return sol;
}

void resuelveCaso() {

	bintree<int> arbol = leerArbol<int>(VACIO);

	Info sol = calcularEquipos(arbol);

	cout << sol.getSol() << " " << sol.getNrExcursionistas() << endl;
}


int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		resuelveCaso();
	}
	

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


