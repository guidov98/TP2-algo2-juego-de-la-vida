#include "Comportamiento.h"
#include "EasyBMP.h"

void visualizador::pintarComportamiento(int ALTO, int ANCHO, comportamientoCelda comportamiento){
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
	for(int x = 0; x<640; x++){
	    for(int y = 420; y<480; y++){
				
                AnImage(x,y)->Red = 50;
                AnImage(x,y)->Green = 50;
                AnImage(x,y)->Blue = 192;
                AnImage(x,y)->Alpha = 0;
		    }
	    }
        for(int x = 580; x<640; x++){
            for(int y = 0; y<480; y++){

                AnImage(x,y)->Red = 50;
                AnImage(x,y)->Green = 50;
                AnImage(x,y)->Blue = 192;
                AnImage(x,y)->Alpha = 0;
            }
        }
        for(int x = 0; x<640; x++){
            for(int y = 0; y<60; y++){

                AnImage(x,y)->Red = 50;
                AnImage(x,y)->Green = 50;
                AnImage(x,y)->Blue = 192;
                AnImage(x,y)->Alpha = 0;
            }
        }
        for(int x = 0; x<60; x++){
            for(int y = 0; y<480; y++){

                AnImage(x,y)->Red = 50;
                AnImage(x,y)->Green = 50;
                AnImage(x,y)->Blue = 192;
                AnImage(x,y)->Alpha = 0;
            }
        }
    }
}

void visualizador::dibujarCelda(Tablero* tablero, unsigned int altura)
{
	Celda* celdaActual;

    for(unsigned int L = 1; L <= tablero->getL(); L++)
    {
    	for(unsigned int M = 1; M <= tablero->getM(); M++)
    	{
    		celdaActual = tablero->getCeldaPos(M, L, altura);

    		this->pintarComportamiento(M, L, celdaActual->getComportamiento());

    		switch(celdaActual->getEstado())
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
void visualizador::dibujarCeldaVacia(int ALTO, int ANCHO, ){
	
	for(int x = 290; x<350; x++){
	    for(int y = 0; y<480; y++){
				
                AnImage(x,y)->Red = 255;
                AnImage(x,y)->Green = 0;
                AnImage(x,y)->Blue = 0;
                AnImage(x,y)->Alpha = 0;
		}
	}
	for(int x = 0; x<640; x++){
	    for(int y = 210; y<270; y++){
				
                AnImage(x,y)->Red = 255;
                AnImage(x,y)->Green = 0;
                AnImage(x,y)->Blue = 0;
                AnImage(x,y)->Alpha = 0;
		}
	}
}
	
	
	
	
	
