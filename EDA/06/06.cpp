// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

typedef struct {
	int pos;
	int beneficio;
}tSol;
/*
// función que resuelve el problema
void resolver(const vector<int> & datos, int tiempo,tSol & sol) {
	int maxBeneficio=0;
	int tamDatos = datos.size();
	sol.beneficio = 0;
	sol.pos = 0;
	

	//ASI NO VALE PORQUE PUEDES PONER LA K EN FUNCION DE N entonces deja de ser lineal respecto a k!!!!!!


	//Aunque tenga dos bucles for, el coste creo que es O(n), el primer bucle da tamDatos-tiempo vueltas y el segundo siempre da tiempo vueltas
	//por lo que el coste seria O(tiempo*i), donde tiempo es una constante en cada caso/
	for (int i = 0; i <= tamDatos-tiempo; i++){ //este bucle da tamDatos-tiempo vueltas por lo que es linear respecto a tamDatos
		int benef = 0;
		int k = i + tiempo;
		for (int j = i; j < k; j++){ // este bucle da k vueltas, por lo que es lineal respecto a k!!!
			benef += datos[j];
		}
		if (benef >= maxBeneficio && tiempo != 0){
			maxBeneficio = benef;
			sol.beneficio = benef;
			sol.pos = i;
		}
	}
}*/

void resolver(const vector<int> & datos, int tiempo, tSol & sol) {
	int tamDatos = datos.size();
	int benef = 0;

	for (int i = 0; i < tiempo; i++){
		benef += datos[i];
	}
	sol.beneficio = benef;
	
	for (int i = 0; i < tamDatos - tiempo; i++){ 
		benef = benef + datos[i+tiempo];
		benef = benef - datos[i];

		if (benef >= sol.beneficio){
			sol.beneficio = benef;
			sol.pos = i + 1;
		}
	}
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int vagonesTotales;
	int tiempo;
	int vagones;
	vector<int> datos;
	tSol sol; sol.pos = 0; sol.beneficio = 0;
	cin >> vagonesTotales >> tiempo;
	for (int i = 0; i < vagonesTotales; i++){
		cin >> vagones;
		datos.push_back(vagones);
	}
	resolver(datos,tiempo,sol);

	cout << sol.pos << " " << sol.beneficio << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	int nrCasos;
	cin >> nrCasos;
	for (int i = 0; i < nrCasos;i++){
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}