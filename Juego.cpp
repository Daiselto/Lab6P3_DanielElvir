#include "Juego.h"
#include "Cazador.h"
#include "Isla.h"
#include <iostream>
using namespace std;

Juego::Juego() {	
}

Juego::Juego(int dimension, string nombre1, string nombre2) : isla(dimension), Cazador1(0, 0, dimension), Cazador2(0, dimension-1, dimension) {
	isla.generarIsla();

	Cazador1.setNombre(nombre1[0]);
	Cazador2.setNombre(nombre2[0]);
	isla.getMatriz()[0][0] = Cazador1.getNombre();
	isla.getMatriz()[0][dimension - 1] = Cazador2.getNombre();

	cout << "Inicia una aventura con los jugadores" << endl;
	cout << "Cazador 1: " << nombre1 << endl;
	cout << "Cazador 2: " << nombre2 << endl;
	cout << endl;
	//isla.mostrarIsla();
}



void Juego::iniciarJuego(){
	bool seguir = true;
	int direccion;
	turno = rand() % 2 + 1;
	while (seguir) {
		if (Cazador1.getMovimientos()>0&&Cazador2.getMovimientos()>0) {								
			mostrarJuego(isla, Cazador1, Cazador2);
			Cazador& cazadorActual = cazadorTurno();

			cout << "Turno del cazador " << cazadorActual.getNombre() << endl;
			cout << "Ingrese la dirección para mover al cazador actual" << endl;
			cout << "1. Arriba" << endl;
			cout << "2. Abajo" << endl;
			cout << "3. Izquierda" << endl;
			cout << "4. Derecha" << endl;
			cin >> direccion;				
			mover(direccion);
			int x = cazadorActual.getPosicionX();
			int y = cazadorActual.getPosicionY();
			char posicionActual = isla.getMatriz()[x][y];

			interactuar(posicionActual);
			//mostrarJuego(isla, Cazador1, Cazador2);
			turno = 3 - turno; 
			if (Cazador1.getMovimientos() <= 0 && Cazador2.getMovimientos() <= 0) {
				seguir = false; 
			}
		}else {
			seguir = false;
		}
	}
}

bool Juego::posicionValida(int x, int y) {
	if (x >= 0 && x < isla.getDimension() && y >= 0 && y < isla.getDimension()) {
		return true;
	}
	else {
		return false;
	}
}

void Juego::activarTrampa(Cazador& cazador) {
	int dano = 1 + rand() % 50;
	cazador.dañoRecibido(dano);
	
	if (&cazador == &Cazador1) {
		cout << "El cazador 1 recibió una cantidad de " << dano << " puntos de daño" << endl;
	}
	else if (&cazador == &Cazador2) {
		cout << "El cazador 2 recibió una cantidad de " << dano << " puntos de daño" << endl;
	}
}

void Juego::interactuar(char pos) {
	Cazador& cazadorActual = cazadorTurno();

	if (pos == 'X') {
		cout << "¡El cazador " << cazadorActual.getNombre() << " ha encontrado el tesoro! ¡Ha ganado el juego!\n";
	}
	else if (pos == '#') {
		activarTrampa(cazadorActual);
	}
}

Cazador& Juego::cazadorTurno() {
	if (turno == 1) {
		return Cazador1;
	}
	else {
		return Cazador2;
	}
}

void Juego::mostrarJuego(Isla& isla, Cazador& Cazador1, Cazador& Cazador2) {
	cout << "Estado actual de la isla: " << endl;
	isla.mostrarIsla();
	cout << "Movimientos restantes del cazador 1: " << Cazador1.getMovimientos() << endl;
	cout << "Vida del cazador 1 : " << Cazador1.getVida() << endl;
	cout << "Movimientos restantes del cazador 2 : " << Cazador2.getMovimientos() << endl;
	cout << "Vida del cazador 2 : " << Cazador2.getVida() << endl;
}

void Juego::mover(int direccion) {
	Cazador& cazadorActual = cazadorTurno();
	int nueva_pos_x = cazadorActual.getPosicionX();
	int nueva_pos_y = cazadorActual.getPosicionY();

	isla.getMatriz()[nueva_pos_x][nueva_pos_y] = '-';

	switch (direccion) {
	case 1:  
		nueva_pos_x--;
		break;
	case 2:  
		nueva_pos_x++;
		break;
	case 3:  
		nueva_pos_y--;
		break;
	case 4:  
		nueva_pos_y++;
		break;
	default:
		cout << "Dirección inválida\n";
		return;
	}

	if (posicionValida(nueva_pos_x, nueva_pos_y)) {
		cazadorActual.nuevaPosicion(nueva_pos_x, nueva_pos_y);
		isla.getMatriz()[nueva_pos_x][nueva_pos_y] = cazadorActual.getNombre();
		cazadorActual.movimientosTotales();
	}
	else {
		cout << "Movimiento inválido. No se puede salir de los límites de la isla.\n";
		isla.getMatriz()[cazadorActual.getPosicionX()][cazadorActual.getPosicionY()] = cazadorActual.getNombre();
	}
}


