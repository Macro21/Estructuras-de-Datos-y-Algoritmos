#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "lista_creciente.h"
#include "Horas.h"

//Andrei Ionut Vaduva E60
void resuelveCaso(int dato) {

	ListaCreciente <Horas> list = ListaCreciente<Horas>();

	int h,m,s;
	while (dato != 0) {
		cin >> h;
		cin.ignore();
		cin >> m;
		cin.ignore();
		cin >> s;
		Horas hora = Horas(h,m,s);
		list.push(hora);
		dato--;
	}

	list.listaCreciente();

	/*for (size_t i = 0; i < list.size(); ++i) {

		Horas elem = list.front(); list.pop();

		list.push(elem);

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