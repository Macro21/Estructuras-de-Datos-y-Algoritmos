#ifndef HORAS_H_
#define HORAS_H_

class Horas{
	// Horas representadas como horas,minutos,segundos

private:
	int horas;
	int minutos;
	int segundos;

	bool horaCorrecta() const;

public:

	Horas();
	Horas(int horas, int minutos, int segundos);
	Horas(const Horas& date);
	bool operator<(const Horas & hora1) const;
	bool operator==(const Horas & h) const;
	int getHoras() const;
	int getMinutos() const;
	int getSegundos() const;

};

#endif


