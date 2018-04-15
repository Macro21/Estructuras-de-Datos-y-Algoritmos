#ifndef info_h
#define info_h

#include <iostream>
using namespace std;

//Andrei Ionut Vaduva
class Info {
private:
	size_t sol;
	size_t nrExcursionistas;
public:

	Info(size_t sol = 0, size_t nrExcursionistas = 0) {
		this->sol = sol;
		this->nrExcursionistas = nrExcursionistas;
	}

	size_t getSol() const {
		return this->sol;
	}

	size_t getNrExcursionistas() const {
		return this->nrExcursionistas;
	}


	void setSol(size_t sol) {
		this->sol = sol;
	}

	void setNrExcursionistas(size_t nrExcursionistas) {
		this->nrExcursionistas = nrExcursionistas;
	}

	Info& operator+=(const Info& data) {
		this->sol += data.getSol();
		this->nrExcursionistas += data.getNrExcursionistas();
		return *this;
	}
};


#endif
