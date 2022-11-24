#include "Tablero.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <time.h>

int copiarCelulasTablero(Lista<Lista<Lista<Celda *> *> *> * tableroDestino,
						 Lista<Lista<Lista<Celda *> *> *> * tableroFuente){
	int contadorCelulas = 0;
	tableroFuente->reiniciarCursor();
	tableroDestino->reiniciarCursor();
	while (tableroDestino->avanzarCursor()){
		tableroFuente->avanzarCursor();
	    Lista<Lista<Celda *> *> * temp = tableroDestino->getCursor();
		Lista<Lista<Celda *> *> * tempAux = tableroFuente->getCursor();
		temp->reiniciarCursor();
		tempAux->reiniciarCursor();
	    while(temp->avanzarCursor()){
			tempAux->avanzarCursor();
	    	Lista<Celda *> * temp2 = temp->getCursor();
	    	Lista<Celda *> * temp2Aux = tempAux->getCursor();
			temp2->reiniciarCursor();
			temp2Aux->reiniciarCursor();
			while(temp2->avanzarCursor()){
				temp2Aux->avanzarCursor();
				Celda * temp3 = temp2->getCursor();
				Celda * temp3Aux = temp2Aux->getCursor();
				if (temp3Aux->getCelula()!=NULL){
					contadorCelulas++;
				}
				temp3->copiarCelda(temp3Aux);
			}
	    }
	}
	return contadorCelulas;
}

void Tablero::setVecinosCelda(int x, int y, int z){
    Celda **** vectorVecinos = new Celda***[3];
	int contador = 0;
    for (int i=-1; i<2;i++){
        vectorVecinos[i+1]=new Celda**[3];
        for (int j=-1; j<2; j++){
            vectorVecinos[i+1][j+1]=new Celda*[3];
            for (int k=-1; k<2; k++){
				contador++;
				if (i==0 && j==0 && k==0){
					vectorVecinos[i+1][j+1][k+1]=NULL;
				}
				else{
                	vectorVecinos[i+1][j+1][k+1]=this->getCeldaPos(x+i,y+j,z+k);
				}
            } 
        }
    }
	this->getCeldaPos(x,y,z)->setVecinos(vectorVecinos);
}

void Tablero::setAllVecinos(){
	for(int i = 0; i < this->N; i++){
	    for(int j = 0; j < this->M; j++){
	        for(int k = 0; k < this->L; k++){
				this->setVecinosCelda(i,j,k);
	        }
	    }
	}
}

Tablero::Tablero(int n, int m, int l, tipoDeTransmicion tipoTransmicion){
	if (n<3 || m<3 || l<3) throw "Tablero imposible.";
	this->cantidadCelulas = 0;
	this->N=n;
	this->M=m;
	this->L=l;
	this->transmicion = tipoTransmicion;
	this->tablero = new Lista<Lista<Lista<Celda*>*> *>;
	for(int i = 0; i < l; i++){
	    Lista<Lista<Celda *> *>* temp = new Lista<Lista<Celda*>*>;
	    for(int j = 0; j < m; j++){
	        Lista<Celda *> * temp2 = new Lista<Celda*>;
	        for(int k = 0; k < n; k++){
				Celda * temp3 = new Celda();
				temp3->setComportamientoRandom();
				temp3->setTransmicion(tipoTransmicion);
				temp2->add(temp3);
	        }
	        temp->add(temp2);
	    }
	    tablero->add(temp);
	}
	this->setAllVecinos();
}

Tablero::Tablero(Tablero * tableroAux){
	this->N=tableroAux->getN();
	this->M=tableroAux->getM();
	this->L=tableroAux->getL();
	this->cantidadCelulas = tableroAux->getCantidadCelulas();
	this->transmicion = tableroAux->getTransmicionTablero();
	this->tablero = new Lista<Lista<Lista<Celda*>*> *>;
	tableroAux->getTablero()->reiniciarCursor();
	while(tableroAux->getTablero()->avanzarCursor()){
	    Lista<Lista<Celda *> *>* temp = new Lista<Lista<Celda*>*>;
	    while(tableroAux->getTablero()->getCursor()->avanzarCursor()){
	        Lista<Celda *> * temp2 = new Lista<Celda*>;
	        while(tableroAux->getTablero()->getCursor()->getCursor()->avanzarCursor()){
				Celda * temp3 = new Celda();
				Celda * temp3Aux = tableroAux->getTablero()->getCursor()->getCursor()->getCursor();
				temp3->setTransmicion(tableroAux->getTransmicionTablero());
				temp3->setComportamiento(temp3Aux->getComportamiento());
				if (temp3Aux->getCelula()!=NULL){
					Celula * aux = new Celula(temp3Aux->getCelula()->getCargaGeneticaGen1(),
											  temp3Aux->getCelula()->getCargaGeneticaGen2(),
											  temp3Aux->getCelula()->getCargaGeneticaGen3());
					temp3->setCelula(aux);
				}
				temp2->add(temp3);
	        }
	        temp->add(temp2);
	    }
	    tablero->add(temp);
	}
}

int Tablero::getN(){
	return this->N;
}
int Tablero::getM(){
	return this->M;
}
int Tablero::getL(){
	return this->L;
}
int Tablero::getCantidadCelulas(){
	return this->cantidadCelulas;
}

Lista<Lista<Lista<Celda *> *> *> * Tablero::getTablero(){
	return tablero;
}

Celda * Tablero::getCeldaPos(int x, int y, int z){
	int i = x;
	int j = y;
	int k = z;
	if (x<0){
		i = (this->N)+(x%(this->N));
	}
	if (y<0){
		j = (this->M)+(y%(this->M));
	}
	if (z<0){
		k = (this->L)+(z%(this->L));
	}
	if (x>=this->N){
		i = (x%(this->N));
	}
	if (y>=this->M){
		j = (y%(this->M));
	}
	if (z>=this->L){
		k = (z%(this->L));
	}

	return ((*(*(*(this->tablero))[k])[j])[i]);
}

tipoDeTransmicion Tablero::getTransmicionTablero(){
	return this->transmicion;
}

int Tablero::revivirCelulaPos(int x, int y, int z, int gen1, int gen2, int gen3){
	Celda * aux = this->getCeldaPos(x,y,z);
	if (aux->hayCelulaViva()){
		return 0;
	}
	else if(aux->getComportamiento()==Contaminada){
		return 0;
	}
	else{
		aux->nacerCelula(gen1, gen2, gen3);
		this->cantidadCelulas++;
		return 1;
	}
	return 0;
}

int Tablero::imprimirTablero(){
	this->tablero->reiniciarCursor();
	while (this->tablero->avanzarCursor()){
	    Lista<Lista<Celda *> *> * temp = this->tablero->getCursor();
		temp->reiniciarCursor();
	    while(temp->avanzarCursor()){
	    	Lista<Celda *> * temp2 = temp->getCursor();
			temp2->reiniciarCursor();
			while(temp2->avanzarCursor()){
				Celda * temp3 = temp2->getCursor();
				if (temp3->getCelula()==NULL){
					std::cout << "0";
				}
				else{
					std::cout << "1";
				}
			}
			std::cout << std::endl;
	    }
		std::cout << std::endl;
	}
	return 0;
}

void Tablero::agregarCelulaRandom(int gen1, int gen2, int gen3){
	int x;
	int y;
	int z;
	
	do{
		x = rand() % this->N;
		y = rand() % this->M;
		z = rand() % this->L;
	}while(this->getCeldaPos(x,y,z)->hayCelulaViva());
	Celula * aux = new Celula(gen1, gen2, gen3);
	int seAgrego = this->getCeldaPos(x,y,z)->setCelula(aux);
	if (seAgrego==-1){
		delete aux;
	}
	else{
		this->cantidadCelulas++;
	}
}

int Tablero::duplicarCelulas(Lista<Celula*> * celulasOrigen, int celulasPortales){
	int cantidadNacidas = 0;
	celulasOrigen->reiniciarCursor();
	while(celulasOrigen->avanzarCursor() &&
		  ((this->cantidadCelulas))<((this->N)*(this->M)*(this->L))){
		int gen1 = celulasOrigen->getCursor()->getCargaGeneticaGen1();
		int gen2 = celulasOrigen->getCursor()->getCargaGeneticaGen2();
		int gen3 = celulasOrigen->getCursor()->getCargaGeneticaGen3();
		this->agregarCelulaRandom(gen1, gen2, gen3);
		cantidadNacidas++;
	}
	return cantidadNacidas;
}

int Tablero::actualizarTablero(int x1, int x2, int x3){
	Lista<Celula*>*auxPortales = new Lista<Celula*>;
	Tablero * aux = new Tablero(this);
	int cantidadPortales = 0;
	int cantidadNacidas = 0;
	
	aux->getTablero()->reiniciarCursor();
	this->tablero->reiniciarCursor();
	while (this->tablero->avanzarCursor()){
		aux->getTablero()->avanzarCursor();
	    Lista<Lista<Celda *> *> * temp = this->tablero->getCursor();
		Lista<Lista<Celda *> *> * tempAux = aux->getTablero()->getCursor();
		temp->reiniciarCursor();
		tempAux->reiniciarCursor();
	    while(temp->avanzarCursor()){
			tempAux->avanzarCursor();
	    	Lista<Celda *> * temp2 = temp->getCursor();
	    	Lista<Celda *> * temp2Aux = tempAux->getCursor();
			temp2->reiniciarCursor();
			temp2Aux->reiniciarCursor();
			while(temp2->avanzarCursor()){
				temp2Aux->avanzarCursor();
				Celda * temp3 = temp2->getCursor();
				Celda * temp3Aux = temp2Aux->getCursor();
				int cantidadVecinos = temp3->contarVecinos();
				if (temp3->getCelula()==NULL){
					if (cantidadVecinos==x1 && temp3->getComportamiento()!=Contaminada){
						int * genes = temp3->getNewGenes();
						temp3Aux->nacerCelula(genes[0],genes[1],genes[2]);
						cantidadNacidas++;
						if (temp3->getComportamiento()==Portal){
							cantidadPortales++;
							auxPortales->add(temp3Aux->getCelula());
						}
						delete [] genes;
					}
				}
				else{
					if (!(cantidadVecinos>=x2 && cantidadVecinos<=x3)){
						temp3Aux->matarCelula();
					}
				}
			}
	    }
	}
	
	this->cantidadCelulas 			= copiarCelulasTablero(this->tablero, aux->getTablero());
	int celulasNacidasDePortales 	= duplicarCelulas(auxPortales, cantidadPortales);
	this->cantidadCelulas 		   += celulasNacidasDePortales;
	cantidadNacidas 			   += celulasNacidasDePortales;
	delete auxPortales;
	delete aux;
	return cantidadNacidas;
}

void Tablero::actualizarComportamientoCeldas(){
	this->tablero->reiniciarCursor();
	while (this->tablero->avanzarCursor()){
	    Lista<Lista<Celda *> *> * temp = this->tablero->getCursor();
		temp->reiniciarCursor();
	    while(temp->avanzarCursor()){
	    	Lista<Celda *> * temp2 = temp->getCursor();
			temp2->reiniciarCursor();
			while(temp2->avanzarCursor()){
				Celda * temp3 = temp2->getCursor();
				temp3->setComportamientoRandom();
			}
	    }
	}
}

Tablero::~Tablero(){
	this->tablero->reiniciarCursor();
	while (this->tablero->avanzarCursor()){
	    Lista<Lista<Celda *> *> * temp = this->tablero->getCursor();
		temp->reiniciarCursor();
	    while(temp->avanzarCursor()){
	    	Lista<Celda *> * temp2 = temp->getCursor();
			temp2->reiniciarCursor();
			while(temp2->avanzarCursor()){
				delete temp2->getCursor();
			}
			delete temp2;
	    }
		delete temp;
	}
	delete this->tablero;
}