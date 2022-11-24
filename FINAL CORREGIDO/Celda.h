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

/*	Pre:  -
	Post:  Crea una celda con comportamiento Inerte, su celula muerta y sus vecinos como NULL*/
	Celda();

/*	Pre:  -
	Post: Crea una celda con comportamiento state, una nueva celula y sus vecinos como NULL*/
	Celda(comportamientoCelda state);

/*	Pre: cell no puede ser NULL 
	Post: Crea una celda con comportamiento Inerte, su celula igual a cell, y sus vecinos como NULL*/
	Celda(Celula * cell);

/*	Pre: cell no puede ser NULL
	Post: Crea una celda con comportamiento state, su celula igual a cell, y sus vecinos como NULL*/
	Celda(comportamientoCelda state, Celula * cell);


/*	Pre: -
	Post: Devuelve un puntero a la Celula de la Celda*/
	Celula * getCelula();

/*	Pre: -
	Post: Devuelve el tipoDeTransmicion de la Celda*/
	tipoDeTransmicion getTransmicion();

/*	Pre: -
	Post: Devuelve el comportamientoCelda de la Celda*/
	comportamientoCelda getComportamiento();

/*	Pre: -
	Post: Devuelve los nuevos genes de la Celda*/
	int * getNewGenes();

/*	Pre: -
	Post: Devuelve los punteros de las Celdas vecinas */
	Celda**** getVecinos();


/*	Pre: -
	Post: Setea la celula de la celda igual a cell */
	int setCelula(Celula * cell);

/*	Pre: -
	Post: Setea el tipoDeTransmicion de la celda igual a tipoTransmicion */
	void setTransmicion(tipoDeTransmicion tipoTransmicion);

/*	Pre: -
	Post: Setea el comportamientoCelda la celda igual a nuevoComportamiento*/
	void setComportamiento(comportamientoCelda nuevoComportamiento);

/*	Pre: -
	Post: Setea el comportamientoCelda de la celda a un comportamiento aleatorio*/
	void setComportamientoRandom();

/*	Pre: -
	Post: Setea los vecinos de la celda como el vectorVecinos*/
	void setVecinos(Celda **** vectorVecinos);


/*	Pre: -
	Post: Devuelve si la celula de la celda esta viva o no*/
	bool hayCelulaViva();

/*	Pre: 	el valor de cada gen debe estar entre 0 y 255
	Post: 	Si la celula de la Celda esta muerta, la setea como viva con los genes indicados
			Si ya esta viva, devuelve un mensaje de error indicandolo*/
	void nacerCelula(int gen1, int gen2, int gen3);

/*	Pre: -
	Post: Si la celula de la Celda esta viva, la setea a NULL, y si esta muerta devuelve un mensaje de error indicandolo*/
	void matarCelula();

/*	Pre: -
	Post: Devuelve la cantidad de Celulas vecinas vivas*/
	int contarVecinos();

/*	Pre: -
	Post: Setea a la Celda igual a celdaFuente*/
	void copiarCelda(Celda * celdaFuente);

/*	Pre: La Celda debe estar inicializada
	Post: Elimina la Celda*/
	~Celda();

private:

/*	Pre: -
	Post: Setea todos los vecinos a NULL*/
	void inicializarVecinos();

/*	Pre: -
	Post: Devuelve el promedio invertido de los genes Celdas vecinas */
	int * getPromediosInvertidosVecinos();

/*	Pre: -
	Post: Devuelve el promedio cuadratico de los genes Celdas vecinas */
	int * getPromedioCuadraticoVecinos();
/*	Pre: -
	Post: Devuelve el minimo de los genes Celdas vecinas */
	int * getMinimoVecinos();
};



#endif /* CELDA_H_ */