#ifndef VISUALIZADOR_INCLUDED
#define VISUALIZADOR_INCLUDED

#include "EasyBMP.h"
#include "Tablero.h"

class Visualizador
{
private:
    BMP capa;

public:
    Visualizador(int anchoTableroCapa, int altoTableroCapa);
    void pintarComportamiento(int posX, int posY, comportamientoCelda comportamiento);
    void pintarCelulaNula(int posX, int posY);
    void pintarCelula(int posX, int posY, Celula* celula);
    void pintarCelda(int posX, int posY, Celula* celula);
    void dibujarCapa(Tablero* tablero, int altura);
    virtual ~Visualizador();
    void exportarImagen(unsigned int);
};

#endif // VISUALIZADOR_INCLUDED