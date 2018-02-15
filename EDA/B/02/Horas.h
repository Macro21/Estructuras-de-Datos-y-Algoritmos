#ifndef HORAS_H_
#define HORAS_H_

class Horas{
	// Horas representadas como horas,minutos,segundos

private:
	int horas;
	int minutos;
	int segundos;

	bool horaCorrecta() const;
	void normalizarMinutos(int & m, int & ho);

public:

	Horas();
	Horas(int horas, int minutos, int segundos);
	Horas(const Horas& date);
	bool operator<(const Horas & hora1) const;
	bool operator==(const Horas & h) const;
	Horas& operator+(const Horas & h);
	int getHoras() const;
	int getMinutos() const;
	int getSegundos() const;
	void setHoras(const int & horas);
	void setMinutos(const int & horas);
	void setSegundos(const int & horas);

};

#endif


