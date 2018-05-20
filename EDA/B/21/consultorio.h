#ifndef consultorio_h
#define consultorio_h
#include <string>
#include <unordered_map>
#include <queue>
#include "fecha_h.h"
#include <map>
using namespace std;

using medico = string;
using paciente = string;

class consultorio {

private:
	/*struct tComp {
		bool operator()(const pair<paciente, fecha> & a, const pair<paciente, fecha> & b) {
			size_t diaA = a.second.getDia();
			size_t diaB = b.second.getDia();
			if (diaA > diaB)
				return true;
			else if (diaA < diaB)
				return false;
			else {
				size_t horaA = a.second.getHora();
				size_t horaB = b.second.getHora();
				if (horaA > horaB)
					return true;
				else if (horaA < horaB)
					return false;
				else {
					size_t minutoA = a.second.getMinuto();
					size_t minutoB = b.second.getMinuto();
					if (minutoA > minutoB)
						return true;
					else if (minutoA < minutoB)
						return false;
					else {
						if (a.first > b.first)
							return true;
						else if (a.first < b.first)
							return false;
						else
							return true;
					}
				}
			}
		}
	};*/
	unordered_map< medico, map<fecha,paciente>> cons;
	//unordered_map< medico, priority_queue<pair<paciente, fecha>, vector<pair<paciente, fecha>>, tComp> > cons;

public:
	void altaMedico(medico const& m) {
		auto it = cons.find(m);
		if (it == cons.end())
			cons[m];
	}
	void pedirConsulta(paciente const& p, medico const& m, const fecha & f) {
		auto it = cons.find(m);
		if (it == cons.end())
			throw std::domain_error("Medico no existente");
		else {
			map<fecha, paciente> & citas = cons[m];
			if (!citas[f].empty()) {
				throw std::domain_error("Fecha ocupada");
			}
			else {
				citas[f] = p;
			}
		}
	}
	vector<pair<paciente, fecha>> listaPacientes(const medico & m, const int & d) const {
		vector<pair<paciente, fecha>> lista;
		auto it = cons.find(m);
		if (it == cons.end()) {
			throw std::domain_error("Medico no existente");
		}
		else {
			map<fecha, paciente> citas = it->second;
			auto itCitas = citas.begin();
			auto itCitasEnd = citas.end();
			bool fin = false;
			while (itCitas != itCitasEnd && !fin){
				fecha aux = itCitas->first;
				if (aux.getDia() == d) {
					lista.push_back(pair<paciente,fecha>(itCitas->second,aux));
				}
				else {
					if (aux.getDia() > d) {
						fin = true;
					}
				}
				itCitas++;
			}
		}

		return lista;
	}
	paciente const& siguientePaciente(medico const& m) const {
		auto it = cons.find(m);
		if (it == cons.end())
			throw std::domain_error("Medico no existente");
		else if (it->second.empty())
			throw std::domain_error("No hay pacientes");
		else {
			return it->second.begin()->second;
		}	
	}
	void atenderConsulta(medico const& m) {
		auto it = cons.find(m);
		if (it == cons.end())
			throw std::domain_error("Medico no existente");
		else if (it->second.empty())
			throw std::domain_error("No hay pacientes");
		else {
			map<fecha, paciente> & citas = it->second;
			citas.erase(citas.begin());
		}
	}
	/*
	void altaMedico(medico const& m) {
		auto it = cons.find(m);
		if (it == cons.end()) 
			cons[m] = priority_queue<pair<paciente, fecha>, vector<pair<paciente, fecha>>, tComp>();
	}

	void pedirConsulta(paciente const& p, medico const& m, const fecha & f) {
		auto it = cons.find(m);
		if (it == cons.end())
			throw std::domain_error("Medico no existente");
		else {//El medico existe
			if (it->second.empty())
				cons[m].push(pair<paciente, fecha>(p, f));
			else {
				priority_queue<pair<paciente, fecha>, vector<pair<paciente, fecha>>, tComp> pq = it->second;
				bool disponible = true;
				size_t dia = f.getDia();
				while (!pq.empty() && pq.top().second.getDia() < dia) {// avanzo hasta el dia en el que me han pedido la cita
					pq.pop();
				}
				while (!pq.empty() && pq.top().second.getDia() == dia && disponible) { // mientras este en el mismo dia
					if (pq.top().second == f) {
						disponible = false;
					}
					pq.pop();
				}
				if(disponible)
					cons[m].push(pair<paciente, fecha>(p, f));
				else
					throw std::domain_error("Fecha ocupada");
			}
		}
	}

	vector<pair<paciente, fecha>> listaPacientes(const medico & m, const int & d) const {
		vector<pair<paciente, fecha>> lista;
		priority_queue<pair<paciente, fecha>, vector<pair<paciente, fecha>>, tComp> pq;
		auto it = cons.find(m);
		if (it == cons.end())
			throw std::domain_error("Medico no existente");
		else {
			pq = it->second; // saco la cola de pacientes de ese medico
			if (!pq.empty()) {
				auto elem = pq.top();//la consulta mas antigua
				int diaAct = elem.second.getDia(); // el dia mas antiguo
				if (diaAct <= d) { // si la fecha esta en la cola
					while (!pq.empty() && diaAct < d) {// mientras que la fecha de la cola sea mayor que la mia
						pq.pop();
						if (!pq.empty()) {
							elem = pq.top();
							diaAct = elem.second.getDia();
						}
					}
					while (!pq.empty() && diaAct == d) {
						lista.push_back(elem);
						pq.pop();
						if (!pq.empty()) {
							elem = pq.top();
							diaAct = elem.second.getDia();
						}
					}
				}
			}
		}
		return lista;
	}
	
	paciente const& siguientePaciente(medico const& m) const {
		auto it = cons.find(m);
		if (it == cons.end())
			throw std::domain_error("Medico no existente");
		else if (it->second.empty())
			throw std::domain_error("No hay pacientes");
		else
			return it->second.top().first;
	}

	void atenderConsulta(medico const& m) {
		auto it = cons.find(m);
		if (it == cons.end())
			throw std::domain_error("Medico no existente");
		else if (it->second.empty())
			throw std::domain_error("No hay pacientes");
		else
			it->second.pop();
	}
	*/

};

#endif
