// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef struct{
	int i;
	int j;
}tRango;


void normalizaVar(int & pos, const int & n){

	while(pos >= n){
		pos = pos - n;
	}

}


// función que resuelve el problema
void resolver(const vector<string> & datos, const int & m, const int & nRel, tRango & sol, const int & n) {
	tRango aux; aux.i = -1; aux.j = -1;
	int iniF = 0;
	int finF = -1;
	bool estamosBlanco=false; // es true si ya hemos encontrado el primer pixel el blanco
	bool inicializa = true;
	int cont = 0;
	int contMax = 0;
	for (int i = m; i < nRel; i++){
		string dato = datos[i];
		if (dato == "FFFFFF" && !estamosBlanco){ // Si es blanco y esta al principio
			aux.i = i;
			if (inicializa)
				iniF = i;
			estamosBlanco = true;
		}
		else if (dato != "FFFFFF" && estamosBlanco){
			aux.j = i - 1;
			estamosBlanco = false;
			if (inicializa){
				finF = aux.j;
				inicializa = false;
			}
			cont = aux.j - aux.i;
			if (contMax < cont ){
				contMax = cont;
				iniF = aux.i;
				finF = aux.j;
			}
		}
		if (i == nRel - 1 && estamosBlanco){
			cont = i - aux.i;
			if (contMax < cont || inicializa){
				iniF = aux.i;
				finF = i;
			}
		}
	}
	normalizaVar(iniF, n);
	normalizaVar(finF,n);
	sol.i = iniF;
	sol.j = finF;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(const int & m) {
	// leer los datos de la entrada
	
	int n;
	string color;
	vector<string> datos;
	tRango sol;
	cin >> n;
	
	for (int i = 0; i < (m*n);i++){
		cin >> color;
		datos.push_back(color);
	}
	//El coste de esta funcion es lineal respecto al numero de datos, es decir n*m, ya que no procesamos dos veces el mismo dato
	for (int j = 0; j < m; j++){
		resolver(datos, j*n, n+(j*n), sol,n);
		cout << sol.i << " " << sol.j << endl;
	}
	
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	int m;
	cin >> m;
	while (!cin.fail()){
		resuelveCaso(m);
		cin >> m;
		if (!cin.fail()){
			cout << endl;
		}
	}
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}