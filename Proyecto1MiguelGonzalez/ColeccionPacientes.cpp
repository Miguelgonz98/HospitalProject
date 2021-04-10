#include"ColeccionPacientes.h"
#include"ColeccionPabellones.h"
#include<sstream>

ColeccionPacientes::ColeccionPacientes() {
	tam = cantPacientes;
	cant = 0;
	pacientes = new Paciente * [cantPacientes];
	for (int i = 0; i < tam; i++){
		pacientes[i] = NULL;
	}
}

int ColeccionPacientes::getCant() {
	return cant;
}

int ColeccionPacientes::getTam() {
	return tam;
}

void ColeccionPacientes::insertarPaciente(Paciente* pac) {
	
	for (int i = 0; i < tam; i++){
		if (pacientes[i] == NULL) {
			pacientes[i] = pac;
			cant++;
			break;
			
		}
	}
}

string ColeccionPacientes::toString() {
	stringstream s;
	s << "PACIENTES REGISTRADOS EN EL HOSPITAL" << endl;
	for (int i = 0; i < cant; i++){
		if (pacientes[i] != NULL) {
			s << "Paciente: " << pacientes[i]->getNombre() << endl;
			s << "Cedula: " << pacientes[i]->getCedula() << endl;
			s << "Doctor: " << pacientes[i]->getDocPac()->getNombre() << endl;
			s << "---------------------------------------------------------------" << endl;
		}
	}
	return s.str();
}

string ColeccionPacientes::toStringEspe(string id) {
	stringstream s;
	int c = 0;
	int o=0;
	for (int i = 0; i < tam; i++){
		if (pacientes[i] != NULL || pacientes[i] != nullptr) {
			if (pacientes[i]->getCedula() == id) {
				o = i;
				c++;
			}
		}
	}
	if (c==0) {//Validar por segunda vez xd
		s << "Ese paciente no existe!!!" << endl;
	} else {
		s << "INFORME DETALLADO:" << endl;
		s << endl;
		s << "Paciente: " << pacientes[o]->getNombre() << endl;
		s << "Cedula: " << pacientes[o]->getCedula() << endl;
		s << "Direccion: " << pacientes[o]->getDireccion() << endl;
		s << "Patologia: " << pacientes[o]->getPatologia() << endl;
		s << "Tipo de cirugia: " << pacientes[o]->getTipoCirugia() << endl;
		s << "Prioridad: " << pacientes[o]->getPrioridad() << endl;
		s << "Genero: " << pacientes[o]->getGenero() << endl;
		if (pacientes[o]->getCamPac() == NULL) {
			s << "Cama: --" << endl;
		} else {
			s << "Cama: " << pacientes[o]->getCamPac()->getCodigo() << endl;
		}
		s << "Doctor: " << pacientes[o]->getDocPac()->getNombre() << endl;
		s << "---------------------------------------------------------------" << endl;
	}
	return s.str();
}

Doctor* ColeccionPacientes::doctoriti(int cod, ColeccionDoctores* c) {
	for (int i = 0; i < c->getCant(); i++) {
		if (c->getDoctor(i)->getCodigo() == cod) {
			return c->getDoctor(i);
		}
	}
	return NULL;
}

//Cama* camariti(string ssd, ColeccionPabellones* pa){
//	for (int i = 0; i < pa->getCant(); i++){
//		if (pa->getPabellon(i) != NULL) {
//			for (int j = 0; j < pa->getPabellon(i)->getCol()->getCant(); j++){
//				if (pa->getPabellon(i)->getCol()->getCama(j) != NULL) {
//					if (pa->getPabellon(i)->getCol()->getCama(j)->getCodigo()==ssd) {
//						return pa->getPabellon(i)->getCol()->getCama(j);
//					}
//				}
//			}
//		}
//	}
//	return NULL;
//}

bool ColeccionPacientes::eliminarPaciente(string cd) {
		for (int i = 0; i < cant; i++) {
			if (pacientes[i]->getCedula() == cd) {
				pacientes[i]->getCamPac()->desocupar();
				pacientes[i] = NULL;
				return true;
			}
		}
		return false;
}



ColeccionPacientes::~ColeccionPacientes() {
	for (int i = 0; i < tam; i++){
		delete pacientes[i];
	}
	delete[] pacientes;
}

bool ColeccionPacientes::validarPacientes(string cedu) {
	for (int i = 0; i < cant; i++) {
		if (pacientes[i]->getCedula() == cedu) {
			return true;
		}
	}
	return false;
}

Paciente* ColeccionPacientes::getPaciente(int p) {
	return pacientes[p];
}

int ColeccionPacientes::buscarPac(string id) {
	int c = 0;
	int o = 0;
	for (int i = 0; i < tam; i++) {
		if (pacientes[i] != NULL || pacientes[i] != nullptr) {
			if (pacientes[i]->getCedula() == id) {
				o = i;
				c++;
			}
		}
	}
	if (c == 0) {//Validar por segunda vez xd
		return -1;
	}
	return o;
}
