#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "bintree_eda.h"

const int VACIO = -1;

//Andrei Ionut Vaduva E60

pair<int, int> resolver(const bintree<int> & arbol) {
	
	pair<int,int> sol;
	pair<int, int> solIzq;
	pair<int, int> solDer;

	if (arbol.empty()) {
		sol.first = 0;
	}
	else if (arbol.left().empty() && arbol.right().empty()) {
		if (arbol.root() == 0)
			sol.first = 1;
		else
			sol.first = 0;
	}
	else {
		solIzq = resolver(arbol.left());
		solDer = resolver(arbol.right());
		sol.first = solIzq.first + solDer.first;
		sol.second = solIzq.second + solDer.second;
		sol.first -= arbol.root();
		if (sol.first < 0)
			sol.first = 0;
		if (solIzq.first >= 3)
			sol.second++;
		if (solDer.first >= 3)
			sol.second++;
	}
	return sol;
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(VACIO);
	cout << resolver(arbol).second << endl;

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


