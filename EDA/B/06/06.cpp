#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "06.h"

//Andrei Ionut Vaduva E60



void resuelveCaso(int dato) {
	ListaDuplica<int> q = ListaDuplica<int>();
	
	while (dato != 0) {
		q.push(dato);
		cin >> dato;
	}
	q.duplica();

	/*for (size_t i = 0; i < q.size(); ++i) {
		int elem = q.front();
		q.pop();
		q.push(elem);
	}
	*/
	//cout << q << endl;
	q.print();
}


int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int dato;
	while (cin>>dato){
		resuelveCaso(dato);

	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}