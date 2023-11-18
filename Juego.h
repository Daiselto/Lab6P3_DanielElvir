#pragma once
#include "Cazador.h"
#include "Isla.h"
#include <string>
using namespace std;
class Juego {
	Cazador Cazador1;
	Cazador Cazador2;
	Isla isla;
	int turno;
public:
	Juego();
	Juego(int, string, string);
	void iniciarJuego();
	bool posicionValida(int, int);
	void activarTrampa(Cazador& cazador);
	void interactuar(char);
	Cazador& cazadorTurno();
	void mostrarJuego(Isla&, Cazador&, Cazador&);
	void mover(int);

};

