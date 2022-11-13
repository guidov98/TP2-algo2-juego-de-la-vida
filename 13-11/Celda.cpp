#include "Celda.h"
#include <iostream>
#include <math.h>

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

void Celda::generarCelulaPorPromedios(){
    int acumuladorGen1 = 0;
    int acumuladorGen2 = 0;
    int acumuladorGen3 = 0;
    int cantidadVecinos = 0;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            for (int k = 0; k<3; k++){
                if (!(i==1 && j==1 && k==1)){
                    if(((this->vecinos)[i][j][k])->getCelula()!=NULL){
                        cantidadVecinos++;
                        acumuladorGen1 = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen1();
                        acumuladorGen2 = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen2();
                        acumuladorGen3 = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen3();
                    }
                }
            }
        }
    }
    Celula * aux = new Celula;
    int promedioGen1 = acumuladorGen1/cantidadVecinos;
    int promedioGen2 = acumuladorGen2/cantidadVecinos;
    int promedioGen3 = acumuladorGen3/cantidadVecinos;
    aux->setGens(promedioGen1,promedioGen2,promedioGen3);
    this->setCelula(aux);
}

void Celda::generarCelulaPorPromediosCuadrados(){
    int acumuladorGen1 = 0;
    int acumuladorGen2 = 0;
    int acumuladorGen3 = 0;
    int cantidadVecinos = 0;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            for (int k = 0; k<3; k++){
                if (!(i==1 && j==1 && k==1)){
                    if(((this->vecinos)[i][j][k])->getCelula()!=NULL){
                        cantidadVecinos++;
                        acumuladorGen1 = pow(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen1(),2);
                        acumuladorGen2 = pow(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen2(),2);
                        acumuladorGen3 = pow(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen3(),2);
                    }
                }
            }
        }
    }
    Celula * aux = new Celula;
    int promedioCuadraticoGen1 = sqrt(acumuladorGen1/cantidadVecinos);
    int promedioCuadraticoGen2 = sqrt(acumuladorGen2/cantidadVecinos);
    int promedioCuadraticoGen3 = sqrt(acumuladorGen3/cantidadVecinos);
    aux->setGens(promedioCuadraticoGen1, promedioCuadraticoGen2, promedioCuadraticoGen3);
    this->setCelula(aux);
}

void Celda::generarCelulaPorMinimos(){
    int minimoGen1 = 256;
    int minimoGen2 = 256;
    int minimoGen3 = 256;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            for (int k = 0; k<3; k++){
                if (!(i==1 && j==1 && k==1)){
                    if(((this->vecinos)[i][j][k])->getCelula()!=NULL){

                        if(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen1() < minimoGen1){
                            minimoGen1 = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen1();
                        }
                        if(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen2() < minimoGen2){
                            minimoGen2 = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen2();
                        }
                        if(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen3() < minimoGen3){
                            minimoGen3 = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen3();
                        }

                    }
                }
            }
        }
    }
    Celula * aux = new Celula;
    minimoGen1 = minimoGen1*1.1;
    if (minimoGen1>255){
        minimoGen1=255;
    }
    minimoGen2 = minimoGen2*1.2;
    if (minimoGen2>255){
        minimoGen2=255;
    }
    minimoGen3 = minimoGen3*1.3;
    if (minimoGen3>255){
        minimoGen3=255;
    }
    aux->setGens(minimoGen1, minimoGen2, minimoGen3);
    this->setCelula(aux);
}

void Celda::generarCelula(){
    if((this->getCelula())!=NULL){
        throw "Ya hay una celula, no se puede volver a generar una.";
    }

    switch(this->transmicion){

        case Promedios:
            this->generarCelulaPorPromedios();
            break;

        case PromediosCuadrados:
            this->generarCelulaPorPromediosCuadrados();
            break;

        case Minimos:
            this->generarCelulaPorMinimos();
            break;

    }
}

void Celda::matarCelula(){
    if (this->getCelula()==NULL){
        throw "No se puede matar celula muerta.";
    }
    delete this->getCelula();
    this->setCelula(NULL);
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

void Celda::setTransmicion(tipoDeTransmicion tipoTransmicion){
    this->transmicion = tipoTransmicion;
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