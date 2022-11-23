#ifndef TABLERO_H_
#define TABLERO_H_

#include "Celda.h"
#include "Lista.h"

class Tablero{
private:
	Lista<Lista<Lista<Celda*>*> *> * tablero;
	int N;
	int M;
	int L;
	int cantidadCelulas;
	tipoDeTransmicion transmicion;

public:
	Tablero(int n, int m, int l, tipoDeTransmicion tipoTransmicion);

	Lista<Lista<Lista<Celda *> *> *> * getTablero();
	int getN();
	int getM();
	int getL();
	int getCantidadCelulas();
	Celda * getCeldaPos(int x, int y, int z);
	tipoDeTransmicion getTransmicionTablero();

	void agregarCelulaRandom(int gen1, int gen2, int gen3);
	void revivirCelulaPos(int x, int y, int z, int gen1, int gen2, int gen3);
	int imprimirTablero();

	int actualizarTablero(int x1, int x2, int x3);
	void actualizarComportamientoCeldas();

	~Tablero();
private:
	void setVecinosCelda(int x, int y, int z);
	void setAllVecinos();
	Tablero(Tablero* tableroAux);
	int duplicarCelulas(Lista<Celula*> * celulasOrigen, int celulasPortales);
};

#endif /*TABLERO_H_*/
