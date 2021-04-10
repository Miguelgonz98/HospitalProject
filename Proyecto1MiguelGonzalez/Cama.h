#ifndef CAMA_H
#define CAMA_H
using namespace std;
#include<string>

class Cama {
private:
	string codigo;
	bool estado;
public:
	Cama(string ="");
	void setCodigo(string);
	string getCodigo();
	void ocupar();
	void desocupar();
	string disponible();
};
#endif // !CAMA_H