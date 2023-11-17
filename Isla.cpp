#include "Isla.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Isla::Isla(int dimension){
	this->dimension = dimension;
}

Isla::~Isla() {
	for (int i = 0; i < dimension; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
}

void Isla::generarIsla() {
	matriz = new char* [dimension];
	int cantTrampas;
	for (int i = 0; i < dimension; i++) {
		matriz[i] = new char[dimension];
		for (int j = 0; j < dimension; j++) {
			matriz[i][j] = '-';
		}
	}

	cantTrampas = 1 + rand() % (dimension * dimension) / 2;
	while (cantTrampas > 0) {
		int x = rand() % dimension;
		int y = rand() % dimension;

		if (matriz[x][y] != '#' && matriz[x][y] != 'X') {
			matriz[x][y] = '#';
			cantTrampas--;
		}
	}

	int xTesoro = rand() % dimension;
	int yTesoro = rand() % dimension;

	matriz[xTesoro][yTesoro] = 'X';
}

void Isla::mostrarIsla() {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

char** Isla::getMatriz() const {
	return matriz;
}

int Isla::getDimension() const {
	return dimension;
}



