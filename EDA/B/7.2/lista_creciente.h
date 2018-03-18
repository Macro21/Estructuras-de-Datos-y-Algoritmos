#include <iostream>
#include "list_eda.h"
#include "queue_eda.h"
#include "Horas.h"
using namespace std;

template <class T>

class ListaCreciente : public queue<T> {

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

	void listaCreciente() {

		if (this->nelems > 1) {
			Nodo* aux = this->prim;
			Nodo* ant = this->prim;
			this->prim = this->prim->sig;

			while (this->prim != NULL) {
				if (this->prim->elem < ant->elem) { //actual menor que el anterior
					if (this->prim == this->ult)//si tocamos el ultimo nodo, hay que actualizar ult
						this->ult = ant;
					ant->sig = this->prim->sig; //guardo el siguiente
					delete this->prim; //borro el actual
					this->prim = ant; //actualizo el actual
					this->nelems--; //actualizo el nr de elementos
				}
				else { //se actualizan las variables para la siguiente iteracion
					ant = this->prim;
					this->prim = ant->sig;		
				}
			}
			this->prim = aux; //dejamos coherente prim
		}
	}
};