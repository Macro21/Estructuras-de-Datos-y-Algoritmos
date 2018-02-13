#include <iostream>
#include <fstream>
using namespace std;

// Nombre del alumno: Andrei Ionut Vaduva
// Usuario del Juez: E60

struct tSol{
	bool ok = true;
	int suma = 0;
};

//de clase
tSol estaBalanceado(){
	int pi, di, pd, dd;
	tSol solIzq;
	tSol solDer;
	tSol sol;

	cin >> pi >> di >> pd >> dd;
	solIzq.suma = pi;
	solDer.suma = pd;
	if (pi != 0 && pd != 0){//Caso base, no hay mas submoviles
		sol.suma = pi + pd;
		sol.ok = (pi * di == pd * dd);
	}
	else if (pi ==0 && pd == 0){ //Si hay submoviles a ambos lados
		solIzq = estaBalanceado();
		solDer = estaBalanceado();
	}
	else if(pi == 0) {//Solo hay un submovil izquierdo
		solIzq = estaBalanceado();
	}
	else{ //Solo hay un submovil derecho
		solDer = estaBalanceado();
	}
	if (solIzq.ok && solDer.ok && (solIzq.suma*di == solDer.suma*dd)){//Comprobamos el equilibrio
		sol.ok = true;
		sol.suma = solIzq.suma + solDer.suma;
	}
	else{
		sol.ok = false;
	}

	return sol;
}

int main(){

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	tSol sol;
	int casos;
	cin >> casos;
	for (int i = 0; i < casos;i++){
		sol = estaBalanceado();
		if (sol.ok)
			cout << "SI" << endl;
		else{
			cout << "NO" << endl;
		}
	}
	
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}