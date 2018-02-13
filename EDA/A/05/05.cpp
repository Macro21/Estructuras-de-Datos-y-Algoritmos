// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


/*
Especifica un metodo que dado un vector de n´umeros enteros y un valor entero positivo (n > 0)
devuelva la posici´on mas a la derecha del vector que cumpla que la suma de los elementos del vector
desde el principio hasta dicha posici´on excluida es menor o igual que el numero dado. El vector
tendr´a al menos un elemento.

*/

// función que resuelve el problema
long long int resolver(const long long int & dato) {
	long long int resultado = 0;
	//por definicion
	long long int fib0 = 0;
	long long int fib1 = 1;
	
	if (dato < 2){
		resultado = dato;
	}		//fib(n) = fib(n-2) + fib(n-1)
	else{ //fib(2) = fib(2 - 2) + fib(2 -1) // sabes que n es mayor que 2
		for (long long int k = 1; k < dato; k++){//recorres todos los numeros hasta el dato
			long long int aux; //llevara la suma parcial
			aux = fib0 + fib1; //empezamos a sumar
			fib0 = fib1; //intercambios para preparar la suma siguiente
			fib1 = aux;
		}
		resultado = fib1;
	}
	return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(long long int dato) {
	// leer los datos de la entrada
	
	cout << resolver(dato) <<endl;
	
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	long long int dato;
	cin >> dato;
	while (dato != -1){
		resuelveCaso(dato);
		cin >> dato;
	}



	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}