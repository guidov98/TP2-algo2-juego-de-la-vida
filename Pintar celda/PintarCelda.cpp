#include "Comportamiento.h"
#include "EasyBMP.h"

void visualizador::dibujar celda(int ALTO, int ANCHO, comportamientoCelda comportamiento){
    switch(comportamiento){
        case(envenenada){
            int rojo = 19;
            int verde = 21;
            int azul = 170;
            int alpha = 0;
            break;
        }
        case(portal){
            int rojo = 19;
            int verde = 21;
            int azul = 140;
            int alpha = 0;
            break;
        }

        for(int x=inicio_x;x<(inicio_x + PIXELES_POR_CELDA);x++){
            for(int y=inicio_y;y<(inicio_y + PIXELES_POR_CELDA);y++){
                this->capa(x,y)->Red = rojo;
                this->capa(x,y)->Green = verde;
                this->capa(x,y)->Azul = blue;
                this->capa(x,y)->Alpha = alpha;
            }
        }
    }
}

void visualizador::dibujarCeldaVacia(int ALTO, int ANCHO){
    //unsigned int inicio_x = ((ALTO-1)*PIXELES_POR_CELDA);
    //unsigned int inicio_y = ((ANCHO-1)*PIXELES_POR_CELDA);

    for(int k=0; k<ALTO; k++){
        int x = k;
        int y=k;

        this->capa(k,k)->Red = 0;
        this->capa(k,k)->Green = 0;
        this->capa(k,k)->Azul = 0;
        this->capa(k,k)->Alpha = 0;
    }
}