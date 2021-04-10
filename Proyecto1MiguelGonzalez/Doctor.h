#ifndef DOCTOR_H
#define DOCTOR_H
#include "Especialidad.h"
#include<string>
using namespace std;

class Doctor {
private:
	string nombre;
	int codigo;
	Especialidad* e;
public:
	Doctor(string ="_", int = 0,Especialidad* = NULL);
	void setNombre(string);
	string getNombre();
	void setCodigo(int);
	int getCodigo();
	void setEspecialidad(Especialidad*);
	Especialidad* getEspecialidad();
};
#endif // !DOCTOR_H

