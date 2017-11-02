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
tRango resolver(const vector<int> & datos, const int & t) {
	tRango aux; aux.ini = -1; aux.fin = -1;
	tRango sol; sol.ini = -1; sol.fin = -1;
	bool enRango = false;
	int tamDatos = datos.size();

	for (int i = 0; i < tamDatos;i++){
		int dato = datos[i];
		if (dato > t && !enRango){ // si tenemos buena altura
			if (sol.ini == -1){
				sol.ini = i;
			}
			enRango = true;
			aux.ini = i;
		}
		else if (dato <= t && enRango){
			aux.fin = i - 1;
			enRango = false;
			if (sol.fin == -1){
				sol.fin = aux.fin;
			}
			if ((aux.fin - aux.ini) > (sol.fin - sol.ini)){
				sol = aux;
			}
		}
		if (i == tamDatos - 1 && enRango ){
			if ((i - aux.ini) > (sol.fin - sol.ini) || sol.fin == -1){
				sol.fin = i;
				sol.ini = aux.ini;
				enRango = false;
			}
		}

	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	vector<int> datos;
	int nrEdificios;
	int t;
	int dato;
	tRango sol;

	cin >> nrEdificios >> t;

	for (int i = 0; i < nrEdificios; i++){
		cin >> dato;
		datos.push_back(dato);
	}
	sol = resolver(datos, t);
	cout << sol.ini << " " << sol.fin << endl;
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