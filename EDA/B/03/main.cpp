#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "Complejo.h"

//Andrei Ionut Vaduva E60


bool divergente(const Complejo<float> & c, const int & n) {

	int i = 0;
	bool divergente = false;

	Complejo<float> z = Complejo<float>(0, 0);

	while (i < n && !divergente) {
		z = (z * z) + c;
		if (z.mod() > 2)
			divergente = true;
		i++;
	}
	return divergente;
}

void resuelveCaso() {
	float real;
	float imag;
	int n;
	
	cin >> real >> imag >> n;

	Complejo<float> c = Complejo<float>(real,imag);

	if (divergente(c, n)) 
		cout << "NO" << endl;
	else 
		cout << "SI" << endl;
	

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