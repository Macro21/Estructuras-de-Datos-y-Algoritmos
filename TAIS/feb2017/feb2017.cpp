#include <iostream>
#include <string>
#include <fstream>
#include "Matriz.h"
#include "Grafo.h"
using namespace std;

vector<bool> marked;

void resuelve(const Grafo & g, int v, int & sol, int & nrManchas) {

	marked[v] = true;
	for (int w: g.adj(v)) {
		if (!marked[w]){
			sol++;
			resuelve(g,w,sol,nrManchas);
		}
	}

}


void crearGrafo(const Matriz<char> & matriz, Grafo & g) {
	int filas = matriz.numfils();
	int cols = matriz.numcols();
	int v1 = -1;
	int v2 = -1;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < cols; j++) {
			if (matriz[i][j] == '#') {
				//Colocar arista
				if(j + 1 < cols && matriz[i][j + 1] == '#' ){ // miro derecha de la casilla en la que estoy
					v1 = (i * cols) + j;
					v2 = (i * cols) + j + 1;
					g.ponArista(v1,v2);
				}
				if (i+1 < filas && matriz[i+1][j] == '#' ) {//rango && pixel negro, NOautoarista
					v1 = (i * cols) + j;
					v2 = ((i+1) * cols) + j;
					g.ponArista(v1,v2);
				}
			}
		}
	}

}

void resuelveCaso(const int & nrFilas, const int & nrCols) {
	char p;
	Matriz<char> matriz = Matriz<char>(nrFilas,nrCols,'-');
	marked = vector<bool>(nrFilas*nrCols, false);
	Grafo g = Grafo(nrFilas*nrCols);
	int sol = 0;
	int nrManchas = 0;

	for (int i = 0; i < nrFilas; i++) {
		for (int j = 0; j < nrCols; j++) {
			cin >> p;
			if (p == '#') {
				matriz[i][j] = '#';
			}
		}
	}

	crearGrafo(matriz,g);
	//hacer un for hasta nrFilas*nrCols de los vertices
	for (int i = 0; i < nrFilas*nrCols; i++) {
		int aux = 0;
		resuelve(g, i, aux,nrManchas);
		if (aux > sol) {
			sol = aux;
		}
		if (aux > 0) {
			nrManchas++;
		}
	}
	cout << nrManchas << " " << sol + 1 << endl;
}

int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int nrFilas;
	int nrCols;
	while (cin>>nrFilas){
		cin >> nrCols;
		resuelveCaso(nrFilas,nrCols);
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
