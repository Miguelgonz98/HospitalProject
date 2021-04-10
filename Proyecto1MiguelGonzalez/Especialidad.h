#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
using namespace std;
#include<string>

class Especialidad {
private:
	string nombre;
public:
	Especialidad(string ="");
	void setNombre(string);
	string getNombre();
};
#endif // !ESPECIALIDAD_H