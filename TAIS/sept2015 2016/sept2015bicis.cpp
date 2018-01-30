#include <iostream>
#include <string>
#include <fstream>
#include "GrafoValorado.h"
#include "IndexPQ.h"
using namespace std;



class Puentes{
private:

	const int _INFINITY = 100001;

	GrafoValorado<int> _g;

	vector<bool> _marked;
	vector<bool> _markedDFS;
	IndexPQ<int> _pq = IndexPQ <int>(0);
	vector <Arista<int>> _edgeTo;
	vector<int> _distTo;

	// Add v to tree; update data structures.
	void _visit(const int & v) {
		_marked[v] = true;
		for (Arista<int> e : _g.adj(v)) {
			int w = e.otro(v);
			if (_marked[w]) continue;
			if (e.valor() < _distTo[w]) {
				_edgeTo[w] = e;
				_distTo[w] = e.valor();
				_pq.update(w, _distTo[w]);
			}
		}
	}

	void _dfs(const int & v, int & sol) {
		_markedDFS[v] = true;
		for (Arista<int> w : _g.adj(v)) {
			int v1 = w.uno();
			int v2 = w.otro(v1);
			if (!_markedDFS[v2]) {
				sol++;
				_dfs(v2,sol);
			}
		}
	}


public:

	Puentes(const GrafoValorado<int> & g) : _g(g){
		_marked = vector<bool>(_g.V(),false);
		_pq = IndexPQ <int>(_g.V());
		_edgeTo = vector<Arista<int>>(_g.V());
		_distTo = vector<int>(_g.V(), _INFINITY);
		_markedDFS = _marked;
	}

	int caminoMin() {
		int sol = 0;

		_distTo[0] = 0;
		_pq.push(0,0);

		while (!_pq.empty()){
			int aux = _pq.top().elem;
			_pq.pop();
			_visit(aux);
		}

		for (int i = 0; i < _g.V(); i++) {
			sol += _distTo[i];
		}

		return sol;
	}

	bool esPosible() {
		bool sol = true;
		int aux = 0;
		_dfs(0, aux);
		if (aux != _g.V()-1) {
			sol = false;
		}
		return sol;
	}

};


void resuelveCaso(const int & nrIslas) {

	GrafoValorado<int> g = GrafoValorado<int>(nrIslas);
	int nrPuentes;
	int v1, v2, valor;
	Arista<int> a;

	cin >> nrPuentes;

	for (int i = 0; i < nrPuentes; i++) {
		cin >> v1 >> v2 >> valor;
		a = Arista<int>(v1-1,v2-1,valor);
		g.ponArista(a);
	}
	Puentes puentes = Puentes(g);


	if (puentes.esPosible()) {
		cout << puentes.caminoMin() << endl;
	}
	else
		cout << "No hay puentes suficientes" << endl;

}


int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int nrIslas;

	while (cin>>nrIslas) {
		resuelveCaso(nrIslas);
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
