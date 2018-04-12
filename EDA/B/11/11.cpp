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

const char VACIO = '.';

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
	bintree_ext<char> arbol =  leerArbol_ext(VACIO);
	Info i = arbol.calcularInfoArbol();
	cout << i.getNrNodos() << " " << i.getNrHojas() << " " << i.getAltura() << endl;
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


