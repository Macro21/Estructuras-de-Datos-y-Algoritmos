#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//vector ordenado al reves
int resuelve(const vector<int> & datos) {
	int sol = 0;
	int tam = datos.size() - 1;
	int cont = 0;
	
	while (tam >= 0){
		cont++;
		if (cont == 3) {
			sol += datos[tam];
			cont = 0;
		}
		tam--;
	}

	return sol;
}


void resuelveCaso(const int & nrLibros) {
	vector<int> datos;
	int p;

	for (int i = 0; i < nrLibros; i++) {
		cin >> p;
		datos.push_back(p);
	}
	sort(datos.begin(),datos.end());
	
	cout << resuelve(datos) << endl;
}

int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int nrLibros;

	while (cin>>nrLibros){
		resuelveCaso(nrLibros);
	}


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
