#ifndef CELDA_H_
#define CELDA_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

#include "Celula.h"

enum comportamientoCelda{
	Inerte,
	Contaminada,
	Envenenada,
	Procreadora,
	Portal,
	Radioactiva
};

class Celda{
private:
	Celula * celula;
	comportamientoCelda comportamiento;
public:
	int a;
	Celda();
	Celda(comportamientoCelda state);
	Celda(Celula * cell);
	Celda(comportamientoCelda state, Celula * cell);
	Celula * getCelula();
	void setCelula(Celula * cell);
};



#endif /* CELDA_H_ */
