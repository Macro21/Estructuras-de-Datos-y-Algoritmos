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


void resuelveCaso(const int & casos) {
	
	map<string, vector<int>> referencias;
	
	stringstream ss;
	string clave;
	string linea;

	for (int i = 1; i <= casos; i++) {
		getline(cin, linea);
		ss.clear();
		ss.str(linea);	
		while (ss >> clave) {
			if (clave.length() > 2) {
				transform(clave.begin(), clave.end(), clave.begin(), ::tolower);
				vector<int> & v = referencias[clave];
				/*if (find(v.begin(), v.end(), i) == v.end()) { //si la linea no esta ya en el array, lo añado
					v.push_back(i);
				}*/
				int ultimo = v.size() - 1;
				if (v.empty() || v[ultimo] != i) {
					v.push_back(i);
				}
			}
		}
	}

	if (casos != 0) {
		auto it = referencias.cbegin();
		auto itEnd = referencias.cend();
		while (it != itEnd) {
			cout << it->first << " ";
			auto itArray = it->second.cbegin();
			auto itArrayEnd = it->second.cend();
			while (itArray != itArrayEnd) {
				cout << *itArray << " ";
				itArray++;
			}
			cout << endl;
			it++;
		}
		cout << "----" << endl;
	}
}


int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int casos;

	while(cin >> casos){
		cin.ignore();
		resuelveCaso(casos);
	}


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


