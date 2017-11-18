// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


/*
El coste de esta funcion es O(nrFilas*nrColumnas) ya que recorremos la matriz una vez
*/

// función que resuelve el problema
int resolver(const vector<vector<int>> & matriz) {
	
	int nrFilas = matriz.size();
	int nrCol = matriz[0].size();
	int sol = 0;
	for (int i = 0; i < nrFilas; i++){
		for (int j = 0; j < nrCol; j++){
			if (matriz[i][j] == i){
				sol++;
			}
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(const int & nrFilas, const int & nrCol) {
	// leer los datos de la entrada
	vector<vector<int>> matriz (nrFilas,vector<int>(nrCol));
	int dato;

	for (int i = 0; i < nrFilas; i++){
		for (int j = 0; j < nrCol;j++){
			cin >> dato;
			matriz[i][j] = dato;
		}
	}
	cout << resolver(matriz) << endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int nrFilas;
	int nrCol;

	while (cin >> nrFilas){
		cin >> nrCol;
		resuelveCaso(nrFilas, nrCol);
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}