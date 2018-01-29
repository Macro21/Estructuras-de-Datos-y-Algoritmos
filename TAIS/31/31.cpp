#include <iostream>
#include <string>
#include <fstream>
#include "Matriz.h"
using namespace std;



int maxSubCadena(const string & p1, const string & p2) {
	int max = 0;
	Matriz<int> m = Matriz<int>(p1.length(), p2.length(),0);
	
	for (int i = p1.length()-1; i >= 0; i--) { // matriz al reves

		for (int j = p2.length()-1; j >= 0; j--){
			int max;
			if (p1[i] == p2[j]) {//si coincide sumo abajo derecha + 1
				if (i+1>=p1.length() || j+1>=p2.length()) {//si existe abajo derecha es que es 0 + 1 = 1
					max = 1;
				}
				else {
					max = m[i + 1][j + 1] + 1;
				}
				
			}
			else { // si no coincide sumar max entre derecha y abajo
				
				if (j+1 >= p2.length() && i+1 < p1.length()) {
					max = m[i+1][j];
				}
				else if (i + 1 >= p1.length() && j + 1 < p2.length()) {
					max = m[i][j + 1];
				}
				else if (i+1 >= p1.length() && j+1 >= p2.length()) {
					max = 0;
				}
				else if (m[i][j+1] > m[i+1][j]) { // el de la derecha es mayor
					max = m[i][j + 1];
				}
				else{//el de abajo es mayor
					max = m[i+1][j];
				}
			}
			m[i][j] = max;
		}
	}

	/*for (int i = 0; i < p1.length(); i++) {
		for (int j = 0; j < p2.length(); j++) {
			cout << m[i][j];
		}
		cout << endl;

	}
	*/

	return m[0][0];
}



int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	string linea;

	string p1, p2;
	while (getline(cin,linea)) {
		p1 = linea.substr(0, linea.find(" "));
		int h = linea.length();
		int y = p1.length();
		if (h == y) {
			cout << 0 << endl;
		}

		else {
			int max = 0;
			int act = 0;
			int indi1 = 0;
			int indi2 = 0;
			p2 = linea.substr(linea.find(" "), linea.length());
			cout << maxSubCadena(p1, p2) << endl;
		}
	}
	
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
