#include "Celda.h"
#include <iostream>

void inicializarVecinos(Celda**** vecinos){
    vecinos = new Celda***[3];
    for (int i=0; i<3; i++){
        vecinos[i]=new Celda**[3];
        for (int j=0; j<3; j++){
            vecinos[i][j]=new Celda*[3];
            for (int k=0; k<3; k++){
                vecinos[i][j][k]=NULL;
            } 
        }
    }
}

Celda::Celda(){
    comportamiento = Inerte;
    celula = NULL;
    inicializarVecinos(this->vecinos);
}

Celda::Celda(comportamientoCelda state){
    comportamiento = state;
    celula = new Celula;
    inicializarVecinos(this->vecinos);
}

Celda::Celda(Celula * cell){
    comportamiento = Inerte;
    celula = cell;
    inicializarVecinos(this->vecinos);
}

Celda::Celda(comportamientoCelda state, Celula * cell){
    comportamiento = state;
    celula = cell;
    inicializarVecinos(this->vecinos);
}

Celula * Celda::getCelula(){
    return this->celula;
}

void Celda::setCelula(Celula * cell){
    if (this->comportamiento == Contaminada){
        return;
    }
    if (this->comportamiento == Envenenada){
        cell->getGen1()->setCargaGentica(0);
    }
    if (this->comportamiento == Radioactiva){
        cell->getGen1()->setCargaGentica(0);
        cell->getGen1()->setCargaGentica(0);
        cell->getGen1()->setCargaGentica(0);
    }
    this->celula = cell;

}

void Celda::setVecinos(Celda **** vectorVecinos){
    this->vecinos = vectorVecinos;
}

int Celda::contarVecinos(){
    int c = 0;
    int contador = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if (i==1 && j==1 && k==1){
                    continue;
                }
                if ((this->vecinos)[i][j][k]->getCelula()!=NULL){
                    contador++;
                }
            }
        }
    }
    return contador;
}

Celda::~Celda(){
    delete this->celula;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            delete[] (this->vecinos)[i][j];
        }
        delete[] (this->vecinos)[i];
    }
    delete[] (this->vecinos);
}