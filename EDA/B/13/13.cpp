#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//#include "bintree_eda.h"
#include "bintree_ext.h"


//Andrei Ionut Vaduva E60


// lee un árbol binario de la entrada estándar

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
/*
template <class T>
T buscarMinimo(bintree<T> & arbol) {
	T min;
	if (!arbol.empty()) {
		vector<T> nodos = arbol.inorder();
		min = nodos[0];
		for (int i = 1; i < nodos.size(); i++) {
			if (min > nodos[i]) {
				min = nodos[i];
			}
		}
	}

	return min;
}

bool resuelveCaso() {
	char tipo;

	cin >> tipo;
	if (!cin)
		return false;

	if (tipo == 'N') {
		bintree<int> arbol = leerArbol(-1);
		int min = buscarMinimo(arbol);
		cout << min << endl;
	}
	else {
		string vacio = "#";
		bintree<string> arbol = leerArbol(vacio);
		string min = buscarMinimo(arbol);
		cout << min << endl;
	}
	
	return true;
}
*/
bool resuelveCaso() {
	char tipo;

	cin >> tipo;
	if (!cin)
		return false;

	if (tipo == 'N') {
		bintree_ext<int> arbol = leerArbol_ext(-1);
		cout << arbol.buscarMinimo() << endl;
	}
	else {
		string vacio = "#";
		bintree_ext<string> arbol = leerArbol_ext(vacio);
		cout << arbol.buscarMinimo() << endl;
	}

	return true;
}

int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while(resuelveCaso());
	

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


