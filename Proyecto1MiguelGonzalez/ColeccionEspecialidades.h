#ifndef COLECCIONESPECIALIDADES_H
#define COLECCIONESPECIALIDADES_H
#include"Especialidad.h"
#include<string>
using namespace std;
int const cantEspecialidades = 10;

class ColeccionEspecialidades {
private:
	Especialidad** especialidades;
	int tam;
	int cant;
public:
	ColeccionEspecialidades();
	int getCant();
	int getTam();
	void insertarEspecialidad(Especialidad*);
	Especialidad* getEspecialidad(int);
	string toString();
	void eliminarEspecialidad(int);
	~ColeccionEspecialidades();
	bool validarIguales(string);


};
#endif // !COLECCIONESPECIALIDADES_H
