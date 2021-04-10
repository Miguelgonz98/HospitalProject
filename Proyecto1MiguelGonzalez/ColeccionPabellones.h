#ifndef COLECCIONPABELLONES_H
#define COLECCIONPABELLOBES_H
#include"Pabellon.h"
#include<string>
using namespace std;
int const cantPabellones = 10;

class ColeccionPabellones {
private:
	Pabellon** pabellones;
	int tam;
	int cant;
public:
	ColeccionPabellones();
	int getCant();
	int getTam();
	void insertarPabellon(Pabellon*);
	string toString();
	void eliminarPabellon(int);
	~ColeccionPabellones();
	bool validarIguales(char, char);
	Pabellon* getPabellon(int);
	string toStringPabCam();
	void anadirCama(int);
	void val(char);
	bool borrarCam(string);
	Cama* camariti(string);
};
#endif // !COLECCIONPABELLONES_H

