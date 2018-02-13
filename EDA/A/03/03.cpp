// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(const vector<int> datos, const int p) {
	bool resultado = false;
	int max; // maximo de la izquierda de p (p incluido)
	int min; // minimo de la derecha de p
	
	if (datos.size() == 0){
		resultado = true;
	}

	else if (p != datos.size()-1){
		max = datos[0];
		for (int i = 1; i <= p; i++){
			if (datos[i] > max){
				max = datos[i];
			}
		}
		min = datos[p+1];
		for (int i = p + 2; i < datos.size(); i++){
			if (datos[i] < min){
				min = datos[i];
			}
		}

		if (max < min){
			resultado = true;
		}
	}

	else{
		resultado = true;
	}

	return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	vector<int> datos;
	int nrElems,p,dato;

	cin >> nrElems >> p;

	for (int i = 0; i < nrElems;i++){
		cin >> dato;
		datos.push_back(dato);
	}

	if (resolver(datos,p)){
		cout << "SI" << endl;
	}
	else{
		cout << "NO" << endl;
	}
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