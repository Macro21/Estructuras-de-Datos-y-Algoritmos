#include <iostream>
#include "bintree_eda.h"

using namespace std;

template <class T>
class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:
	struct tSol {
		int nrDragones = -1;
		int sol = -1;
	};
	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	int resuelve() const {
		return resuelve(this->raiz).sol;
	}

private:

	static tSol resuelve(Link raiz) {
		tSol sol;
		tSol solIzq;
		tSol solDer;
	
		if (raiz == nullptr) {
			return sol;
		}
		if (raiz->elem == 1) {//dragon 1
			solIzq = resuelve(raiz->left);
			solDer = resuelve(raiz->right);
			if (solIzq.sol >= 3 && solIzq.nrDragones <= solDer.nrDragones || solDer.sol == -1) {
				sol = solIzq;
			}
			else
				sol = solDer;
			sol.nrDragones += 1;
		}
		else if (raiz->elem != 2 && raiz->elem >= 3) {//hoja >=3
			sol.sol = raiz->elem;
			sol.nrDragones = 0;
		}
		else {//2
			solIzq = resuelve(raiz->left);
			solDer = resuelve(raiz->right);
			if (solIzq.sol >= 3 && solIzq.nrDragones <= solDer.nrDragones || solDer.sol == -1) {
				sol = solIzq;
			}
			else
				sol = solDer;
		}
		return sol;
	}
};