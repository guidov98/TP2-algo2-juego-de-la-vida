#ifndef TABLERO_H_
#define TABLERO_H_

#include "Celda.h"
#include "Lista.h"

class Tablero
{
private:
	Lista<Lista<Lista<Celda*>*> *> * tablero;
	int N;
	int M;
	int L;
	void agregarCelulaRandom(int gen1, int gen2, int gen3);
	void setVecinosCelda(int x, int y, int z);
	void setAllVecinos();

public:
	Tablero(int n, int m, int l, tipoDeTransmicion tipoTransmicion);
	int getN();
	int getM();
	int getL();
	Lista<Lista<Lista<Celda *> *> *> * getTablero();
	Celda * getCeldaPos(int x, int y, int z);
	int imprimirTablero();
	void actualizarTablero(int x1, int x2, int x3);
	void actualizarComportamientoCeldas();
	~Tablero();
};

#endif /* TABLERO_H_ */
