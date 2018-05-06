#include <iostream>
#include "bintree_eda.h"

using namespace std;

template <class T>
class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	pair<int,int> multiploMasCercano() const {
		return multiploMasCercano(this->raiz, 1);
	}


private:

	//Se puede mejorar para que quede mas bonito
	static pair<int,int> multiploMasCercano(Link raiz, int nivel) {
		pair<int, int> sol;
		pair<int, int> solIzq;
		pair<int, int> solDer;
		bool es_Primo;
	
		if (raiz == nullptr) {
			sol.first = -1;
			sol.second = -1;
		}
		else if (raiz->left == nullptr && raiz->right == nullptr) {
			es_Primo = esPrimo(raiz->elem);
			if (!es_Primo && raiz->elem % 7 == 0) {
				sol.first = raiz->elem;
				sol.second = nivel;
			}
			else {
				sol.first = -1; 
				sol.second = -1;
			}
		}
		else if (raiz->left != nullptr && raiz->right == nullptr) {
			es_Primo = esPrimo(raiz->elem);
			if (!es_Primo && raiz->elem % 7 == 0) {
				sol.first = raiz->elem;
				sol.second = nivel;
			}
			else
				if(!es_Primo)
					sol = multiploMasCercano(raiz->left, nivel + 1);
		}
		else if (raiz->left == nullptr && raiz->right != nullptr) {
			es_Primo = esPrimo(raiz->elem);
			if (!es_Primo && raiz->elem % 7 == 0){
				sol.first = raiz->elem;
				sol.second = nivel;
			}
			else
				if(!es_Primo)
					sol = multiploMasCercano(raiz->right, nivel + 1);
		}
		else {
			es_Primo = esPrimo(raiz->elem);
			if (!es_Primo ) {
				if (raiz->elem % 7 != 0) {
					solIzq = multiploMasCercano(raiz->left, nivel + 1);
					solDer = multiploMasCercano(raiz->right, nivel + 1);
						
					if (solIzq.second != -1 && solDer.second != -1 && solIzq.second <= solDer.second)
						sol = solIzq;
					else if (solIzq.second != -1 && solDer.second != -1 && solIzq.second > solDer.second)
						sol = solDer;
					else if (solIzq.second == -1 && solDer.second != -1)
						sol = solDer;
					else if (solIzq.second != -1 && solDer.second == -1)
						sol = solIzq;
					else {
						sol.first = -1;
						sol.second = -1;
					}
					
				}
				else {
					sol.first = raiz->elem;
					sol.second = nivel;
				}
			}
			else {
				sol.first = -1;
				sol.second = -1;
			}
		}
	
		return sol;
	}
	
	static bool esPrimo(const int & n) {
		bool esPrimo = true;
		int divisible = 0;

		for (int i = 1; i < n + 1; i++) {
			if (n % i == 0)
				divisible++;
		}
		if (divisible != 2)
			esPrimo = false;

		return esPrimo;
	}

};