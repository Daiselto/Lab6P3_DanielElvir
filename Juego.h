#pragma once
#include "Cazador.h"
#include "Isla.h"
class Juego {
	Cazador Cazador1;
	Cazador Cazador2;
	Isla isla;
	void iniciarJuego();
	void activarTrampa();
	Cazador& cazadorTurno();

};

