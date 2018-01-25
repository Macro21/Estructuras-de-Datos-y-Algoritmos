#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


int degradado(const vector<int> & datos, int ini , int fin, bool & seguir) {
	int sumaIz;
	int sumaDr;
	int suma = 0;
	if (seguir) {//si en algun punto no es un degradado no hace falta mirar mas
		if (ini == fin) { // vector vacio
			seguir = false;
			return -1;
		}
		else if (ini + 1 == fin) {//si no podemos dividir mas
			if (datos[ini] > datos[fin]) {
				seguir = false;
			}
			else {//sino devuelvo la suma
				return datos[ini] + datos[fin];
			}
		}
		else {//dividimos el vector en dos partes en cada llamada
			int m = (ini + fin) / 2;
			sumaIz = degradado(datos, ini, m, seguir);
			sumaDr = degradado(datos, m+1, fin, seguir);
			if (sumaIz > sumaDr) {
				seguir = false;
			}
			suma = sumaIz + sumaDr;
		}
	}
	return suma;
}

void resuelveCaso(const int & m) {

	vector<int> datos;
	int n;
	int color;
	int res;
	bool seguir = true;

	cin >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {//relleno la fila del vector
			cin >> color;
			datos.push_back(color);
		}
		if (seguir) {
			res = degradado(datos, 0, datos.size() - 1, seguir); // miro solo la fila
			datos.clear(); // una vez tengo el resultado elimino la fila
		}
		else //si no tengo que seguir mirando, tengo que leer los siguientes numeros para no leer datos incorrectos.
			cin.get();
	}
	if (seguir || res == -1)
		cout << "SI" << endl;
	else 
		cout << "NO" << endl;
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	int m;

	while (cin>>m){
		resuelveCaso(m);
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}