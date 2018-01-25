#include <iostream>
#include <string>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

long long int calcularGorras(PriorityQueue<long long int> pq, const long long int & nrEquipos) {
	long long int sol = 0;

	for (long long int i = 0; i < nrEquipos-1; i++) {
		long long int ns = pq.top();
		pq.pop();
		long long int ns2 = pq.top();
		sol += ns + ns2;
		pq.pop();
		pq.push(ns + ns2);
	}


	return sol;
}

void resuelveCaso(long long int nrEquipos) {
	PriorityQueue<long long int> pq = PriorityQueue<long long int>(nrEquipos);

	long long int nrSeguidores;

	for (long long int i = 0; i < nrEquipos; i++) {
		cin >> nrSeguidores;
		pq.push(nrSeguidores);
	}
	cout << calcularGorras(pq, nrEquipos) << endl;

}


int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	long long int nrEquipos;
	cin >> nrEquipos;
	while (nrEquipos != 0){
		resuelveCaso(nrEquipos);
		cin >> nrEquipos;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
