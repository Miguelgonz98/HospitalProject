#include"Paciente.h"

Paciente::Paciente(Doctor* doc, Cama* cam ,string ced, string nom, string dir, string pat, string cir, char pri, char gen) : cedula(ced), nombre(nom), direccion(dir), patologia(pat), tipoCirugia(cir), prioridad(pri), genero(gen), docPac(doc), camPac(cam) {
	estado = false;  

}

void Paciente::setCedula(string cedula) {
	this->cedula = cedula;
}

string Paciente::getCedula() {
	return cedula;
}

void Paciente::setNombre(string nombre) {
	this->nombre = nombre;
}

string Paciente::getNombre() {
	return nombre;
}

void Paciente::setDireccion(string direccion) {
	this->direccion = direccion;
}

string Paciente::getDireccion() {
	return direccion;
}

void Paciente::setPatologia(string patologia) {
	this->patologia = patologia;
}

string Paciente::getPatologia() {
	return patologia;
}

void Paciente::setTipoCirugia(string tipoCirugia) {
	this->tipoCirugia = tipoCirugia;
}

string Paciente::getTipoCirugia() {
	return tipoCirugia;
}

void Paciente::setPrioridad(char prioridad) {
	this->prioridad = prioridad;
}

char Paciente::getPrioridad() {
	return prioridad;
}

void Paciente::setGenero(char genero) {
	this->genero = genero;
}

char Paciente::getGenero() {
	return genero;
}

void Paciente::setCamPac(Cama* camPac) {
	this->camPac = camPac;
	estado = false;
}

void Paciente::setDocPac(Doctor* docPac) {
	this->docPac = docPac;
}

Cama* Paciente::getCamPac() {
	return camPac;
}

Doctor* Paciente::getDocPac() {
	return docPac;
}

void Paciente::deAlta() {
	estado = true;
}