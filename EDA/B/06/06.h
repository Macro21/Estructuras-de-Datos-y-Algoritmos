#include <iostream>
#include "queue_eda.h"
using namespace std;

template <class T>

class ListaDuplica : public queue<T> {

	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí

public:

	void print(std::ostream & o = std::cout) const {
		Nodo * aux = this->prim;

		if (aux != NULL) {
			while (aux->sig != NULL) {
				o << aux->elem << " ";
				aux = aux->sig;
			}
			o << aux->elem << endl; // Para no poner el espacio en blanco al final
		}
		else {
			o << endl;
		}
	}

	// Duplicar los nodos de una lista enlazada simple

	void duplica() {
		if (!this->empty()) {
			Nodo* ant = this->prim; //Nodo anterior
			Nodo* act = this->prim->sig; //Nodo actual
			while (ant->sig != NULL) {
				Nodo* aux = new Nodo(ant->elem); //Creamos un nodo con un mismo valor que el anterior
				ant->sig = aux;//hacemos que el anterior apunte al nodo creado
				aux->sig = act;//hacemos que el nodo creado apunte al nodo "actual" que hemos guardado antes
				if (ant->sig->sig != NULL) { // avanzo la lista para el siguiente nodo
					ant = ant->sig;
					ant = ant->sig;
				}
				act = act->sig;
			}
			ant->sig = new Nodo(ant->elem);//para el ultimo nodo o si hay un solo nodo en la lista
			this->ult = ant->sig;
			this->nelems = this->nelems * 2;
		}
		
	}

};