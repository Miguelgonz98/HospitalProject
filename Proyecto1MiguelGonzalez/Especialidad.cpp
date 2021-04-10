#include"Especialidad.h"

Especialidad::Especialidad(string n) : nombre(n) {

}

void Especialidad::setNombre(string nombre) {
	this->nombre = nombre;
}

string Especialidad::getNombre() {
	return nombre;
}