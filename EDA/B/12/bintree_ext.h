#include <iostream>
#include "bintree_eda.h"

using namespace std;

template <class T>
class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	void frontera(vector<int> & sol) const {
		return frontera(this->raiz, sol);
	}


private:

	static void frontera(Link raiz, vector<int> & sol) {

		if (raiz == nullptr) {
			return;
		}
		else if (raiz->left == nullptr && raiz->right == nullptr) {
			sol.push_back(raiz->elem);
		}
		else {
			frontera(raiz->left, sol);
			frontera(raiz->right, sol);
		}
	}

/*
	static Info calcularInfoArbol(Link raiz) {
		//en datos guardo la suma del lado izquierdo y del lado derecho
		Info datos;
		Info datosIzq;
		Info datosDer;
		
		if (raiz == nullptr) {
			datos = Info(0, 0, 0);
		}

		else if (raiz->left == nullptr && raiz->right == nullptr) {
			datos = Info(1,1,1);
		}

		else {
			datosIzq = calcularInfoArbol(raiz->left);
			datosDer = calcularInfoArbol(raiz->right);

			int altIzq = datosIzq.getAltura();
			int nNodosIzq = datosIzq.getNrNodos();
			int nHojasIzq = datosIzq.getNrHojas();

			int altDer = datosDer.getAltura();
			int nNodosDer = datosDer.getNrNodos();
			int nHojasDer = datosDer.getNrHojas();

			if (altIzq > altDer) {
				datos = Info(altIzq + 1, nNodosDer + nNodosIzq + 1, nHojasDer + nHojasIzq);
			}
			else {
				datos = Info(altDer + 1, nNodosDer + nNodosIzq + 1, nHojasDer + nHojasIzq);
			}
		}
		return datos;
	}*/
};