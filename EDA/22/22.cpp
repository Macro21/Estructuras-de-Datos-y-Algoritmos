#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60

struct tSol {
	int min = 10000000;
	int max = -1;
};

tSol pOrdenado(const vector<int> & datos, int ini, int fin, bool & seguir) {
	tSol solIz;
	tSol solDr;
	tSol sol;
	if (seguir) {
		if (ini == fin) {//si solo hay un elemento
			seguir = true;
			return sol;
		}
		else if (solIz.min > solDr.min) {//si el minIz es mayor que el min dr, ya no esta parcialmente ordenado
			seguir = false;
		}
		else if (ini + 1 == fin) {//no se puede dividir mas
			if (datos[ini]>datos[fin]) {
				seguir = false;
			}
			else {//si el segundo elem es mayor ese será el maximo
				if(sol.min > datos[ini])
					sol.min = datos[ini];
				if(sol.max < datos[fin])
					sol.max = datos[fin];
				return sol;
			}
		}
		else { //si se puede dividir
			int m = (ini + fin) / 2;
			solIz = pOrdenado(datos, ini, m, seguir);
			solDr = pOrdenado(datos, m+1, fin, seguir);
			if (solIz.max > solDr.max) {
				seguir = false;
			}
			else if (solIz.min > solDr.min) {
				seguir = false;
			}
			sol.max = solDr.max;
			sol.min = solIz.min;
		}
	}
	return sol;
}

void resuelveCaso() {
	int dato;
	vector<int> datos;
	bool seguir = true;

	cin >> dato;
	while (dato != 0){
		while (dato != 0){
			datos.push_back(dato);
			cin >> dato;
		}
		pOrdenado(datos, 0, datos.size() - 1, seguir);
		datos.clear();
		
		if (seguir)
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
		seguir = true;
		cin >> dato;
	}
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	
	resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}