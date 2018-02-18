#ifndef COMPLEJO_H_
#define COMPLEJO_H_

#include <math.h>
using namespace std;

template <class T>
class Complejo {
private:
	float _real;
	float _imag;

public:
	
	Complejo() : _real(3), _imag(-3) {}
	Complejo(const T & real, const T & imag) : _real(real), _imag(imag) { }
	
	float getReal() const {
		return this->_real;
	};

	float getImag() const {
		return this->_imag;
	};

	Complejo operator+(const Complejo & c) {
		float real = 0, imag = 0;
		real = this->_real + c.getReal();
		imag = this->_imag + c.getImag();
		return Complejo(real,imag);
	};

	Complejo operator*(const Complejo & c) {
		float real = 0, imag;
		real = ((this->_real * c.getReal()) - (this->_imag * c.getImag())); // (a*c - b*d)
		imag = ((this->_real * c.getImag()) + (c.getReal()*this->_imag)); //(a*d+c*b)i
		return Complejo(real, imag);
	};

	float mod() {
		return sqrt(pow(this->_real,2) + (pow(this->_imag,2)));
	};

};

#endif // !
