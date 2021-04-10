#include"ColeccionEspecialidades.h"
#include<sstream>

ColeccionEspecialidades::ColeccionEspecialidades() {
	tam = cantEspecialidades;
	cant = 0;
	especialidades = new Especialidad * [cantEspecialidades];
	for (int i = 0; i < tam; i++) {
		especialidades[i] = NULL;
	}
}

int ColeccionEspecialidades::getCant() {
	return cant;
	}

int ColeccionEspecialidades::getTam() {
	return tam;
}

void ColeccionEspecialidades::insertarEspecialidad(Especialidad* e) {
	for (int i = 0; i < tam; i++){
		if (especialidades[i] == NULL) {
			especialidades[i] = e;
			cant++;
			break;
		}
	}
}

Especialidad* ColeccionEspecialidades::getEspecialidad(int n) {
	return especialidades[n];
}

string ColeccionEspecialidades::toString() {
	stringstream s;
	s << "ESPECIALIDADES REGISTRADAS EN EL HOSPITAL ESPERANZA" << endl;
	s << endl;
	for (int i = 0; i < tam; i++){
		if (especialidades[i] != NULL || especialidades[i] != nullptr) {
			s << "Especialidad: " << especialidades[i]->getNombre() << endl;
		}
	}
	return s.str();
}

void ColeccionEspecialidades::eliminarEspecialidad(int i) {
	especialidades[i] = NULL;
}

ColeccionEspecialidades::~ColeccionEspecialidades() {
	for (int i = 0; i < tam; i++){
		delete especialidades[i];
	}
	delete[] especialidades;
}

bool ColeccionEspecialidades::validarIguales(string cadena) {
	for (int i = 0; i < cant; i++){
		if (especialidades[i]->getNombre() == cadena) {
			return true;
		}
	}
	return false;
}