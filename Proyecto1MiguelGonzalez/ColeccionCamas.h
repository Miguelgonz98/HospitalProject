#ifndef COLECCIONCAMAS_H
#define COLECCIONCAMAS_H
#include"Cama.h"
#include<string>
using namespace std;
int const cantCamas = 20;

class ColeccionCamas {
private:
	Cama** camas;
	int tam;
	int cant;
public:
	ColeccionCamas();
	int getCant();
	int getTam();
	void insertarCama(char);
	string toString();
	void eliminarCama(int);
	~ColeccionCamas();
	Cama* getCama(int);
};
#endif // !COLECCIONCAMAS_H