#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60



/*
Coste en el caso peor: tamaño de los datos n = (fin - ini)/2, es decir que el minimo se encuentre
en alguno de los extremos, como no miramos las de partes porque miramos la mitad y si el valor medio
es menor que el valor que hay a la derecha sabemos que el minimo pude estar en el lado contrario,
ya que el vector esta ordenado de forma creciente y decreciente, o decreciente y creciente,
por lo que miraremos solo una parte del fector y no todo.

T(n) = {c1  si n = 1}
T(n) = {T(n/2) + c1 si n > 1}
En conclusion, en el peor de los casos el coste es log n ya que nos vemos obligados a mirar la mitad del vector entera.
*/

void resuelve(const vector<int> & datos, int ini, int fin, int & min) {

	if (ini == fin) {
		if (datos[ini] < min) {
			min = datos[ini];
		}
	}
	else if (ini + 1 == fin) {
		if (min > datos[ini]) {
			min = datos[ini];
		}
		if (min > datos[fin]) {
			min = datos[fin];
		}
	}
	else {
		int m = (ini + fin) / 2;
		//min = datos[m];
		if (datos[m + 1] >= datos[m - 1] || datos[ini] < datos[fin]) {//si el elemento a la derecha de m es mayor que el que esta a la iz entonces el min esta en la otra mitad
			resuelve(datos, ini, m, min);
		}
		if (datos[m + 1] < datos[m - 1] || datos[ini] > datos[fin]) { // si no, si es menor, entonces hay que buscar en esa mitad
			resuelve(datos, m + 1, fin, min);
		}
	}

}


void resuelveCaso(const int & tamDatos) {
	int dato;
	vector<int> datos;

	for (int i = 0; i < tamDatos; i++) {
		cin >> dato;
		datos.push_back(dato);
	}
	int min = datos[0];
	resuelve(datos, 0, datos.size() - 1, min);
	cout << min << endl;
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int tamDatos;

	while (cin >> tamDatos) {
		resuelveCaso(tamDatos);
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}