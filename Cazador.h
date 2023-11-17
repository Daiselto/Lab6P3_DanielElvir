#pragma once
class Cazador{
	int posicionX;
	int posicionY;
	int vida;
	int movimientos;
	char Nombre;
public:
	Cazador(int, int, int);
	int getPosicionX() const;
	int getPosicionY() const;
	int getVida() const;
	int getMovimientos() const;
	void nuevaPosicion(int, int);
	void dañoRecibido(int);
	void movimientosTotales();
};

