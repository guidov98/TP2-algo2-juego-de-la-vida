#include "Celda.h"
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

void Celda::inicializarVecinos(){
    this->vecinos = new Celda***[3];
    for (int i=0; i<3; i++){
        this->vecinos[i]=new Celda**[3];
        for (int j=0; j<3; j++){
            this->vecinos[i][j]=new Celda*[3];
            for (int k=0; k<3; k++){
                this->vecinos[i][j][k]=NULL;
            } 
        }
    }
}

Celda::Celda(){
    this->comportamiento = Inerte;
    this->celula = NULL;
    this->vecinos = NULL;
    this->inicializarVecinos();
}

Celda::Celda(comportamientoCelda state){
    this->comportamiento = state;
    this->celula = new Celula;
    this->vecinos = NULL;
    this->inicializarVecinos();
}

Celda::Celda(Celula * cell){
    this->comportamiento = Inerte;
    this->celula = cell;
    this->vecinos = NULL;
    this->inicializarVecinos();
}

Celda::Celda(comportamientoCelda state, Celula * cell){
    this->comportamiento = state;
    this->celula = cell;
    this->vecinos = NULL;
    this->inicializarVecinos();
}


Celula * Celda::getCelula(){
    return this->celula;
}

tipoDeTransmicion Celda::getTransmicion(){
    return this->transmicion;
}

comportamientoCelda Celda::getComportamiento(){
    return this->comportamiento;
}

void aplicarComportamiento(int genes[3], comportamientoCelda comportamiento){
    if (comportamiento==Radioactiva){
        genes[0]=genes[0]/2;
        genes[2]=genes[2]/3;
    }
    else if(comportamiento==Envenenada){
        genes[1]=0;
    }
    else if(comportamiento==Intercambiadora){
        int aux[3];
        aux[0]=genes[0];
        aux[1]=genes[1];
        aux[2]=genes[2];
        genes[0]=aux[1];
        genes[1]=aux[2];
        genes[2]=aux[0];
    }
}

int * Celda::getNewGenes(){
    if((this->getCelula())!=NULL){
        throw "Ya hay una celula, no se puede volver a generar una.";
    }
    int * genes = NULL;
    switch(this->transmicion){
        case InvertirProgenitores:
            genes = this->getPromediosInvertidosVecinos();
            break;

        case PromediosCuadrados:
            genes = this->getPromedioCuadraticoVecinos();
            break;

        case Minimos:
            genes = this->getMinimoVecinos();
            break;
    }
    aplicarComportamiento(genes, this->getComportamiento());
    return genes;
}

Celda**** Celda::getVecinos(){
    return this->vecinos;
}



int Celda::setCelula(Celula * cell){
    if (this->comportamiento == Contaminada){
        return -1;
    }
    if (this->celula==NULL){
        this->celula = cell;
        return 1;
    }
    else{
        return -1;
    }
}

void Celda::nacerCelula(int gen1, int gen2, int gen3){
    Celula * aux = new Celula(gen1,gen2,gen3);
    int seLogro = this->setCelula(aux);
    if (seLogro==-1){
        delete aux;
    }
}

void Celda::setTransmicion(tipoDeTransmicion tipoTransmicion){
    this->transmicion = tipoTransmicion;
}

void Celda::setComportamiento(comportamientoCelda nuevoComportamiento){
    this->comportamiento = nuevoComportamiento;
}

void Celda::setComportamientoRandom(){
    double random = (double)rand()/RAND_MAX;
    if (random<PROBABILIDAD_CELDA_INTERTE){
        this->setComportamiento(Inerte);
    }
    else{
        double probabilidadComportamientos = (1 - PROBABILIDAD_CELDA_INTERTE)/(CantidadComportamientos-1);
        for (int i=1; i<(CantidadComportamientos); i++){
            double probabilidadAcumulada = PROBABILIDAD_CELDA_INTERTE+(probabilidadComportamientos*(i));
            if (random<probabilidadAcumulada){
                this->setComportamiento((comportamientoCelda)(i));
                return;
            }
        }
    }
}

void Celda::setVecinos(Celda **** vectorVecinos){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            delete[] (this->vecinos)[i][j];
        }
        delete[] (this->vecinos)[i];
    }
    delete[] (this->vecinos);
    this->vecinos = vectorVecinos;
}


bool Celda::hayCelulaViva(){
    if (this->celula==NULL){
        return false;
    }
    return true;
}



void Celda::matarCelula(){
    if (this->getCelula()==NULL){
        throw "No se puede matar celula muerta.";
    }
    delete this->getCelula();
    this->celula=NULL;
}

int Celda::contarVecinos(){
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

void Celda::copiarCelda(Celda * celdaFuente){

    if (this->hayCelulaViva()){
        this->matarCelula();
    }
    
    Celula * celulaAux;
    if (celdaFuente->hayCelulaViva()){
        celulaAux = new Celula(celdaFuente->getCelula()->getCargaGeneticaGen1(),
                               celdaFuente->getCelula()->getCargaGeneticaGen2(),
                               celdaFuente->getCelula()->getCargaGeneticaGen3());
        this->celula=celulaAux;
    }
    else{
        this->celula=NULL;
    }
    
    this->setComportamiento(celdaFuente->getComportamiento());
    this->setTransmicion(celdaFuente->getTransmicion());
}

Celda::~Celda(){
    if (this->hayCelulaViva()){
        delete this->celula;
    }  
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            delete[] (this->vecinos)[i][j];
        }
        delete[] (this->vecinos)[i];
    }
    delete[] (this->vecinos);
}

int * Celda::getPromediosInvertidosVecinos(){
    int * genes = new int[3];
    genes[0] = 0;
    genes[1] = 0;
    genes[2] = 0;
    int cantidadVecinos = 0;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            for (int k = 0; k<3; k++){
                if (!(i==1 && j==1 && k==1)){
                    if(((this->vecinos)[i][j][k])->getCelula()!=NULL){
                        cantidadVecinos++;
                        genes[0] = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen1();
                        genes[1] = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen2();
                        genes[2] = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen3();
                    }
                }
            }
        }
    }
    genes[0] = MAXIMO_GEN-(genes[0]/cantidadVecinos);
    genes[1] = MAXIMO_GEN-(genes[1]/cantidadVecinos);
    genes[2] = MAXIMO_GEN-(genes[2]/cantidadVecinos);
    return genes;
}
int * Celda::getPromedioCuadraticoVecinos(){
    int * genes = new int[3];
    genes[0] = 0;
    genes[1] = 0;
    genes[2] = 0;
    int cantidadVecinos = 0;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            for (int k = 0; k<3; k++){
                if (!(i==1 && j==1 && k==1)){
                    if(((this->vecinos)[i][j][k])->getCelula()!=NULL){
                        cantidadVecinos++;
                        genes[0] = pow(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen1(),2);
                        genes[1] = pow(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen2(),2);
                        genes[2] = pow(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen3(),2);
                    }
                }
            }
        }
    }
    genes[0] = sqrt(genes[0]/cantidadVecinos);
    genes[1] = sqrt(genes[1]/cantidadVecinos);
    genes[2] = sqrt(genes[2]/cantidadVecinos);
    return genes;
}
int * Celda::getMinimoVecinos(){
    int * genes = new int[3];
    genes[0] = MAXIMO_GEN+1;
    genes[1] = MAXIMO_GEN+1;
    genes[2] = MAXIMO_GEN+1;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            for (int k = 0; k<3; k++){
                if (!(i==1 && j==1 && k==1)){
                    if(((this->vecinos)[i][j][k])->getCelula()!=NULL){
                        if(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen1() < genes[0]){
                            genes[0] = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen1();
                        }
                        if(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen2() < genes[1]){
                            genes[1] = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen2();
                        }
                        if(((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen3() < genes[2]){
                            genes[2] = ((this->vecinos)[i][j][k])->getCelula()->getCargaGeneticaGen3();
                        }
                    }
                }
            }
        }
    }
    genes[0] = genes[0]*1.1;
    if (genes[0]>MAXIMO_GEN){
        genes[0]=MAXIMO_GEN;
    }
    genes[1] = genes[1]*1.2;
    if (genes[1]>MAXIMO_GEN){
        genes[1]=MAXIMO_GEN;
    }
    genes[2] = genes[2]*1.3;
    if (genes[2]>MAXIMO_GEN){
        genes[2]=MAXIMO_GEN;
    }
    return genes;
}
