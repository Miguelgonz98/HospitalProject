#include"Pabellon.h"

Pabellon::Pabellon(char n, char g) : nombre(n), genero(g){
	c = new ColeccionCamas();
}

void Pabellon::setNombre(char nombre) {
	this->nombre = nombre;
}

char Pabellon::getNombre() {
	return nombre;
}

void Pabellon::setGenero(char genero) {
	this->genero = genero;
}

char Pabellon::getGenero() {
	return genero;
}

void Pabellon::conexPabCam() {
	c->insertarCama(getNombre());
}

ColeccionCamas* Pabellon::getCol() {
	return c;
}