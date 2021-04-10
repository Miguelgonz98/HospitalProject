#include"Interfaz.h"

void print(string cadena) {
	cout << cadena << endl;
}

string leerCadena() {
	string x;
	getline(cin, x);
	cin.clear();
	cin.ignore(1024, '\n');
	return x;
}

int leerEntero() {
	int n;
	bool continuar = true;
	while (true) {
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "Valor incorrecto.. digita UN NUMERO" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

void cleanScr() {
	system("cls");
}

void esperandoEnter() {
	cin.get();
}

string mayus(string cadena) {
	for (size_t i = 0; i < cadena.length(); i++){
		cadena[i] = toupper(cadena[i]);
	}
	return cadena;
}

char mayusCh(char car) {
	car = toupper(car);
	return car;
}

void cambiarColor(){
	system("color 0a");
}

string validarAcentos(string cadena) {
	for (int i = 0; i < cadena.length(); i++){
		if (cadena[i] == 'Á') {
			cadena[i] = 'A';
		}
		if (cadena[i] == 'É') {
			cadena[i] = 'E';
		}
		if (cadena[i] == 'Í') {
			cadena[i] = 'I';
		}
		if (cadena[i] == 'Ó') {
			cadena[i] = 'O';
		}
		if (cadena[i] == 'Ú') {
			cadena[i] = 'U';
		}
		if (cadena[i] == 'á') {
			cadena[i] = 'a';
		}
		if (cadena[i] == 'é') {
			cadena[i] = 'e';
		}
		if (cadena[i] == 'í') {
			cadena[i] = 'i';
		}
		if (cadena[i] == 'ó') {
			cadena[i] = 'o';
		}
		if (cadena[i] == 'ú') {
			cadena[i] = 'u';
		}
	}
	return cadena;
}

void printNum(int num) {
	cout << num << endl;
}

char leerChar() {
	char car;
	bool continuar = true;
	while (true) {
		cin >> car;
		char carac = mayusCh(car);
		if (carac != '0' && carac != '1' && carac != '2' && carac != '3' && carac != '4' && carac != '5' && carac != '6' && carac != '7' && carac != '8' && carac != '9') {
			cin.clear();
			cin.ignore(1024, '\n');
			return carac;
		}
		else {
			cerr << "Caracter incorrecto.. digita UNA LETRA" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

char validarsexo() {
	char car;
	bool continuar = true;
	while (true) {
		cin >> car;
		char carac = mayusCh(car);
		if (carac == 'M' || carac == 'H') {
			cin.clear();
			cin.ignore(1024, '\n');
			return carac;
		} else {
			cerr << "Caracter incorrecto.. digita H para Hombres o M para Mujeres" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}