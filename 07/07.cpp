// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef struct{
	int inicio;
	int fin;
}tSol;

/*Esta funcion tiene coste O(n) ya que tiene un bucle que se va acortando conforme la variable i se acerca a tamDatos, es decir
se recorren todos los elementos del array una sola vez*/
void resolver(const vector<string> & datos, tSol & sol){

	int tamDatos = datos.size();
	tSol solParcial;
	int i = 0;
	int iniUltSeg = 0;
	int maxLong = 0;
	int ini = 0;

	while (i<tamDatos){
		if (datos[i] == "FFFFFF"){
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
	sol.inicio = ini;
	sol.fin = ini + maxLong - 1;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(const int & nrCol) {
	// leer los datos de la entrada
	
	vector<string> datos;
	string color;
	tSol sol; sol.inicio = 0; sol.fin = -1;
	
	for (int i = 0; i <nrCol; i++){
		cin >> color;
		datos.push_back(color);
	}
	resolver(datos,sol);
	cout << sol.inicio << " " << sol.fin << endl;
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
		for (int i = 0; i < nrFilas;i++){
			resuelveCaso(nrCol);
		}
	}
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}