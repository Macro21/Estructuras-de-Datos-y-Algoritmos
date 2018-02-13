// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


/*
El coste de esta funcion es lineal, recorremos el vector una sola vez y procesamos cada dato una sola vez. O(n)
*/

// función que resuelve el problema
int resolver(const vector<int> & datos) {
	int sol = 0;
	int max = datos[0];
	int tam = datos.size();
	int sumMaxParciales = datos[0];


	for (int i = 1; i < tam; i++){
		int dato = datos[i];
		if (dato > max){
			sol += sumMaxParciales;
			max = dato;
			sumMaxParciales = max;
		}
		else if (dato==max){
			sumMaxParciales += dato;
		}
		else{
			sol += dato;
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	vector<int> datos;
	int nrElems;
	int dato;
	int sol;

	cin >> nrElems;

	for (int i = 0; i < nrElems; i++){
		cin >> dato;
		datos.push_back(dato);
	}
	
	cout << resolver(datos) << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}