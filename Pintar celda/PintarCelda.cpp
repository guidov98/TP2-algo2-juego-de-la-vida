#include "Comportamiento.h"
#include "EasyBMP.h"

void visualizador::pintarComportamiento(int ALTO, int ANCHO, comportamientoCelda comportamiento){
	unsigned int pixelesX = 640;
	unsigned int pixelesY = 480;
	unsigned int anchoBorde = 60;
	
    switch(comportamiento){
        case(envenenada){
            int rojo = 245;
            int verde = 0;
            int azul = 0;
            int alpha = 0;
            break;
        }
        case(portal){
            int rojo = 33;
            int verde = 227;
            int azul = 243;
            int alpha = 0;
            break;
        }
        case(Radioactiva){
            int rojo = 33;
            int verde = 243;
            int azul = 52;
            int alpha = 0;
            break;
        }
        case(intercambiadora){
            int rojo = 113;
            int verde = 24;
            int azul = 149;
            int alpha = 0;
            break;
        }
        case(contaminada){
            int rojo = 241;
            int verde = 234;
            int azul = 129;
            int alpha = 0;
            break;
        }
	for(int x = 0; x<pixelesX; x++){
	    for(int y = pixelesY - anchoBorde; y<pixelesY; y++){
				
                this->capa(x,y)->Red = 50;
                this->capa(x,y)->Green = 50;
                this->capa(x,y)->Blue = 192;
                this->capa(x,y)->Alpha = 0;
		    }
	    }
        for(int x = pixelesX - anchoBorde; x<pixelesX; x++){
            for(int y = 0; y<pixelesY; y++){

                this->capa(x,y)->Red = 50;
                this->capa(x,y)->Green = 50;
                this->capa(x,y)->Blue = 192;
                this->capa(x,y)->Alpha = 0;
            }
        }
        for(int x = 0; x<pixelesX; x++){
            for(int y = 0; y<anchoBorde; y++){

                this->capa(x,y)->Red = 50;
                this->capa(x,y)->Green = 50;
                this->capa(x,y)->Blue = 192;
                this->capa(x,y)->Alpha = 0;
            }
        }
        for(int x = 0; x<anchoBorde; x++){
            for(int y = 0; y<pixelesY; y++){

                this->capa(x,y)->Red = 50;
                this->capa(x,y)->Green = 50;
                this->capa(x,y)->Blue = 192;
                this->capa(x,y)->Alpha = 0;
            }
        }
    }
}

void visualizador::dibujarCelda(Tablero* tablero, unsigned int altura)
{
	Celda* celdaActual;
	Celula* celulaActual;

    for(unsigned int L = 1; L <= tablero->getL(); L++)
    {
    	for(unsigned int M = 1; M <= tablero->getM(); M++)
    	{
    		celdaActual = tablero->getCeldaPos(M, L, altura);

    		this->pintarComportamiento(M, L, celdaActual->getComportamiento());
		this->pintarCelula(/*Coordenadas de la celula*/, celulaActual->getCargaGeneticaGen1(), celulaActual->getCargaGeneticaGen2(), celulaActual->getCargaGeneticaGen3()));
    		switch(celulaActual->getEstado())
    		{
    			case viva:
    				this->dibujarCeldaVacia(M, L);
    				break;
    			case muerta:
    				this->dibujarCeldaMuerta(M, L);
					break;
    		}
    	}
    }
}
void visualizador::dibujarCeldaVacia(//Definido en Constantes, ){
	
	unsigned int pixelesX = 640;
	unsigned int pixelesY = 480;
	unsigned int anchoBorde = 60;
	
    for(int x = (pixelesX/2) - (anchoBorde/2); x<(pixelesX/2) + (anchoBorde/2); x++){
	    for(int y = 0; y < pixelesY; y++){
				
                this->capa(x,y)->Red = 255;
                this->capa(x,y)->Green = 0;
                this->capa(x,y)->Blue = 0;
                this->capa(x,y)->Alpha = 0;
		    }
	    }
	for(int x = 0; x < pixelesX; x++){
	    for(int y = (pixelesY/2) - (anchoBorde/2); y<(pixelesY/2) + (anchoBorde/2); y++){
				
                this->capa(x,y)->Red = 255;
                this->capa(x,y)->Green = 0;
                this->capa(x,y)->Blue = 0;
                this->capa(x,y)->Alpha = 0;
		    }
	    }
}
	
void visualizador::pintarCelula(/*Definido en Constantes*/, int cargaGenetica1, int cargaGenetica2, int cargaGenetica3){
	
	unsigned int pixelesX = 640;
	unsigned int pixelesY = 480;
	unsigned int anchoBorde = 60;
	
	    for(int x = anchoBorde; x<(pixelesX - anchoBorde); x++){
	    	for(int y = anchoBorde; y < (pixelesY - anchoBorde); y++){
				
                this->capa(x,y)->Red = cargaGenetica1;
                this->capa(x,y)->Green = cargaGenetica2;
                this->capa(x,y)->Blue = cargaGenetica3;
		   }
	    }
}
//HACER ARCHIVO CONSTANTES	
