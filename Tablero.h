/*
 * Tablero.h
 *
 *  Created on: 29 oct. 2022
 *      Author: guido
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Celda.h"
#include "Nodo.h"
#include "Lista.h"

class Tablero
{
private:
	Lista<Lista<Lista<Celda*>*> *> * tablero;
	int N;
	int M;
	int L;

public:
	Tablero(int n, int m, int l);
	void getN();
	void getM();
	void getL();
	int imprimirTablero();
};



#endif /* TABLERO_H_ */
