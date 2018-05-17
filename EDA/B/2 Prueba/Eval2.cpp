#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "bintree_eda.h"


//Andrei Ionut Vaduva E60

struct tSol {
	bool esZurdo = false;
	int nrHijos = 0;
};

tSol resuelve(const bintree<char> & arbol) {
	tSol sol;
	tSol solIzq;
	tSol solDer;

	if (arbol.empty()) {
		sol.esZurdo = true;
		sol.nrHijos = 0;
	}
	else if (arbol.left().empty() && arbol.right().empty()) { //si los dos hijos son vacios, el arbol es hoja
		sol.esZurdo = true;
		sol.nrHijos = 1;
	}
	else {
		solIzq = resuelve(arbol.left());
		solDer = resuelve(arbol.right());
		// si el de la derecha o el de la izq no son zurdos o si el nr de hijos del izq es mayor o igual que el de la derecha no es zurdo
		double total = solIzq.nrHijos + solDer.nrHijos;
		double p = (solDer.nrHijos * 100) / total;
		if (!solIzq.esZurdo || !solDer.esZurdo || p >= 50 ) { 
			sol.esZurdo = false;
		}
		else {
			sol.esZurdo = true;
			sol.nrHijos = solDer.nrHijos + solIzq.nrHijos + 1; //el +1 es porque me sumo a mi mismo
		}
	}
	return sol;
}


void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	tSol sol = resuelve(arbol);
	if (sol.esZurdo) {
		cout << "SI" << endl;
	}
	else
		cout << "NO" << endl;
}

int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		resuelveCaso();
	}
	

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


