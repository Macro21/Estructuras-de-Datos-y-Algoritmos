#ifndef PELICULA_H_
#define PELICULA_H_

#include "Horas.h"
#include <string>
using namespace std;



class Pelicula {
	//friend ostream& operator<< (ostream &o, const Horas & h);

private:
	Horas _inicio;
	Horas _duracion;
	Horas _fin;
	string _titulo;


public:

	Pelicula();
	Pelicula(Horas _horaComienzo, Horas _duracion, string _titulo);
	Pelicula(const Pelicula& pelicula);
	Horas calcularFin();
	Horas getFin() const;
	string getTitulo() const;
	bool operator<(const Pelicula& peli) const;
	bool operator==(const Pelicula& peli) const;

};

#endif /* PELICULA_H_ */


