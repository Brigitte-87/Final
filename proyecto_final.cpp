#include <iostream>
#include "Cliente.h"

using namespace std;

int main() {
    Cliente c;
    int opcion;
    string nombres, apellidos, nit, correo_electronico, fecha_ingreso;
    int telefono, id;

    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Crear cliente" << endl;
        cout << "2. Leer clientes" << endl;
        cout << "3. Actualizar cliente" << endl;
        cout << "4. Borrar cliente" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            cout << "Ingrese Nombres: ";
            getline(cin, nombres);

            cout << "Ingrese Apellidos: ";
            getline(cin, apellidos);

            cout << "Ingrese NIT: ";
            getline(cin, nit);

            cout << "Ingrese Telefono: ";
            cin >> telefono;
            cin.ignore();

            cout << "Ingrese Correo Electronico: ";
            getline(cin, correo_electronico);

            cout << "Ingrese Fecha de Ingreso: ";
            getline(cin, fecha_ingreso);

            c = Cliente(nombres, apellidos, nit, telefono, correo_electronico, fecha_ingreso, 0);
            c.crear();
            break;

        case 2:
            c.leer();
            break;

        case 3:
            cout << "Ingrese ID del cliente a actualizar: ";
            cin >> id;
            cin.ignore();

            cout << "Ingrese nuevos Nombres: ";
            getline(cin, nombres);

            cout << "Ingrese nuevos Apellidos: ";
            getline(cin, apellidos);

            cout << "Ingrese nuevo NIT: ";
            getline(cin, nit);

            cout << "Ingrese nuevo Telefono: ";
            cin >> telefono;
            cin.ignore();

            cout << "Ingrese nuevo Correo Electronico: ";
            getline(cin, correo_electronico);

            cout << "Ingrese nueva Fecha de Ingreso: ";
            getline(cin, fecha_ingreso);

            c = Cliente(nombres, apellidos, nit, telefono, correo_electronico, fecha_ingreso, id);
            c.actualizar();
            break;

        case 4:
            cout << "Ingrese ID del cliente a borrar: ";
            cin >> id;
            cin.ignore();

            c.setId(id);
            c.borrar();
            break;

        case 5:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
}