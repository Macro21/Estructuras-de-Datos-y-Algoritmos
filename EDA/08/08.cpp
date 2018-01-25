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
}tSol;


/*
	El coste de esta funcion es lineal, recorremos el vector una sola vez y procesamos cada dato una sola vez. O(n)
*/

void resolver(const vector<int> & datos, const int & t, tSol & sol){

	int tamDatos = datos.size();

	int i = 0;
	int iniUltSeg = 0;
	int maxLong = 0;
	int ini = 0;

	while (i<tamDatos){
		if (datos[i] > t){
			if (maxLong < i - iniUltSeg + 1){
				ini = iniUltSeg;
				maxLong = i - iniUltSeg + 1;
			}
		}
		else{
			iniUltSeg = i + 1;
		}
		i++;
	}
	sol.ini = ini;
	sol.fin = ini + maxLong - 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	vector<int> datos;
	int nrEdificios;
	int t;
	int dato;
	tSol sol;

	cin >> nrEdificios >> t;

	for (int i = 0; i < nrEdificios; i++){
		cin >> dato;
		datos.push_back(dato);
	}
	resolver(datos, t,sol);
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