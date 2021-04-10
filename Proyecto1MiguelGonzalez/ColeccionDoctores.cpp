#include"ColeccionDoctores.h"
#include<sstream>

ColeccionDoctores::ColeccionDoctores() {
	tam = cantDoctores;
	cant = 0;
	doctores = new Doctor * [cantDoctores];
	for (int i = 0; i < tam; i++){
		doctores[i] = NULL;
	}
}

int ColeccionDoctores::getCant() {
	return cant;
}

int ColeccionDoctores::getTam() {
	return tam;
}

void ColeccionDoctores::insertarDoctor(Doctor* d) {
	
	for (int i = 0; i < tam; i++){
		if (doctores[i] == NULL) {
			doctores[i] = d;
			cant++;
			break;
		}
	}
}

string ColeccionDoctores::toString() {
	stringstream s;
	s << "DOCTORES REGISTRADOS EN EL HOSPITAL" << endl;
	for (int i = 0; i < cant; i++){
		if (doctores[i]!=NULL) {
			s << "Doctor: " << doctores[i]->getNombre() << " | Codigo: " << doctores[i]->getCodigo() << " | Especialidad: " << doctores[i]->getEspecialidad()->getNombre() << endl;
		}
	}
	return s.str();
}

string ColeccionDoctores::toStringEspe(int cod) {
	stringstream s;
	int c = 0;
	int o = 0;
	for (int i = 0; i < tam; i++) {
		if (doctores[i] != NULL || doctores[i] != nullptr) {
			if (doctores[i]->getCodigo() == cod) {
				o = i;
				c++;
			}
		}
	}
	if (c == 0) {
		s << "Ese doctor no existe!!!" << endl;
	}
	else {
		s << "INFORME DETALLADO:" << endl;
		s << endl;
		s << "Doctor: " << doctores[o]->getNombre() << endl;
		s << "Codigo: " << doctores[o]->getCodigo() << endl;
		s << "Especialidad: " << doctores[o]->getEspecialidad()->getNombre() << endl;

	}
	return s.str();
}

bool ColeccionDoctores::eliminarDoctor(int n) {
	for (int i = 0; i < cant; i++){
		if (doctores[i]->getCodigo() == n) {
			doctores[i] = NULL;
			return true;
		}
	}
	return false;
}

ColeccionDoctores::~ColeccionDoctores() {
	for (int i = 0; i < tam; i++){
		delete doctores[i];
	}
	delete[] doctores;
}

Doctor* ColeccionDoctores::getDoctor(int n) {
	return doctores[n];
}

Especialidad* ColeccionDoctores::especialiti(string r, ColeccionEspecialidades* c) {
	for (int i = 0; i < c->getCant(); i++){
		if (c->getEspecialidad(i)->getNombre() == r) {
			return c->getEspecialidad(i);
		}
	}
	return NULL;
}

bool ColeccionDoctores::validarDoctores(int codi) {
	for (int i = 0; i < cant; i++){
		if (doctores[i]->getCodigo() == codi) {
			return true;
		}
	}
	return false;
}

int ColeccionDoctores::getDocPos(int code) {
	for (int i = 0; i < cant; i++){
		if (doctores[i]->getCodigo() == code) {
			return i;
		}
	}
	return -1;
}

