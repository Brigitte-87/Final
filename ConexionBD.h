#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class ConexionBD {
private: MYSQL* conectar;
public:
	void abrir_conexion() {
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "usr_proyecto", "proyecto@123", "proyecto_final", 3306, NULL, 0);
	}
	MYSQL* getConectar() {
		return conectar;
	}
	void cerrar_conexion() {
		mysql_close(conectar);
	}
};