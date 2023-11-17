#include <iostream>
#include <locale>
#include "Cazador.h"
#include "Isla.h"
#include "Juego.h"
using namespace std;

void iniciarJuego() {
	int dimension=0;
	cout << "Bienvenido a una nueva partida" << endl;
	cout << "Ingrese el tamaño de la isla (Tiene que ser mayor de 10)" << endl;
	cin >> dimension;
	while (dimension<10) {
		cout << "La isla tiene que ser mayor de 10" << endl;
		cout << "Ingrese el tamaño de la isla (Tiene que ser mayor de 10)" << endl;
		cin >> dimension;
	}

	string nombre1, nombre2;
	cout << "Ingrese el nombre del cazador 1" << endl;
	cin >> nombre1;
	cout << "Ingrese el nombre del cazador 2" << endl;
	cin >> nombre2;

}

void menu() {
	bool seguir = true;
	int opcion = 0;
	while (seguir) {
		cout << "Bienvenido al juego CAZADORES DE TESOROS (Patente Pendiente)" << endl;
		cout << "Que desea hacer?" << endl;
		cout << "1. Iniciar juego" << endl;
		cout << "2. Salir del juego" << endl;
		cout << "Escoja una opción valida" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			iniciarJuego();
			break;

		case 2:
			cout << "Gracias por jugar" << endl;
			seguir = false;
			break;

		default:
			cout << "ERROR" << endl;
			cout << "ESCOJA UNA OPCION VALIDA" << endl;
			break;
		}
	}
	
	
}

int main() {
	setlocale(LC_ALL, "spanish");
	menu();
}
