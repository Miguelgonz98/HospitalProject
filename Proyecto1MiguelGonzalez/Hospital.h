#ifndef HOSPITAL_H
#define HOSPITAL_H
#include"ColeccionDoctores.h"
#include"ColeccionEspecialidades.h"
#include"ColeccionPabellones.h"
#include"ColeccionPacientes.h"
#include"Interfaz.h"
#include<string>
using namespace std;

class Hospital {
private:
	ColeccionDoctores* colDoc;
	ColeccionEspecialidades* colEsp;
	ColeccionPabellones* colPab;
	ColeccionPacientes* colPac;
public:
	void menuInicio();
	void menuEspecialidad();
	void menuPabellon();
	void menuDoctor();
	void menuPaciente();
	void menuAsignaCam();
	void menuAsignaDoc();
};
#endif // !HOSPITAL_H