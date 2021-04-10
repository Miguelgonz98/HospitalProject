#include"ColeccionCamas.h"
#include<sstream>

ColeccionCamas::ColeccionCamas() {
	tam = cantCamas;
	cant = 0;
	camas = new Cama * [cantCamas];
	for (int i = 0; i < tam; i++){
		camas[i] = NULL;
	}
}

int ColeccionCamas::getCant() {
	return cant;
}

int ColeccionCamas::getTam() {
	return tam;
}

void ColeccionCamas::insertarCama(char n) {
	string str = "";
	Cama* c = new Cama();
	for (int i = 0; i < tam; i++){
		if (camas[i] == NULL) {
			camas[i] = c;
			int f = i+1;
			str = to_string(f);
			c->setCodigo(n+str);
			cant++;
			break;
		}
	}
}

string ColeccionCamas::toString() {
	stringstream s;
	for (int i = 0; i < cant; i++){
		if (camas[i] != NULL) {
			s << "Cama: " << camas[i]->getCodigo() <<" | Estado: "<< camas[i]->disponible() << endl;
		}
	}
	return s.str();
}

void ColeccionCamas::eliminarCama(int i) {
	camas[i] = NULL;
}

ColeccionCamas::~ColeccionCamas() {
	for (int i = 0; i < tam; i++){
		delete camas[i];
	}
	delete[] camas;
}

Cama* ColeccionCamas::getCama(int n) {
	return camas[n];
}