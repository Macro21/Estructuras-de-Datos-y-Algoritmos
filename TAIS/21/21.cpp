#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int resuelve(const vector<int> & datos, const int & pesoMax) {
	int sol = 0;
	int tam = datos.size() - 1;
	int i = 0;
	while ( i < datos.size() && i <= tam ) {
		if (datos[i] == pesoMax) {//si son iguales una silla seguro
			sol++;
			i++;
		}
		else if (datos[i] + datos[tam] <= pesoMax) { // si el primero mas el ultimo son menos que el max
			sol++;
			tam--;;
			i++;
		}
		else {
			sol++;
			tam--;
		}
	}
	return sol;
}

void resuelveCaso(const int & peso, const int & nrPersonas) {
	vector<int> datos;
	int p;
	for (int i = 0; i < nrPersonas; i++) {
		cin >> p;
		datos.push_back(p);
	}
	sort(datos.begin(),datos.end());

	cout << resuelve(datos,peso) << endl;
}


int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int peso;
	int nrPersonas;

	while (cin>>peso){
		cin >> nrPersonas;
		resuelveCaso(peso,nrPersonas);
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
