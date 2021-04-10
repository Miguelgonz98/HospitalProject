#include"Hospital.h"
#include<iostream>
using namespace std;

int main() {
	cambiarColor();
	Hospital *esperanza = new Hospital();
	esperanza->menuInicio();
	delete esperanza;
	cin.get();
	return 0;
}
