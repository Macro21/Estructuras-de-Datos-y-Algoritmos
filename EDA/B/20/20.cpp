#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

//Andrei Ionut Vaduva E60

const string FIN = "_FIN_";


bool miOperador(const pair<string,int> & a, const pair<string, int> & b) {
	if (a.second > b.second) {
		return true;
	}
	else if (a.second < b.second) {
		return false;
	}
	else {
		return a.first < b.first;
	}
}


void resuelveCaso(string & palabra) {
	
	unordered_map<string, int> deportes; // deporte,nrAlumnos apuntados en total
	unordered_map<string, pair<bool,string>> alumnos; // alumno, (estaApuntadoAunDeporte,deporte)

	string deporteAct;
	
	//Lee todos los deportes y todos los alumnos y los guarda en los diccionarios
	while (palabra != FIN){
		if (std::any_of(palabra.begin(), palabra.end(), ::islower)) {
			if (alumnos[palabra].first) {//si el alumno ya esta apuntado a un deporte entonces lo eliminamos de ese deporte
				if (alumnos[palabra].second != deporteAct && alumnos[palabra].second != "") {
					deportes[alumnos[palabra].second]--;// estamos al alumno de ese deporte
					alumnos[palabra].second = "";
				}
			}
			else {// si no pertenece a ese deporte se añade el alumno a los alumnos apuntados y se actualiza el nr de alumnos del deporte
				alumnos[palabra].first = true;
				alumnos[palabra].second = deporteAct;
				deportes[deporteAct]++;
			}
		}
		else {//si es deporte
			deportes[palabra] = 0;
			deporteAct = palabra;
		}
		cin >> palabra;
	}
	vector<pair<string, int>> salida;
	for (auto & it : deportes) {
		pair<string, int> aux(it.first,it.second);
		salida.push_back(aux);
	}

	sort(salida.begin(), salida.end(), miOperador);

	for (auto & it : salida) {
		cout << it.first << " " << it.second << endl;
	}

	cout << "***" << endl;
}


int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	string palabra;
	while (cin >> palabra)	resuelveCaso(palabra);
	
	


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


