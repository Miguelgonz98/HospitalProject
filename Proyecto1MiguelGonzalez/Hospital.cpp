#include"Hospital.h"

void Hospital::menuInicio() {
	colDoc = new ColeccionDoctores();
	colEsp = new ColeccionEspecialidades();
	colPab = new ColeccionPabellones();
	colPac = new ColeccionPacientes();

	int opcion;
	bool bandera = true;
	while (bandera == true){
		cleanScr();
		print("----------------------------------------------SISTEMA HOSPITAL ESPERANZA-------------------------------------------");
		print(" ");
		print("Le Damos la bienvenida al Sistema del Hospital Esperanza");
		print("----------MENU----------");
		print(" ");
		print("[1] Especialidades");
		print("[2] Pabellones y Camas");
		print("[3] Doctores");
		print("[4] Pacientes");
		print("[5] Salir");
		print(" ");
		print("Digite una Opcion:");
		opcion = leerEntero();
		switch (opcion) {
		case 1: {
			cleanScr();
			menuEspecialidad();
			break;
		};
		case 2: {
			cleanScr();
			menuPabellon();

			break;
		};
		case 3: {
			cleanScr();
			menuDoctor();
			break;
		};
		case 4: {
			cleanScr();
			menuPaciente();
			break;
		};
		case 5: {
			bandera = false;
			break;
		};
		default:print("OPCION INVALIDA, INTENTE OTRA VEZ!!!"); print(" "); esperandoEnter(); cleanScr();
		}
	} 
}

void Hospital::menuEspecialidad() {
	int opcion;
	bool banderaB = true;
	while (banderaB == true) {
		cleanScr();
		print("----------MENU DE ESPECIALIDADES----------");
		print(" ");
		print("[1] Ingresar Especialidades");
		print("[2] Lista de Especialidades");
		print("[3] Mostrar Doctores por especialidad");
		print("[4] Regresar al Menu Principal");
		print(" ");
		print("Digite una Opcion:");
		opcion = leerEntero();
		switch (opcion) {
		case 1: {
			cleanScr();
			string espe;
			if (colEsp->getCant() == cantEspecialidades) {
				print(mayus("Ya se han ingresado todas las especialidades del hospital"));
				esperandoEnter();
				break;
			}
			print("Por favor, digite la especialidad a ingresar en el hospital (Sin acentos):");
			espe = leerCadena();
			Especialidad* especi = new Especialidad(mayus(espe));
			if (colEsp->getCant() == 0) {
				colEsp->insertarEspecialidad(especi);
				print("Su especialidad se ha registrado satisfactoriamente!!!");
			}
			else {
				if (colEsp->validarIguales(mayus(espe)) == true) {
					print("La especialidad ya ha sido registrada anteriormente!!!");
				}
				else {
					colEsp->insertarEspecialidad(especi);
					print("Su especialidad se ha registrado satisfactoriamente!!!");
				}
			}
			esperandoEnter();
			break;
		};
		case 2: {
			cleanScr();
			print(colEsp->toString());
			esperandoEnter();
			break;
		};
		case 3: {
			cleanScr();
			if (colDoc->getCant() == 0) {
				print(mayus("No se han ingresado doctores en el hospital. Ingrese un doctor e intente nuevamente..."));
				esperandoEnter();
			}
			else {
				print(mayus("Doctores segun su especialidad"));
				print(" ");
				for (int i = 0; i < colEsp->getCant(); i++) {
					if (colEsp->getEspecialidad(i) != NULL) {
						print(colEsp->getEspecialidad(i)->getNombre());
						for (int j = 0; j < colDoc->getCant(); j++) {
							if (colDoc->getDoctor(j) != NULL) {
								if (colEsp->getEspecialidad(i)->getNombre() == colDoc->getDoctor(j)->getEspecialidad()->getNombre()) {
									print("Nombre:");
									print(colDoc->getDoctor(j)->getNombre());
									print("Codigo:");
									printNum(colDoc->getDoctor(j)->getCodigo());
								}
							}
							print(" ");
						}
					}
				}
			}
			esperandoEnter();
			break;
		};
		case 4: {
			banderaB = false;
			cleanScr();
			break;
		};
		default:print("OPCION INVALIDA, INTENTE OTRA VEZ!!!"); print(" "); esperandoEnter();
		}
	}
}

void Hospital::menuPabellon() {
	int opcion;
	bool banderaB = true;
	while (banderaB == true) {
		cleanScr();
		print("----------MENU DE PABELLONES Y CAMAS----------");
		print(" ");
		print("[1] Ingresar Pabellones");
		print("[2] Ingresar Cama a Pabellon");
		print("[3] Eliminar Cama");
		print("[4] Informe de Pabellones y sus Camas");
		print("[5] Regresar al Menu Principal");
		print(" ");
		print("Digite una Opcion");
		opcion = leerEntero();
		switch (opcion) {
		case 1: {
			cleanScr();
			char letra;
			char gen;
			if (colPab->getCant() == cantPabellones) {
				print(mayus("Ya se han ingresado todos los pabellones del hospital"));
				esperandoEnter();
				break;
			}
			print("Por favor, digite la letra distintiva del pabellon:");
			letra = leerChar();
			print("Ahora, digite si el pabellon es para hombres o mujeres (H para hombres, M para Mujeres):");
			gen = validarsexo();
			if (colPab->getCant() == 0) {
				Pabellon* pabe = new Pabellon(letra, gen);
				colPab->insertarPabellon(pabe);
				print("Su pabellon se ha creado satisfactoriamente!!!");
			}
			else {
				if (colPab->validarIguales(letra, gen) == true) {
					print("El pabellon ya ha sido creado anteriormente!!!");
				}
				else {
					Pabellon* pabe = new Pabellon(letra, gen);
					colPab->insertarPabellon(pabe);
					print("Su pabellon se ha creado satisfactoriamente!!!");
				}
			}
			esperandoEnter();
			break;
		};
		case 2: {
			cleanScr();
			char letra;
			char gen;
			print(colPab->toString());
			print(" ");
			print("De los siguientes pabellones, digite la letra del pabellon al que va a agregar una cama:");
			letra = leerChar();
			print("De los siguientes pabellones, digite el genero del pabellon al que va a agregar una cama (H o M):");
			gen = validarsexo();
			if (colPab->validarIguales(letra, gen) == true) {
				colPab->val(letra);
				print("Se ha ingresado la cama satisfactoriamente!!!");
			}
			else {
				print(mayus("No se ha encontrado el pabellon, intente nuevamente"));
			}
			esperandoEnter();
			break;
		};
		case 3: {
			cleanScr();
			string cam;
			print("Por favor, digite el codigo de la cama que desea eliminar:");
			cam = mayus(leerCadena());
			if (colPab->borrarCam(cam)==true) {
				print("La cama "+cam+" ha sido eliminada satisfactoriamente!!!");
			} else {
				print("No se ha podido eliminar la cama "+cam);
			}
			esperandoEnter();
			break;
		};
		case 4: {
			cleanScr();
			print(colPab->toStringPabCam());
			esperandoEnter();
			break;
		};
		case 5: {
			banderaB = false;
			cleanScr();
			break;
		};
		default:print("OPCION INVALIDA, INTENTE OTRA VEZ!!!"); print(" "); esperandoEnter();
		}
	}
}

void Hospital::menuDoctor() {
	int opcion;
	bool banderaB = true;
	while (banderaB) {
		cleanScr();
		print("----------MENU DE DOCTORES----------");
		print("[1] Ingresar Doctores");
		print("[2] Mostrar Lista de Doctores");
		print("[3] Informe Detallado por Doctor");
		print("[4] Renuncia o Despido del Doctor");
		print("[5] Regresar al Menu Principal");
		print(" ");
		print("Digite una Opcion");
		opcion = leerEntero();
		switch (opcion) {
		case 1: {
			cleanScr();
			string nom;
			string espe;
			int cod;
			if (colDoc->getCant() == cantDoctores) {
				print(mayus("Ya se han ingresado todas los doctores del hospital"));
				esperandoEnter();
				break;
			}
			print("Por favor, digite el NOMBRE COMPLETO del doctor a ingresar en el hospital (Sin acentos):");
			nom = validarAcentos(mayus(leerCadena()));
			print(" ");
			print(colEsp->toString());
			print("Ahora, digite la especialidad del doctor de acuerdo a las existentes en el hospital:");
			espe = mayus(leerCadena());
			int c = 0;
			for (int i = 0; i < colEsp->getTam(); i++) {
				if (colEsp->getEspecialidad(i) != NULL) {
					if (colEsp->getEspecialidad(i)->getNombre() == espe) {
						c++;
					}
				}
			}
			if (c == 0) {
				print(mayus("Esa especialidad no existe!!!"));
				esperandoEnter();
				break;
			}
			print("Finalmente, digite el codigo del doctor en el hospital:");
			cod = leerEntero();
			if (colDoc->getCant() == 0) {
				Doctor* d = new Doctor(nom,cod, colDoc->especialiti(espe, colEsp));
				colDoc->insertarDoctor(d);
				print("El doctor se ha registrado satisfactoriamente!!!");
			}
			else {
				if (colDoc->validarDoctores(cod) == true) {
					print("El doctor ya ha sido registrado anteriormente!!!");
				}
				else {
					Doctor* d = new Doctor(nom, cod, colDoc->especialiti(espe, colEsp));
					colDoc->insertarDoctor(d);
					print("Su doctor se ha registrado satisfactoriamente!!!");
				}
			}
			esperandoEnter();
			break;
		};
		case 2: {
			cleanScr();
			print(colDoc->toString());
			esperandoEnter();
			break;
		};
		case 3: {
			cleanScr();
			int cod;
			print("Por favor, digite el codigo del doctor que desea buscar:");
			cod = leerEntero();
			print(colDoc->toStringEspe(cod));
			esperandoEnter();
			break;
		};
		case 4: {
			cleanScr();
			int cod;
			string id;
			int conta = 0;
			print("Por favor, digite el codigo del doctor que desea eliminar:");
			cod = leerEntero();
			string codi = to_string(cod);
			if (colDoc->getDocPos(cod)==-1) {
				print("Ese doctor no existe!!!");
				esperandoEnter();
				break;
			} else {
				for (int i = 0; i < colPac->getCant(); i++){
					if (colPac->getPaciente(i) != NULL) {
						if (colPac->getPaciente(i)->getDocPac()->getNombre() == colDoc->getDoctor(colDoc->getDocPos(cod))->getNombre()) {
							conta++;
						}
					}
				}
			}
			if (conta!=0) {
				print(mayus("Ese doctor tiene pacientes, no se puede eliminar!!!"));
				print("Vaya al apartado de CAMBIAR DOCTOR A PACIENTE");
				esperandoEnter();
				break;
			} else {
				if (colDoc->eliminarDoctor(cod)) {
					print("El doctor de codigo " + codi + " ha sido eliminado satisfactoriamente!!!");
				}
				else {
					print("No se ha posido eliminar el doctor de codigo" + codi);
				}
			}
			esperandoEnter();
			break;
		};
		case 5: {
			banderaB = false;
			cleanScr();
			break;
		}
		default:print("OPCION INVALIDA, INTENTE OTRA VEZ!!!"); print(" "); esperandoEnter();
		}
	}
}

void Hospital::menuPaciente() {
	int opcion;
	bool banderaB = true;
	while (banderaB) {
		cleanScr();
		print("----------MENU DE PACIENTES----------");
		print("[1] Ingresar Pacientes");
		print("[2] Informe General de Pacientes");
		print("[3] Informe Estado de Paciente Especifico ");
		print("[4] Dar de Alta a Paciente");
		print("[5] Asignar o Cambiar de Cama a Paciente");
		print("[6] Asignar o Cambiar de Doctor a paciente");
		print("[7] Regresar al Menu Principal");
		print(" ");
		print("Digite una Opcion");
		opcion = leerEntero();
		switch (opcion) {
		case 1: {
			cleanScr();
			string id;
			string name;
			string direction;
			string pat;
			string surgery;
			char priori;
			char gen;
			int codDoc;
			string codCam;
			if (colPac->getCant() == cantPacientes) {
				print(mayus("Ya se han ingresado todos los pacientes del hospital"));
				esperandoEnter();
				break;
			}
			print("Digite la cedula del paciente a ingresar en el hospital:");
			id = leerCadena();
			print("Digite el NOMBRE COMPLETO del paciente a ingresar en el hospital (Sin acentos):");
			name = validarAcentos(mayus(leerCadena()));
			print("Digite la direccion del paciente:");
			direction = validarAcentos(mayus(leerCadena()));
			print("Digite la patologia del paciente:");
			pat = validarAcentos(mayus(leerCadena()));
			print("Digite el tipo de cirugia para el paciente:");
			surgery = validarAcentos(mayus(leerCadena()));
			print("Ahora, digite la prioridad del paciente (B-Prioridad baja | M-Prioridad media | A-Prioridad alta):");
			priori = leerChar();
			print("Digite el sexo del paciente (H para hombres, M para Mujeres):");
			gen = validarsexo();
			print(" ");
			print(colDoc->toString());
			print("Ingrese el codigo del doctor para el paciente:");
			codDoc = leerEntero();
			int c = 0;
			for (int i = 0; i < colDoc->getTam(); i++) {
				if (colDoc->getDoctor(i) != NULL) {
					if (colDoc->getDoctor(i)->getCodigo() == codDoc) {
						c++;
					}
				}
			}
			if (c == 0) {
				print(mayus("Ese doctor no existe!!!"));
				esperandoEnter();
				break;
			}
			print(colPab->toStringPabCam());
			print("Finalmente, ingrese el codigo de la cama para el paciente de acuerdo a su genero");
			codCam = mayus(leerCadena());
			int c2 = 0;
			for (int i = 0; i < colPab->getCant(); i++){
				if (colPab->getPabellon(i) != NULL) {
					for (int j = 0; j < colPab->getPabellon(i)->getCol()->getCant(); j++){
						if (colPab->getPabellon(i)->getCol()->getCama(j) != NULL) {
							if (colPab->getPabellon(i)->getGenero() == gen && colPab->getPabellon(i)->getCol()->getCama(j)->getCodigo() == codCam) {
								c2++;
							}
						}
					}
				}
			}
			if (c2==0) {
				print(mayus("Esa cama no existe o no esta para su genero!!!"));
				esperandoEnter();
				break;
			}
			if (colPac->getCant() == 0) {
				Paciente* pac = new Paciente(colPac->doctoriti(codDoc, colDoc), colPab->camariti(codCam), id, name, direction, pat, surgery, priori, gen);
				pac->getCamPac()->ocupar();
				colPac->insertarPaciente(pac);
				print("El paciente se ha registrado satisfactoriamente!!!");
			}
			else {
				if (colPac->validarPacientes(id) == true) {
					print("El paciente ya ha sido registrado anteriormente!!!");
				}
				else {
					Paciente* pac = new Paciente(colPac->doctoriti(codDoc, colDoc), colPab->camariti(codCam), id, name, direction, pat, surgery, priori, gen);
					colPac->insertarPaciente(pac);
					print("Su paciente se ha registrado satisfactoriamente!!!");
				}
			}
			esperandoEnter();
			break;
		};
		case 2: {
			cleanScr();
			print(colPac->toString());
			esperandoEnter();
			break;
		};
		case 3: {
			string id;
			cleanScr();
			print("Digite la cedula del paciente a buscar en el hospital:");
			id = leerCadena();
			print(colPac->toStringEspe(id));
			esperandoEnter();
			break;
		};
		case 4: {
			cleanScr();
			string cedu;
			print("Digite la cedula del paciente a dar de alta del hospital:");
			cedu = leerCadena();
			if (colPac->eliminarPaciente(cedu) == true) {
				print("El Paciente " + cedu + " ha sido eliminado satisfactoriamente!!!");
			}
			else {
				print("No se ha posido eliminar al paciente " + cedu);
			}
			esperandoEnter();
			break;
		};
		case 5: {
			cleanScr();
			menuAsignaCam();
			break;
		};
		case 6: {
			cleanScr();
			menuAsignaDoc();
			break;
		};
		case 7: {
			banderaB = false;
			cleanScr();
			break;
		};
		default:print("OPCION INVALIDA, INTENTE OTRA VEZ!!!"); print(" "); esperandoEnter();
		}
	}
}

void Hospital::menuAsignaCam() {
	int opcion;
	bool banderaC = true;
	while (banderaC) {
		print("----------MENU DE ASIGNACION CAMA-PACIENTE----------");
		print("[1] Cambiar Cama a Paciente");
		print("[2] Regresar al Menu Pacientes");
		print("Digite una Opcion");
		opcion = leerEntero();
		switch (opcion) {
		case 1: {
			cleanScr();
			string cedu;
			print("Digite la cedula del paciente:");
			cedu = leerCadena();
			if (colPac->buscarPac(cedu) == -1) {
				print("Ese paciente no existe!!!");
				esperandoEnter();
				break;
			}
			else {
				int c = 0;
				for (int i = 0; i < colPab->getCant(); i++){
					if (colPab->getPabellon(i) != NULL && colPab->getPabellon(i)->getGenero()==colPac->getPaciente(colPac->buscarPac(cedu))->getGenero()) {
						for (int j = 0; j < colPab->getPabellon(i)->getCol()->getCant(); j++){
							if (colPab->getPabellon(i)->getCol()->getCama(j)!=NULL && colPab->getPabellon(i)->getCol()->getCama(j)->disponible()=="Disponible") {
								c++;
							}
						}
					}
				}
				if (c == 0) {
					print("No existe otra cama con el mismo genero para el cambio!!!");
					esperandoEnter();
					break;
				}
				else {
					string came;
					print(colPab->toStringPabCam());
					print("Ahora, digite el codigo de la cama a cambiar");
					came = mayus(leerCadena());
					for (int  i = 0; i < colPab->getCant(); i++){
						if (colPab->getPabellon(i) != NULL && colPab->getPabellon(i)->getGenero() == colPac->getPaciente(colPac->buscarPac(cedu))->getGenero()) {
							if (colPab->camariti(came)) {
								colPac->getPaciente(colPac->buscarPac(cedu))->getCamPac()->desocupar();
								colPac->getPaciente(colPac->buscarPac(cedu))->setCamPac(colPab->camariti(came));
								colPac->getPaciente(colPac->buscarPac(cedu))->getCamPac()->ocupar();
								print("El cambio de cama se ha realizado satisfactoriamente!!!");
								esperandoEnter();
								break;
							}
						}
					}
				}
			}
			esperandoEnter();
			break;
		};
		case 2: {
			banderaC = false;
			cleanScr();
			break;
		}
		default:print("OPCION INVALIDA, INTENTE OTRA VEZ!!!"); print(" "); esperandoEnter();
		}



		
	}
}

void Hospital::menuAsignaDoc() {
	int opcion;
	bool banderaC = true;
	while (banderaC) {
		print("----------MENU DE CAMBIO DOCTOR-PACIENTE----------");
		print("[1] Cambiar Doctor a Paciente");
		print("[2] Regresar al Menu Pacientes");
		print("Digite una Opcion");
		opcion = leerEntero();
		switch (opcion) {
		case 1: {
			cleanScr();
			string cedu;
			print("Digite la cedula del paciente:");
			cedu = leerCadena();
			if (colPac->buscarPac(cedu) == -1) {
				print("Ese paciente no existe!!!");
				esperandoEnter();
				break;
			} else {
				int c = 0;
				for (int i = 0; i < colDoc->getCant(); i++){
					if (colDoc->getDoctor(i) != NULL) {
						if (colDoc->getDoctor(i)->getEspecialidad()->getNombre()==colPac->getPaciente(colPac->buscarPac(cedu))->getDocPac()->getEspecialidad()->getNombre()) {
							c++;
						}
					}
				}
				if (c == 0) {
					print("No existe otro doctor con la misma especialidad para el cambio!!!");
					esperandoEnter();
					break;
				} else {
					int cod;
					colPac->getPaciente(colPac->buscarPac(cedu))->getCamPac()->desocupar();
					print(colDoc->toString());
					print("Ahora, digite el codigo del doctor con la misma especialidad");
					cod = leerEntero();
					if (colPac->doctoriti(cod,colDoc)->getEspecialidad()->getNombre() == colPac->getPaciente(colPac->buscarPac(cedu))->getDocPac()->getEspecialidad()->getNombre()) {
						colPac->getPaciente(colPac->buscarPac(cedu))->setDocPac(colPac->doctoriti(cod,colDoc));
						print("El cambio de doctor se ha realizado satisfactoriamente!!!");
					} else {
						print(mayus("No se ha podido realizar el cambio, intente nuevamente!!!"));
					}
				}
			}
			esperandoEnter();
			break;
		};
		case 2: {
			banderaC = false;
			cleanScr();
			break;
		}
		default:print("OPCION INVALIDA, INTENTE OTRA VEZ!!!"); print(" "); esperandoEnter();
		}
	}
}