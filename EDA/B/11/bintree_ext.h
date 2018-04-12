#include <iostream>
#include "bintree_eda.h"
#include "info_h.h"
using namespace std;

template <class T>
class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	/*size_t altura() const {
		return altura(this->raiz);
	}

	size_t nNodos() const {
		return nNodos(this->raiz);
	}

	size_t nHojas() const {
		return nHojas(this->raiz);
	}*/

	Info calcularInfoArbol(){
		return calcularInfoArbol(this->raiz);
	}

private:
/*
	static size_t altura(Link r) {
		if (r == nullptr) {
			return 0;
		}
		else {
			return 1 + std::max(altura(r->left), altura(r->right));
		}
	}

	static size_t nNodos(Link raiz) {
		int nrNodos = 0;
		if (raiz == nullptr) {//ha llegado a una hoja
			return 0;
		}
		else {
			nrNodos++;
			nrNodos += nNodos(raiz->left);
			nrNodos += nNodos(raiz->right);
		}
		return nrNodos;
	}

	static size_t nHojas(Link raiz) {
		int nrHojas = 0;
		if (raiz == nullptr) {
			return 0;
		}
		else {
			if (raiz->left == nullptr && raiz->right == nullptr) {
				nrHojas++;
			}
			nrHojas += nHojas(raiz->left);
			nrHojas += nHojas(raiz->right);
		}
		return nrHojas;
	}
	*/
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
	}
};