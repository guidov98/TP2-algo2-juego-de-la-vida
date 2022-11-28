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

/*	Pre: n, m y l tienen que ser mayor que 3
	Post: Crea el tablero con los valores indicados*/
	Tablero(int n, int m, int l, tipoDeTransmicion tipoTransmicion);

/*	Pre: -
	Post: Devuelve el Tablero*/
	Lista<Lista<Lista<Celda *> *> *> * getTablero();

/*	Pre: -
	Post: Devuelve el N del Tablero*/
	int getN();

/*	Pre: -
	Post: Devuelve el M del Tablero*/
	int getM();

/*	Pre: -
	Post: Devuelve el L del Tablero*/
	int getL();

/*	Pre: -
	Post: Devuelve la cantidad de Celulas vivas del Tablero*/
	int getCantidadCelulas();

/*	Pre: -
	Post: Devuelve la posicion de la Celda que coincide con las coordenadas indicadas del Tablero*/
	Celda * getCeldaPos(int x, int y, int z);

/*	Pre: -
	Post: Devuelve lel tipoDeTransmicion del Tablero*/
	tipoDeTransmicion getTransmicionTablero();

/*	Pre: -
	Post: Agrega una Celula con los genes indicados, en una posicion aleatoria del Tablero*/
	void agregarCelulaRandom(int gen1, int gen2, int gen3);

/*	Pre: -
	Post: Revive la Celula con los genes indicados, en la Celda que coincide con la posicion indicada del Tablero*/
	int revivirCelulaPos(int x, int y, int z, int gen1, int gen2, int gen3);

/*	Pre: -
	Post: Imprime el Tablero con 0s y 1s, donde 0 corresponde a Celula muerta y 1 a Celula viva*/
	int imprimirTablero();

/*	Pre: -
	Post: Actualiza el Tablero teniendo en cuenta los parametros indicados*/
	int actualizarTablero(int x1, int x2, int x3);

/*	Pre: -
	Post: Actualiza el comportamiento de las Celdas del Tablero, con un comportamiento aleatorio*/
	void actualizarComportamientoCeldas();

/*	Pre: El Tablero debe estar inicializado
	Post: Elimina el Tablero*/
	~Tablero();
private:

/*	Pre: -
	Post: Setea los vecinos de la Celda del Tablero indicada*/
	void setVecinosCelda(int x, int y, int z);

/*	Pre: -
	Post: Setea los vecinos de cada Celda del Tablero*/
	void setAllVecinos();

/*	Pre: tableroAux no puede ser NULL
	Post: Crea el tablero con los mismos valores que tableroAux*/
	Tablero(Tablero* tableroAux);

/*	Pre: -
	Post: Genera las Celulas debido a las Celulas portal en posiciones aleatorias del teclado*/
	int duplicarCelulas(Lista<Celula*> * celulasOrigen, int celulasPortales);
};

#endif /*TABLERO_H_*/
