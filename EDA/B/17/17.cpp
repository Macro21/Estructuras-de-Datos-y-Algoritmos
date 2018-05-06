#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;

//Andrei Ionut Vaduva E60

void resuelveCaso() {
	
	long long int tamDatos;
	int elem;
	unordered_map<int, long long int> map;
	cin >> tamDatos; 
	
	long long int iniUltSeg = 1;
	long long int maxLong = 0;
	long long int ini = 1;
	long long int maxFinal = 0;

	for(long long int i = 1; i <= tamDatos; i++) {
		cin >> elem;
		
		if (map[elem] <= iniUltSeg) {
			if ((ini != 0 && map[elem] != iniUltSeg) && maxLong < i - iniUltSeg + 1) {
				ini = iniUltSeg;
				maxLong = i - iniUltSeg + 1;
				if (maxLong > maxFinal) {
					maxFinal = maxLong;
				}
			}
			else {
				iniUltSeg = map[elem] + 1;
				if (maxLong > maxFinal) {
					maxFinal = maxLong;
				}
				maxLong = i - iniUltSeg + 1;
			}
		}
		else {
			iniUltSeg = map[elem] + 1;
			if (maxLong > maxFinal) {
				maxFinal = maxLong;
			}
			maxLong = i - iniUltSeg + 1;
		
		}

		map[elem] = i;
	}

	cout << maxFinal << endl;
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


