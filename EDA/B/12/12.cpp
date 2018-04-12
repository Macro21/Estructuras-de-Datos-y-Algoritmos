#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "bintree_ext.h"


//Andrei Ionut Vaduva E60


// lee un árbol binario de la entrada estándar

const int VACIO = -1;

template <typename T>

bintree_ext<T> leerArbol_ext(T vacio) {

	T raiz;

	std::cin >> raiz;

	if (raiz == vacio) { // es un árbol vacío

		return {};

	}
	else { // leer recursivamente los hijos

		auto iz = leerArbol_ext(vacio);

		auto dr = leerArbol_ext(vacio);

		return { iz, raiz, dr };

	}

}

void resuelveCaso() {
	vector<int> sol;
	bintree_ext<int> arbol =  leerArbol_ext(VACIO);

	arbol.frontera(sol);
	int tam = sol.size();
	if ( tam > 0) {
		vector<int>::iterator it = sol.begin();
		vector<int>::iterator itEnd = sol.end() - 1;

		while (it != itEnd) {
			cout << *it << " ";
			it++;
		}
		cout << *it << endl;
	}
	else
		cout << endl;
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


