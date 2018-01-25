#include <iostream>
#include <string>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;


class Notificacion {
private:
	
	long long int _id;
	int _periodo;
	int _periodoOriginal;

public:

	Notificacion(long long int id, int periodo, int periodoOriginal):_id(id), _periodo(periodo),_periodoOriginal(periodoOriginal){}
	Notificacion() :_id(-1), _periodo(-1), _periodoOriginal(-1) {}

	bool operator< (const Notificacion & n ) const {
		bool sol = false;
		if (_periodo < n.getPeriodo()) {
			sol = true;
		}
		else if (_periodo == n.getPeriodo()) {
			if (_id < n.getId()) {
				sol = true;
			}
		}
		return sol;
	}

	long long int getId() const {
		return _id;
	}

	int getPeriodo() const {
		return _periodo;
	}

	int getPeriodoOriginal() const {
		return _periodoOriginal;
	}

	void setPeriodo(const int & periodo) {
		_periodo = periodo;
	}

};

void resuelve(PriorityQueue<Notificacion> & pq, const int & k) {
	int i = 0;

	while (i<k){
		Notificacion n = pq.top();
		pq.pop();

		cout << n.getId() << endl;

		//Calculo el nuevo tiempo y lo meto en la cola otra vez
		int aux = n.getPeriodo() + n.getPeriodoOriginal();
		n.setPeriodo(aux);
		pq.push(n);

		i++;
	}
}

void resuelveCaso(const int & nrUsuarios) {
	long long int id;
	int periodo;
	int k;
	Notificacion n;
	PriorityQueue<Notificacion> pq = PriorityQueue<Notificacion>(nrUsuarios);
	
	for (int i = 0; i < nrUsuarios; i++) {
		cin >> id >> periodo;
		n = Notificacion(id,periodo,periodo);
		pq.push(n);
	}
	cin >> k;
	resuelve(pq,k);
	cout << "----" << endl;
}

int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int nrUsuarios;
	cin >> nrUsuarios;
	while (nrUsuarios != 0) {
		resuelveCaso(nrUsuarios);
		cin >> nrUsuarios;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
