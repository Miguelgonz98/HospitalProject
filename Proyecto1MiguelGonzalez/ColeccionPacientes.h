#ifndef COLECCIONPACIENTES_H
#define COLECCIONPACIENTES_H
#include"Paciente.h"
#include"ColeccionDoctores.h"
#include<string>
using namespace std;
int const cantPacientes = 200;

class ColeccionPacientes {
private:
	Paciente** pacientes;
	int tam;
	int cant;
public:
	ColeccionPacientes();
	int getCant();
	int getTam();
	void insertarPaciente(Paciente*);
	string toString();
	Doctor* doctoriti(int, ColeccionDoctores*);
	bool eliminarPaciente(string);
	~ColeccionPacientes();
	bool validarPacientes(string);
	string toStringEspe(string);
	Paciente* getPaciente(int);
	int buscarPac(string id);
};
#endif // !COLECCIONPACIENTES_H

