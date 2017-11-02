// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

typedef struct {
	int ini;
	int fin;
}tRango;


/*
El coste de esta funcion es lineal, recorremos el vector una sola vez y procesamos cada dato una sola vez. O(n)
*/

// función que resuelve el problema
int resolver(const vector<int> & datos) {
	int p = -1; //p
	int tamDatos = datos.size();
	int contUnos = 0;
	int contCeros = 0;

	for (int i = 0; i < tamDatos; i++){
		int dato = datos[i];
		if (dato == 1){
			contUnos++;
		}
		else if (dato == 0){
			contCeros++;
		}
		if (contUnos == contCeros){
			contUnos = 0;
			contCeros = 0;
			p = i;
		}
	}

	return p;
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
	sol = resolver(datos);
	cout << sol << endl;
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