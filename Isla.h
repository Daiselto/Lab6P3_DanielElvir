#pragma once
class Isla{
	char** matriz;
	int dimension;
public:
	Isla();
	Isla(int);
	~Isla();
	void generarIsla();
	void mostrarIsla();
	char** getMatriz() const;
	int getDimension() const;
};

