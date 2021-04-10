#include"Doctor.h"

Doctor::Doctor(string s, int n,Especialidad* f) : nombre(s), codigo(n), e(f) {

}

void Doctor::setNombre(string nombre) {
	this->nombre = nombre;
}

string Doctor::getNombre() {
	return this-> nombre;
}

void Doctor::setCodigo(int codigo) {
	this->codigo = codigo;
}

int Doctor::getCodigo() {
	return this->codigo;
}

void Doctor::setEspecialidad(Especialidad* e) {
	this->e = e;
}

Especialidad* Doctor::getEspecialidad() {

	return this->e;
}

