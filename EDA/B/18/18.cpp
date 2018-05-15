#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

//Andrei Ionut Vaduva E60

//Orden lineal respecto al numero de claves del diccionario antiguo O(antiguo.size())
vector<vector<string>> compararDiccionarios(const map<string, int> & antiguo, const map<string, int> & nuevo) {
	vector<vector<string>> sol = vector<vector<string>>(3); // en la pos 0 van las sumas, en la 1 las restas y en la 2 las modificaciones
	auto itAnt = antiguo.cbegin();
	auto itAntEnd = antiguo.cend();

	auto itNuevo = nuevo.cbegin();
	auto itNuevoEnd = nuevo.cend();

	while (itAnt != itAntEnd) { // mientras no se acabe el antiguo
		string claveAnt = itAnt->first;
		if (itNuevo != itNuevoEnd) {//si no hemos acabado el recorrido en el nuevo
			string claveNuevo = itNuevo->first;
			if (claveAnt < claveNuevo) { // si clave del ant < clave del nuevo entonces se ha borrado un elemento
				sol[1].push_back(claveAnt);
				itAnt++;
			}
			else if (claveAnt > claveNuevo) { // si la clave el ant es > que la del nuevo es que se ha añadido un elemento y se ha borrado uno del ant
				sol[0].push_back(claveNuevo);
				itNuevo++;
			}
			else {
				if (itAnt->second != itNuevo->second) {
					sol[2].push_back(claveAnt);//o claveNuevo, da igual
				}
				itNuevo++;
				itAnt++;
			}
		}
		else {//si ha acabado el recorrido del nuevo es que los demás del antiguo han sido eliminados
			sol[1].push_back(claveAnt);
			itAnt++;
		}
		
	}

	while (itNuevo != itNuevoEnd) {//si ha acabado el antiguo antes que el nuevo
		sol[0].push_back(itNuevo->first);
		itNuevo++;
	}
	return sol;
}

void rellenaDiccionario(map<string, int> & diccionario) {
	stringstream ss;
	string clave;
	int valor;
	string linea;

	getline(cin,linea);
	ss.str(linea);
	while(ss >> clave >> valor) {
		diccionario[clave] = valor;
	}
}

void mostrar(const vector<string> & sol, const char & tipo) {
	int tam = sol.size();
	if(tam > 0)
		cout << tipo << " ";
	for (int i = 0; i < tam-1; i++) {
		cout << sol[i] << " ";
	}
	if(tam > 0)
		cout << sol[tam-1] << endl;
}

void resuelveCaso() {
	
	map<string, int> antiguo;
	map<string, int> nuevo;
	vector<vector<string>> sol; // en la pos 0 van las sumas, en la 1 las restas y en la 2 las modificaciones
	
	rellenaDiccionario(antiguo);
	rellenaDiccionario(nuevo);

	sol = compararDiccionarios(antiguo,nuevo);

	if (sol[0].size() == 0 && sol[1].size() == 0 && sol[2].size() == 0)
		cout << "Sin cambios" << endl;
	else {
		mostrar(sol[0], '+');
		mostrar(sol[1], '-');
		mostrar(sol[2], '*');
	}
	cout << "----" << endl;
}


int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	cin >> casos;
	cin.ignore();
	for (int i = 0; i < casos; i++) {
		resuelveCaso();
	}


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


