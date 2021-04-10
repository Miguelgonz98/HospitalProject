#ifndef COLECCIONDOCTORES_H
#define COLECCIONDOCTORES_H
#include"Doctor.h"
#include"ColeccionEspecialidades.h"
#include<string>
using namespace std;
int const cantDoctores = 20;

class ColeccionDoctores {
private:
	Doctor** doctores;
	int tam;
	int cant;
public:
	ColeccionDoctores();
	int getCant();
	int getTam();
	void insertarDoctor(Doctor*);
	string toString();
	bool eliminarDoctor(int);
	Doctor* getDoctor(int);
	Especialidad* especialiti(string, ColeccionEspecialidades*);
	~ColeccionDoctores();
	bool validarDoctores(int);
	string toStringEspe(int);
	int getDocPos(int);
};
#endif // !COLECCIONDOCTORES_H

