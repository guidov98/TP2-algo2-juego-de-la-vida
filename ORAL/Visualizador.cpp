#include <sstream>
#include "Visualizador.h"



Visualizador::Visualizador(int anchoTableroCapa, int altoTableroCapa)
{
	this->capa.SetBitDepth(32);
    //Definir ancho, prof y pixeles por casillero
	this->capa.SetSize(anchoTableroCapa * PIXELES_POR_CASILLERO, altoTableroCapa * PIXELES_POR_CASILLERO);
}

Visualizador::~Visualizador(){

}

void Visualizador::exportarImagen(unsigned int altura)
{
	std::stringstream alturaStr;
	alturaStr << altura;
	std::string nombreArchivo = NOMBRE_ARCHIVO + alturaStr.str() + ".bmp";
	this->capa.WriteToFile(nombreArchivo.c_str());
}

void Visualizador::pintarComportamiento(int posX, int posY, comportamientoCelda comportamiento){
    int rojo = 0;
	int verde = 0;
    int azul = 0;
    switch(comportamiento){
        case(Inerte):
            rojo = 255;
            verde = 255;
            azul = 255;
            break;
        case(Envenenada):
            rojo = 250;
            verde = 70;
            azul = 70;
            break;
        case(Portal):
            rojo = 33;
            verde = 227;
            azul = 243;
            break;
        case(Radioactiva):
            rojo = 33;
            verde = 243;
            azul = 52;
            break;
        case(Intercambiadora):
            rojo = 113;
            verde = 24;
            azul = 149;
            break;
        case(Contaminada):
            rojo = 241;
            verde = 234;
            azul = 129;
            break;
        default:
            break;
    }
	for(int x = posX*PIXELES_POR_CASILLERO; x<(posX+1)*PIXELES_POR_CASILLERO; x++){
	    for(int y = posY*PIXELES_POR_CASILLERO; y<(posY+1)*PIXELES_POR_CASILLERO; y++){
                this->capa(y,x)->Red = rojo;
                this->capa(y,x)->Green = verde;
                this->capa(y,x)->Blue = azul;
                this->capa(y,x)->Alpha = 0;
		}
	}
}

void Visualizador::pintarCelulaNula(int posX, int posY){
    for(int x = (posX*PIXELES_POR_CASILLERO)+((PIXELES_POR_CASILLERO/2)-(GROSOR_CRUZ/2)); x<(posX*PIXELES_POR_CASILLERO)+((PIXELES_POR_CASILLERO/2)+(GROSOR_CRUZ/2)); x++){
	    for(int y = (posY*PIXELES_POR_CASILLERO)+ANCHO_BORDE; y<((posY+1)*PIXELES_POR_CASILLERO)-ANCHO_BORDE; y++){
                this->capa(y,x)->Red = 0;
                this->capa(y,x)->Green = 0;
                this->capa(y,x)->Blue = 0;
                this->capa(y,x)->Alpha = 0;
		}
	}

    for(int x = (posX*PIXELES_POR_CASILLERO)+ANCHO_BORDE; x<((posX+1)*PIXELES_POR_CASILLERO)-ANCHO_BORDE; x++){
	    for(int y = (posY*PIXELES_POR_CASILLERO)+((PIXELES_POR_CASILLERO/2)-(GROSOR_CRUZ/2)); y<(posY*PIXELES_POR_CASILLERO)+((PIXELES_POR_CASILLERO/2)+(GROSOR_CRUZ/2)); y++){
                this->capa(y,x)->Red = 0;
                this->capa(y,x)->Green = 0;
                this->capa(y,x)->Blue = 0;
                this->capa(y,x)->Alpha = 0;
		}
	}
}

void Visualizador::pintarCelula(int posX, int posY, Celula* celula){
    if (celula==NULL){
        this->pintarCelulaNula(posX,posY);
        return;
    }
    int rojo = celula->getCargaGeneticaGen1();
	int verde = celula->getCargaGeneticaGen2();
    int azul = celula->getCargaGeneticaGen3();
	for(int x = posX*PIXELES_POR_CASILLERO+ANCHO_BORDE; x<(posX+1)*PIXELES_POR_CASILLERO-ANCHO_BORDE; x++){
	    for(int y = posY*PIXELES_POR_CASILLERO+ANCHO_BORDE; y<(posY+1)*PIXELES_POR_CASILLERO-ANCHO_BORDE; y++){
                this->capa(y,x)->Red = rojo;
                this->capa(y,x)->Green = verde;
                this->capa(y,x)->Blue = azul;
                this->capa(y,x)->Alpha = 0;
		}
	}
}

void Visualizador::dibujarCapa(Tablero* tablero, int altura)
{
    if (altura>=tablero->getL()){
        throw "Segmentation Fault";
    }
    tablero->getTablero()->reiniciarCursor();

    for(int i=0; i<=altura; i++){
        tablero->getTablero()->avanzarCursor();
    }
    int x = 0;
    int y = 0;
    tablero->getTablero()->getCursor()->reiniciarCursor();
    while(tablero->getTablero()->getCursor()->avanzarCursor()){
        tablero->getTablero()->getCursor()->getCursor()->reiniciarCursor();
        while(tablero->getTablero()->getCursor()->getCursor()->avanzarCursor()){
            Celda * aux = tablero->getTablero()->getCursor()->getCursor()->getCursor();
            this->pintarComportamiento(x,y,aux->getComportamiento());
            this->pintarCelula(x,y,aux->getCelula());
            y++;
        }
        y=0;
        x++;
    }
}

