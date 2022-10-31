/*
 * Celda.h
 *
 *  Created on: 30 oct. 2022
 *      Author: guido
 */

#ifndef CELDA_H_
#define CELDA_H_

#include "Celula.h"

enum estadoCelda{
	Contaminada,
	Envenenada,
	Procreadora,
	Portal,
	Radioactiva
};

class Celda{
private:
	Celula* celula;
	estadoCelda estado;
public:
	int a;
};



#endif /* CELDA_H_ */
