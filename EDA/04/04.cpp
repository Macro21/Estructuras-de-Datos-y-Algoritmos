#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;




/*
Implementa un programa que dado un vector v calcule sobre un vector diferente sol la suma
acumulada de los elementos. Esto es sol[n] == v[n], sol[n-1] == v[n] + v[n-1],
sol[n-2] == v[n] + v[n-1] + v[n-2], y as´ı sucesivamente, siendo n la ´ultima posici´on del vector.
a) Especifica el problema en Dafny
b) Resuelve el problema suponiendo que el vector de entrada tiene al menos un valor
c) Resuelve el problema suponiendo que el vector de entrada puede ser vac´ıo.
d) Verifica cada uno de los problemas y s´ubelos al juez en el problema 04 (primero uno y cuando
de correcto, el otro)

*/

// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resolver(const vector<int> & datos, vector<int> & sol) {
	int tamDatos = datos.size();
	int i = tamDatos-1;
	sol[i] = datos[i];
	while (0 <= i-1){
		sol[i-1] = sol[i] + datos[i-1];
		i--;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(int dato) {
	// leer los datos de la entrada
	vector<int> datos;
	vector<int> sol;
	
	while (dato != 0){
		datos.push_back(dato);
		cin >> dato;
	}
	int tamDatos = datos.size();
	sol = vector<int>(tamDatos);
	resolver(datos, sol);
	for (int i = 0; i < tamDatos; i++){
		cout << sol[i] << " ";
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	int dato;
	cin >> dato;
	while (dato != 0){
		resuelveCaso(dato);
		cout << endl;
		cin >> dato;
	}
	


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}