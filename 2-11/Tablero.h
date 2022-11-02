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
	int getN();
	int getM();
	int getL();
	int imprimirTablero();
	~Tablero();
};



#endif /* TABLERO_H_ */
