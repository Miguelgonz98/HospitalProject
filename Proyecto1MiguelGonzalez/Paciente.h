#ifndef PACIENTE_H
#define PACIENTE_H
#include"Cama.h"
#include"Doctor.h"
#include<string>
using namespace std;

class Paciente {
private:
	Doctor* docPac;
	string cedula;
	string nombre;
	string direccion;
	string patologia;
	string tipoCirugia;
	bool estado;
	char prioridad;
	char genero;
	Cama* camPac;
public:
	Paciente(Doctor* = NULL, Cama* = NULL,string =" ", string =" ", string = " ", string = " ", string = " ", char =' ', char=' ');
	void setCedula(string);
	string getCedula();
	void setNombre(string);
	string getNombre();
	void setDireccion(string);
	string getDireccion();
	void setPatologia(string);
	string getPatologia();
	void setTipoCirugia(string);
	string getTipoCirugia();
	void setPrioridad(char);
	char getPrioridad();
	void setGenero(char);
	char getGenero();
	void setCamPac(Cama*);
	void setDocPac(Doctor*);
	Cama* getCamPac();
	Doctor* getDocPac();
	void deAlta();
};
#endif // !PACIENTE_H
