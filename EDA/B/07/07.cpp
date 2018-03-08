#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "InvertirLista.h"

//Andrei Ionut Vaduva E60

void resuelveCaso(int dato) {

	ListaInvierte <int> list = ListaInvierte<int>();
	
	while (dato != 0) {
		list.push_back(dato);
		cin >> dato;
	}

	list.invierte();

	/*for (size_t i = 0; i < list.size(); ++i) {

		int elem = list.front(); list.pop_front();

		list.push_back(elem);

	}*/
	
	list.print();
}


int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int dato;
	while (cin >> dato) {
		resuelveCaso(dato);
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}