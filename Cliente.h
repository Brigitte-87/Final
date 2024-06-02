#pragma once
#include "mysql.h"
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
using namespace std;
class Cliente : Persona {
	// Atributos
private: string nom;
	   int id = 0;

	   // Constructor
public:
	Cliente() {
	}

	Cliente(string nom, string ape, string n, int tel, string ce, string fi, int i) : Persona(nom, ape, n, ce, fi, tel) {
		id = i;
	}

	// Metodos
	// Set (modificar)
	void setId(int i) { id = i; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setNit(string n) { nit = n; }
	void setTelefono(int tel) { telefono = tel; }
	void setCorreo_electronico(string ce) { correo_electronico = ce; }
	void setFecha_ingreso(string fi) { fecha_ingreso = fi; }

	// Get (mostrar)
	int getId() { return id; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getNit() { return nit; }
	int getTelefono() { return telefono; }
	string getCorreo_electronico() { return correo_electronico; }
	string getFecha_ingreso() { return fecha_ingreso; }


	//Metodos
	void borrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string ii = to_string(id);
		if (cn.getConectar()) {
			string borrar = "delete from clientes  where id_cliente = " + ii + "";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\n ------BORRADO------" << endl;
			}
			else {
				cout << "\n xxx ERROR AL BORRAR xxx " << endl;
			}
		}
		else {
			cout << "\n*Error en la conexion*" << endl;
		}
		cn.cerrar_conexion();
	}


	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string ii = to_string(id);
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string  actualizar = "update clientes set nombres = '" + nombres + "', apellidos = '" + apellidos + "', nit = '" + nit + "', telefono = " + t + ", correo_electronico = '" + correo_electronico + "', fecha_ingreso = '" + fecha_ingreso + "' where(id_cliente = '" + ii + "')";
			const char* i = actualizar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "/Actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al actualizar xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string insert = "INSERT INTO clientes(nombres,apellidos,nit,telefono,correo_electronico,fecha_ingreso)VALUES('" + nombres + "','" + apellidos + "','" + nit + "'," + t + ",'" + correo_electronico + "','" + fecha_ingreso + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\n ------INGRESO EXITOSO------" << endl;
			}
			else {
				cout << "\n xxx Error al ingresar la informacion xxx " << endl;
			}
		}
		else {
			cout << "\n*Error en la conexion*" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "\n------------Clientes------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}
			}
			else {
				cout << "\n*Error en la consulta*" << endl;
			}
		}
		else {
			cout << "\n*Error en la conexion*" << endl;
		}
		cn.cerrar_conexion();
	}
};