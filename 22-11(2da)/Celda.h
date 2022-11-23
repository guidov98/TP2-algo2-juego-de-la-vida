#ifndef CELDA_H_
#define CELDA_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

#include "Celula.h"
#include <stdlib.h>
#include <time.h>

enum comportamientoCelda{
	Inerte,				//Celda sin comportamientos extra
	//Color: Blanca/Negra
	Contaminada,		//No deja crecer una celula
	//Color: Amarilla
	Portal,				//Duplica el nacimiento de una celula en otra
	//Color: Celeste
	Radioactiva,		//Afecta a 1 o varios genes al heredarse
	//Color: Verde
	Envenenada,  		//Mata un Gen
	//Color: Roja
	Intercambiadora,	//Intercambia Gen1 por Gen2, Gen2 por Gen3, Gen3 por Gen1
	//Color: Violeta
	CantidadComportamientos
};

enum tipoDeTransmicion{
	InvertirProgenitores,
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
	tipoDeTransmicion getTransmicion();
	comportamientoCelda getComportamiento();
	int * getNewGenes();
	Celda**** getVecinos();

	void setCelula(Celula * cell);
	void setTransmicion(tipoDeTransmicion tipoTransmicion);
	void setComportamiento(comportamientoCelda nuevoComportamiento);
	void setComportamientoRandom();
	void setVecinos(Celda **** vectorVecinos);

	bool hayCelulaViva();
	void nacerCelula(int gen1, int gen2, int gen3);
	void matarCelula();
	int contarVecinos();
	void copiarCelda(Celda * celdaFuente);
	~Celda();

private:
	void inicializarVecinos();
	int * getPromediosInvertidosVecinos();
	int * getPromedioCuadraticoVecinos();
	int * getMinimoVecinos();
};



#endif /* CELDA_H_ */