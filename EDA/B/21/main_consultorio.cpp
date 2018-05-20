
#include <iostream>
#include <fstream>
#include "fecha_h.h"
#include <sstream>
#include "consultorio.h"

using namespace std;

string mostrarHora(const fecha & f) {
	int horas = f.getHora();
	int minutos = f.getMinuto();
	stringstream horaCompleta;
	if (horas <= 9) {
		horaCompleta << "0" << horas << ":";
	}
	else {
		horaCompleta << horas << ":";
	}
	if (minutos <= 9) {
		horaCompleta << "0" << minutos;
	}
	else {
		horaCompleta << minutos;
	}
	return horaCompleta.str();
}

bool resuelveCaso() {
   std::string orden, pac, med;
   int dia, hora, minuto;
   int n;
   std::cin >> n;

   if (!std::cin)
      return false;
   
   consultorio H;

   while (n > 0) {
      try {
		  cin >> orden;
         if (orden == "nuevoMedico") {
            std::cin >> med;
            H.altaMedico(med);
         } 
		 else if (orden == "pideConsulta") {
			 cin >> pac >> med >> dia >> hora >> minuto;
			 fecha f = fecha(dia,hora,minuto);
			 H.pedirConsulta(pac,med,f);
         }
		 else if (orden == "siguientePaciente") {
			 cin >> med;
			 string medic = H.siguientePaciente(med);
			 cout << "Siguiente paciente doctor " << med << endl;
			 cout << medic  << endl;
			 cout << "---" << endl;
         }
		 else if (orden == "atiendeConsulta") {
			 cin >> med;
			 H.atenderConsulta(med);
         }
		 else if (orden == "listaPacientes") {
			 cin >> med >> dia;
			 vector<pair<medico,fecha>> lista = H.listaPacientes(med,dia);
			 cout << "Doctor " << med << " dia " << dia << endl;
			 for (auto & it : lista) {
				 fecha f = it.second;
				 cout << it.first << " " << mostrarHora(f) << endl;
			 }
			 cout << "---" << endl;
		 }
      } 
	  catch (std::domain_error e) {
         std::cout << e.what() << '\n';
		 cout << "---" << endl;
      }
	  n--;
   }

   std::cout << "------\n";
   return true;
}

int main() {

#ifndef DOMJUDGE 
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while(resuelveCaso());
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}

