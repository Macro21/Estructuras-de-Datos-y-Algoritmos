// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };

/*
El coste de esta funcion es O(n) ya que recorremos el vector una vez
*/

// función que resuelve el problema
int resolver(const vector<piedrasPreciosas> & datos, const int & tamSec, const int & numTipo1, const int & numTipo2, const piedrasPreciosas & tipo1, const piedrasPreciosas & tipo2) {

	int tamDatos = datos.size();
	int i = 0;
	int cont1 = 0;
	int cont2 = 0;
	int sol = 0;

	while (i < tamSec){
		if (datos[i] == tipo1){
			cont1++;
		}
		else if (datos[i] == tipo2) {
			cont2++;
		}
		i++;
	}

	int j = 0;
	while (j < tamDatos - tamSec){
		if (cont1 >= numTipo1 && cont2 >= numTipo2){
			sol++;
		}
		if (datos[j] == tipo1){
			cont1--;
		}
		else if (datos[j] == tipo2){
			cont2--;
		}
		if (datos[j + tamSec] == tipo1){
			cont1++;
		}
		else if (datos[j + tamSec] == tipo2){
			cont2++;
		}
		j++;
	}
	if (cont1 >= numTipo1 && cont2 >= numTipo2){
		sol++;
	}

	return sol;
}
std::istream& operator>> (std::istream& entrada, piedrasPreciosas& p) {
	char num;
	entrada >> num;
	switch (num) {
	case 'd': p = diamante; break;
	case 'r': p = rubi; break;
	case 'e': p = esmeralda; break;
	case 'z': p = zafiro; break;
	case 'j': p = jade; break;
	}
	return entrada;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	
	int tam;
	int numpiedras;
	int numtipo1, numtipo2;
	piedrasPreciosas tipo1, tipo2;

	cin >> tam >> numpiedras >> tipo1 >> numtipo1 >> tipo2 >> numtipo2;

	vector<piedrasPreciosas> v(tam);
	for (piedrasPreciosas& i : v)
		cin >> i;
	cout << resolver(v,numpiedras,numtipo1,numtipo2,tipo1,tipo2) << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}