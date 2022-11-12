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

enum tipoDeTransmicion{
	Promedios,
	PromediosCuadrados,
	Minimos
};

class Celda{
private:
	Celula * celula;
	comportamientoCelda comportamiento;
	tipoDeTransmicion transmicion;
	Celda**** vecinos;
public:
	Celda();
	Celda(comportamientoCelda state);
	Celda(Celula * cell);
	Celda(comportamientoCelda state, Celula * cell);

	Celula * getCelula();
	void generarCelula();
	void setCelula(Celula * cell);
	void setTransmicion(tipoDeTransmicion tipoTransmicion);
	void setVecinos(Celda **** vectorVecinos);
	int contarVecinos();
	~Celda();
};



#endif /* CELDA_H_ */