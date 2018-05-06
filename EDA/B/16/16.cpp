#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


//#include "bintree_ext.h"

#include "bintree_eda.h"

//Andrei Ionut Vaduva E60


// lee un árbol binario de la entrada estándar

const int VACIO = -1;

/*template <typename T>

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

}*/

bool primo(const int & n) {
	bool esPrimo = true;
	int divisible = 0;

	for (int i = 1; i < n + 1; i++) {
		if (n % i == 0)
			divisible++;
	}
	if (divisible != 2)
		esPrimo = false;

	return esPrimo;
}


pair<int, int> resuelve(const bintree<int> & arbol) {
	pair<int, int> sol (-1,-1);
	bool sum = false;
	if (!arbol.empty()) {
		queue<pair<bintree<int>,int>> pendientes;
		pair<bintree<int>, int> aux (arbol,1);
		pendientes.push(aux);
		bool enc = false;
		while (!pendientes.empty() && !enc){
			bintree<int> sig = pendientes.front().first;
			int nivel = pendientes.front().second;
			int elem = sig.root();
			pendientes.pop();
			if (!primo(elem)) {
				if (elem % 7 == 0) {
					sol.first = elem;
					sol.second = nivel;
					enc = true;
				}
				else {
					if (!sig.left().empty())
						pendientes.push(pair<bintree<int>,int> (sig.left(),nivel+1));
					if (!sig.right().empty())
						pendientes.push(pair<bintree<int>, int> (sig.right(),nivel+1));
				}
			}
		}
	}
	return sol;
}


void resuelveCaso() {

	bintree<int> arbol = leerArbol(VACIO);
	pair<int,int> sol = resuelve(arbol);

/*	bintree<int> arbol = leerArbol(VACIO);
	bool enc = false;
	pair<int, int> sol (-1,-1);
	int nivel = 1;
	queue<int> cola = queue<int>();
	cola.push(arbol.root());
	while (!cola.empty() && !enc){
		int elem = cola.front(); cola.pop();
		bool esPrimo = primo(elem);
		if (!esPrimo) {//si no es primo
			if (elem % 7 == 0) {//Si es solucion
				enc = true;
				sol.first = elem;
				sol.second = nivel;
			}
			else {//si no es sol y no es primo, meto a su hijo
				nivel++;
				if (!arbol.left().empty()) {
					cola.push(arbol.left().root());
				}
				
			}

		}
		else
		*/

	if (sol.second == -1)
		cout << "NO HAY" << endl;
	else	
		cout << sol.first << " " << sol.second << endl;
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


