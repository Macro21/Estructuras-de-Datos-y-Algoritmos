#include <iostream>
#include "list_eda.h"
#include "queue_eda.h"
#include "Horas.h"
using namespace std;

template <class T>

class BorrarPosPares : public queue<T> {

	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí

public:

	void print(std::ostream & o = std::cout) const {
		Nodo * aux =this->prim;

		while (aux != NULL) {

			Horas h = aux->elem;

			int horas = h.getHoras();
			int minutos = h.getMinutos();
			int segundos = h.getSegundos();

			if (horas <= 9) 
				o << "0" << horas << ":";
			else
				o << horas << ":";
			if (minutos <= 9)
				o << "0" << minutos << ":";
			else
				o << minutos << ":";
			if (segundos <= 9) 
				o << "0" << segundos;
			else
				o << segundos;
			o <<" ";
			aux = aux->sig;
		}
		if(this->prim != NULL)
			o << endl; // Para no poner el espacio en blanco al final
	}

	void borraPosPares() {

		if (this->nelems > 1) {
			Nodo* aux = this->prim;
			Nodo* ant = this->prim;
			this->prim = this->prim->sig;
			ant->sig = NULL;
			int i = 1;
			while (i<=this->nelems) {
				if (i%2 == 0) {//si la pos es par, borro
					ant->sig = this->prim->sig;
					ant = ant->sig;
					if (ant != NULL) {
						delete this->prim;
						this->prim = ant->sig;
						this->ult = ant;
						ant->sig = NULL;
					}
				}
				i++;
			}
			if (this->nelems % 2 == 0) 
				this->nelems = this->nelems / 2;
			else
				this->nelems = (this->nelems / 2) + 1;
			this->prim = aux;
		}
	}
};