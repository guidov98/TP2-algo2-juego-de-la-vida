#ifndef VISUALIZADOR_INCLUDED
#define VISUALIZADOR_INCLUDED

#include "EasyBMP.h"
#include "tablero.h"

class Visualizador
{
private:
    BMP capa;

public:
    Visualizador();
    virtual ~Visualizador();
    void exportarImagen(unsigned int);
};

#endif // VISUALIZADOR_INCLUDED