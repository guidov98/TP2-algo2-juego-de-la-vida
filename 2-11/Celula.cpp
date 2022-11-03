#include "Celula.h"

Celula::Celula(){
    this->gen1 = new Gen(255);
    this->gen2 = new Gen(255);
    this->gen3 = new Gen(255);
}
void Celula::setGen1(int cargaGenetica){
    this->gen1->setCargaGentica(cargaGenetica);
}

void Celula::setGen2(int cargaGenetica){
    this->gen2->setCargaGentica(cargaGenetica);
}

void Celula::setGen3(int cargaGenetica){
    this->gen3->setCargaGentica(cargaGenetica);
}

void Celula::setGens(int cargaGenetica1, int cargaGenetica2, int cargaGenetica3){
    this->setGen1(cargaGenetica1);
    this->setGen2(cargaGenetica2);
    this->setGen3(cargaGenetica3);
}

int Celula::getCargaGeneticaGen1(){
    return this->getGen1()->getCargaGentica();
}

int Celula::getCargaGeneticaGen2(){
    return this->getGen2()->getCargaGentica();
}

int Celula::getCargaGeneticaGen3(){
    return this->getGen3()->getCargaGentica();
}

Gen * Celula::getGen1(){
    return (this->gen1);
}
Gen * Celula::getGen2(){
    return (this->gen2);
}
Gen * Celula::getGen3(){
    return (this->gen3);
}