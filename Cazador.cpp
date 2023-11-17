#include "Cazador.h"
#include <stdlib.h>

Cazador::Cazador(int x, int y, int dimension) {
	this->posicionX = x;
	this->posicionY = y;
	this->vida = 100;
	this->movimientos = 5 + rand() % (dimension - 4);
}
int Cazador::getPosicionX() const {
	return posicionX;
}
int Cazador::getPosicionY() const {
	return posicionY;
}
int Cazador::getVida() const {
	return vida;
}

int Cazador::getMovimientos() const {
	return movimientos;
}

void Cazador::nuevaPosicion(int x, int y){
	posicionX = x;
	posicionY = y;
}

void Cazador::dañoRecibido(int dano) {
	this->vida -= dano;
	if (this->vida<0) {
		this->vida = 0;
	}
}

void Cazador::movimientosTotales() {
	this->movimientos--;
}

;




