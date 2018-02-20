#ifndef POLINOMIO_H_
#define POLINOMIO_H_

#include <vector>
#include <math.h>
using namespace std;

class Polinomio {

private:
	struct Par {
		int coeficiente = -1;
		int exponente = 10;
	};
	vector<Par> polinomio;

	void _insertaParOrdenadamente(const Par & p) {
		
		if (polinomio.size() == 0) {
			polinomio.push_back(p);
		}
		else if (polinomio.size() == 1) {
			if (polinomio[0].exponente <= p.exponente) {
				polinomio.push_back(p);
			}
			else {
				polinomio.push_back(polinomio[0]);
				polinomio[0] = p;
			}
		}
		else {
			/*
				Este else se encarga de insertar al final el nuevo monomio (p) y despues a colocarlo en su sitio desplazando los valores hasta la posicion
				que le corresponde.
			*/
			polinomio.push_back(p);
			int i = polinomio.size() - 1;
			bool salir = false;
			while (i > 0 && !salir) {
				Par aux = polinomio[i];
				if (aux.exponente < polinomio[i - 1].exponente) {
					polinomio[i] = polinomio[i - 1];
					polinomio[i-1] = aux;
				}
				else {
					salir = true;
				}
				i--;
			}
		}
	}

	long long int _eval(const int & x) {
		long long int aux = 0;
		for (int i = 0; i < polinomio.size(); i++) {
			aux += polinomio[i].coeficiente*pow(x, polinomio[i].exponente);
		}
		return aux;
	}



public:

	Polinomio(){
		polinomio = vector<Par>();
	}

	void insertarMonomio(const int & coeficiente, const int & exponente) {
		Par p;
		p.coeficiente = coeficiente;
		p.exponente = exponente;
		_insertaParOrdenadamente(p);
	}

	long long int evaluacionX(const int & x) {
		return _eval(x);
	}

};


#endif // !POLINOMIO_H_
