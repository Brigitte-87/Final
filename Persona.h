#pragma once
#include <iostream>
using namespace std;

class Persona {
	// Atributos
protected: string nombres, apellidos, nit, correo_electronico, fecha_ingreso;
		 int telefono = 0;

		 // Constructor 
protected:
	Persona() {
	}
	Persona(string nom, string ape, string n, string ce, string fi, int tel) {

	}
};/*