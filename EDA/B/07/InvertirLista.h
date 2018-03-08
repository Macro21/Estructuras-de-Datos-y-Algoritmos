#include <iostream>
#include "list_eda.h"
#include "deque_eda.h"
using namespace std;

template <class T>

class ListaInvierte : public deque<T> {

	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí

public:

	void print(std::ostream & o = std::cout) const {
		Nodo * aux = this->fantasma->sig;

		while (aux != this->fantasma) {
			o << aux->elem << " ";
			aux = aux->sig;
		}
	
		o << endl; // Para no poner el espacio en blanco al final
		

	}

	void invierte() {
		
		Nodo* prim = this->fantasma->sig;
		Nodo* ult = this->fantasma->ant;
		Nodo* aux = prim->sig;

		if (this->nelems > 1) {
			//Paso 1
			//Inserto al final de la lista el primer nodo y actualizo los punteros bien
			ult->sig = prim;
			prim->sig = this->fantasma;
			prim->ant = ult;
			aux->ant = this->fantasma;

			//El bucle inserta (desde el segundo elemento hasta el elem i-1) los elementos delante del ultimo nodo original
			/*
				Ej lista: 1 2 3 4
				Paso 1: 2 3 4 1 con punteros actualizados
				Paso 2: 3 4 2 1 con punteros actualizados
				asi con todos los elems
				de forma que al final queda 4 3 2 1 al acabar el bucle con el fantasma desactualizado
			*/
			//Paso 2
			int i = this->nelems-2;
			while (i>0) {
				Nodo* aux2 = ult->sig; 
				ult->sig = aux;
				aux = ult->sig->sig;
				ult->sig->sig = aux2;
				ult->sig->ant = ult;
				ult->sig->sig->ant = ult->sig;
				i--;
			}
			//Actualiza los punteros al fantasma
			ult->ant = this->fantasma;
			Nodo* a = this->fantasma->ant;
			this->fantasma->ant = this->fantasma->sig;
			this->fantasma->sig = a;
		};
	}
};