#include "Celda.h"

Celda::Celda(){
    comportamiento = Inerte;
    celula = new Celula;
}

Celda::Celda(comportamientoCelda state){
    comportamiento = state;
    celula = new Celula;
}

Celda::Celda(Celula * cell){
    comportamiento = Inerte;
    celula = cell;
}

Celda::Celda(comportamientoCelda state, Celula * cell){
    comportamiento = state;
    celula = cell;
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