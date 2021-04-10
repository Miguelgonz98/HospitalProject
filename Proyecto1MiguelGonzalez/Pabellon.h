#ifndef PABELLON_H
#define PABELLON_H
#include"ColeccionCamas.h"
#include<string>
using namespace std;

class Pabellon {
private:
	char nombre;
	char genero;
	ColeccionCamas* c;
public:
	Pabellon(char =' ',char = ' ');
	void setNombre(char);
	char getNombre();
	void setGenero(char);
	char getGenero();
	void conexPabCam();
	ColeccionCamas* getCol();
};
#endif // !PABELLON_H