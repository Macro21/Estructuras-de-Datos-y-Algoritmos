// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
/*void resolver(vector<int> & datos) {
	int i = 0;
	int j = 0;
	
	while (i < datos.size()-1){
		if (datos[i] % 2 != 0 && datos[i+1] % 2 == 0){
			int aux = datos[j]; // en realidad no hace falta porque al final lo vamos a borrar de todas formas
			datos[j] = datos[i+1];
			datos[i + 1] = aux;
			j++;
		}
		else if (datos[i] % 2 == 0){
			j++;
		}
		i++;
	}
	if (datos[datos.size()-1] % 2 == 0){
		j++;
	}
	datos.resize(j);
}*/

/*
	Tiene coste lineal ya que recorremos todo el vector y la funcion cota es datos.size() - i ya que decrece hasta 0
*/
void resolver(vector<int> & datos) {
	int i = 0;
	int j = 0;

	while (i < datos.size()){
		if (datos[i] % 2 == 0){
			if (i > j){
				datos[j] = datos[i];
			}
			j++;
		}
		i++;
	}
	datos.resize(j);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	
	vector<int> datos;
	datos.reserve(100);
	int nrElems,dato;


	cin >> nrElems;
	for (int i = 0; i < nrElems;i++){ //relleno el array
		cin >> dato;
		datos.push_back(dato);
	}
	resolver(datos);

    // escribir sol
	for (int i : datos){
		cout << i << " ";
	}
	cout << endl;
    
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