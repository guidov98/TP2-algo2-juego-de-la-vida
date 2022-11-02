#include "Celula.h"

Celula::Celula(){
    this->gen1 = new Gen;
    this->gen2 = new Gen;
    this->gen3 = new Gen;
}
Celula::Celula(int gene1, int gene2, int gene3){
    gen1 = new Gen(255,0);
    gen2 = new Gen(255,0);
    gen3 = new Gen(255,0);
}
void Celula::setGen1(Gen gene){
    *(this->gen1) = gene;
}

void Celula::setGen2(Gen gene){
    *(this->gen2) = gene;
}

void Celula::setGen3(Gen gene){
    *(this->gen3) = gene;
}

void Celula::setGens(Gen gene1, Gen gene2, Gen gene3){
    this->setGen1(gene1);
    this->setGen2(gene2);
    this->setGen3(gene3);
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