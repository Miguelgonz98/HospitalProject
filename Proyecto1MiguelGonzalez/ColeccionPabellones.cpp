#include"ColeccionPabellones.h"
#include<sstream>

ColeccionPabellones::ColeccionPabellones() {
	tam = cantPabellones;
	cant = 0;
	pabellones = new Pabellon * [cantPabellones];
	for (int i = 0; i < tam; i++) {
		pabellones[i] = NULL;
	}
}

int ColeccionPabellones::getCant() {
	return cant;
}

int ColeccionPabellones::getTam() {
	return tam;
}

void ColeccionPabellones::insertarPabellon(Pabellon* p) {
	for (int i = 0; i < tam; i++){
		if (pabellones[i] == NULL) {
			pabellones[i] = p;
			cant++;
			break;
		}
	}
}

string ColeccionPabellones::toString() {
	stringstream s;
	s << "PABELLONES REGISTRADOS EN EL HOSPITAL" << endl;
	for (int i = 0; i < cant; i++){
		s << "Pabellon " << pabellones[i]->getNombre() << " (" << pabellones[i]->getGenero() << ")" << endl;
	}
	return s.str();
}

void ColeccionPabellones::eliminarPabellon(int n) {
	pabellones[n] = NULL;
}

ColeccionPabellones::~ColeccionPabellones() {
	for (int i = 0; i < tam; i++){
		delete pabellones[i];
	}
	delete[] pabellones;
}

bool ColeccionPabellones::validarIguales(char s, char c) {
	for (int i = 0; i < cant; i++) {
		if (pabellones[i]->getNombre() == s && pabellones[i]->getGenero() == c) {
			return true;
		}
	}
	return false;
}

Pabellon* ColeccionPabellones::getPabellon(int n) {
	return pabellones[n];
}

string ColeccionPabellones::toStringPabCam() {
	stringstream s;
	for (int i = 0; i < cant; i++){
		if (pabellones[i] != NULL) {
			s << "PABELLON " << pabellones[i]->getNombre() <<" ("<< pabellones[i]->getGenero() <<") "<<":" << endl;
			s << endl;
			s << pabellones[i]->getCol()->toString();
			s << endl;
		}
	}
	s << endl;
	return s.str();
}

void ColeccionPabellones::anadirCama(int n) {
	pabellones[n]->conexPabCam();
}

void ColeccionPabellones::val(char r) {
	for (int i = 0; i < cant; i++){
		if (pabellones[i]->getNombre() == r) {
			anadirCama(i);
		}
	}
}

bool ColeccionPabellones::borrarCam(string cod) {
	for (int i = 0; i < cant; i++) {
		if (pabellones[i] != NULL) {
			for (int j = 0; j < pabellones[i]->getCol()->getCant(); j++){
				if (pabellones[i]->getCol()->getCama(j) != NULL && pabellones[i]->getCol()->getCama(j)->disponible()=="Disponible") {
					if (pabellones[i]->getCol()->getCama(j)->getCodigo() == cod) {
						pabellones[i]->getCol()->eliminarCama(j);
						return true;
					}
				}
			}
		}
	}
	return false;
}

Cama* ColeccionPabellones::camariti(string ssd) {
	for (int i = 0; i < cant ; i++) {
		if (pabellones[i] != NULL) {
			for (int j = 0; j < pabellones[i]->getCol()->getCant(); j++) {
				if (pabellones[i]->getCol()->getCama(j) != NULL) {
					if (pabellones[i]->getCol()->getCama(j)->getCodigo() == ssd) {
						return pabellones[i]->getCol()->getCama(j);
					}
				}
			}
		}
	}
	return NULL;
}