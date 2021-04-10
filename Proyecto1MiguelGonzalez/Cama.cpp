#include"Cama.h"
#include<sstream>

Cama::Cama(string c) : codigo(c) {
	estado = false;
}

void Cama::setCodigo(string codigo) {
	this->codigo = codigo;
}

string Cama::getCodigo() {
	return codigo;
}

void Cama::ocupar() {
	estado = true;
}

void Cama::desocupar() {
	estado = false;
}

string Cama::disponible() {
	string s;
	if (estado==false) {
		s = "Disponible";
	} else {
		s = "Ocupada";
	}
	return s;
}