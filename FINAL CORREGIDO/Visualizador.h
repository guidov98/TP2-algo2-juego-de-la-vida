#ifndef VISUALIZADOR_INCLUDED
#define VISUALIZADOR_INCLUDED

#include "EasyBMP.h"
#include "Tablero.h"

class Visualizador
{
private:
    BMP capa;

public:
/*	Pre: 
	Post: Crea el Visualizador conlos parametros indicados*/
    Visualizador(int anchoTableroCapa, int altoTableroCapa);

/*	Pre: las posiciones no deben estar fuera de rango
	Post: Pinta la posicion indicada con el comportamiento indicado*/
    void pintarComportamiento(int posX, int posY, comportamientoCelda comportamiento);

/*	Pre: las posiciones no deben estar fuera de rango
	Post: Pinta la posicion indicada como una celula muerta*/
    void pintarCelulaNula(int posX, int posY);

/*	Pre: las posiciones no deben estar fuera de rango
	Post: Pinta la posicion indicada con los valores de la celula indicada*/
    void pintarCelula(int posX, int posY, Celula* celula);

/*	Pre: el tablero no puede ser NULL
	Post: Pinta todas las celulas de la capa n° altura */
    void dibujarCapa(Tablero* tablero, int altura);

/*	Pre: El Visualizador debe estar inicializado
	Post: Elimina el Visualizador*/
    virtual ~Visualizador();

/*	Pre: la altura debe se menor que L y mayor a 0
	Post: Genera una imagen de la capa indicada*/
    void exportarImagen(unsigned int altura);
};

#endif // VISUALIZADOR_INCLUDED