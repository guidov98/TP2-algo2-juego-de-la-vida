#include "Tablero.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>


void Tablero::setVecinosCelda(int x, int y, int z){
    Celda **** vectorVecinos = new Celda***[3];
	int contador = 0;
    for (int i=-1; i<2;i++){
        vectorVecinos[i+1]=new Celda**[3];
        for (int j=-1; j<2; j++){
            vectorVecinos[i+1][j+1]=new Celda*[3];
            for (int k=-1; k<2; k++){
				contador++;
				///std::cout << "x:" << x << " y:" << y << " z:" << z << " i:" << i << " j:" << j << " k:" << k << " n:"  << contador << std::endl;
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

Tablero::Tablero(int n, int m, int l){
	if (n<1 || m<1 || l<1) throw "Tablero imposible.";
	srand(time(NULL));
	this->N=n;
	this->M=m;
	this->L=l;
	this->tablero = new Lista<Lista<Lista<Celda*>*> *>;

	for(int i = 0; i < n; i++){
	    Lista<Lista<Celda *> *>* temp = new Lista<Lista<Celda*>*>;
	    for(int j = 0; j < m; j++){
	        Lista<Celda *> * temp2 = new Lista<Celda*>;
	        for(int k = 0; k < l; k++){
				int n = rand() % 2;
				Celda * temp3;
				if (n==1){
					temp3 = new Celda(new Celula);
					temp3->getCelula()->setGens(i*25+k*10,j*25+i*10,k*25+j*10);
				}
				else{
					temp3 = new Celda();
				}
				temp2->add(temp3);
	        }
	        temp->add(temp2);
	    }
	    tablero->add(temp);
	}
	this->setAllVecinos();
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


	return ((*(*(*(this->tablero))[i])[j])[k]);
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
				if (temp3->getCelula()!=NULL){
					int color1 = (temp3->getCelula()->getCargaGeneticaGen1());
					int color2 = (temp3->getCelula()->getCargaGeneticaGen2());
					int color3 = (temp3->getCelula()->getCargaGeneticaGen3());
					std::cout << "\x1b[38;2;"<<color1<<";"<<color2<<";"<<color3<<"m█\x1b[0m";
					std::cout << "\x1b[38;2;"<<color1<<";"<<color2<<";"<<color3<<"m█\x1b[0m";
				}
				else{
					std::cout << "\x1b[47;2;0;0;0m/\x1b[0m";
					std::cout << "\x1b[47;2;0;0;0m/\x1b[0m";
				}
			}
			std::cout << std::endl;
	    }
		std::cout << std::endl;
	}
	std::cout << this->getCeldaPos(0,0,0)->getCelula()->getCargaGeneticaGen1() << std::endl;
	std::cout << this->getCeldaPos(0,0,0)->getCelula()->getCargaGeneticaGen2() << std::endl;
	std::cout << this->getCeldaPos(0,0,0)->getCelula()->getCargaGeneticaGen3() << std::endl;
	std::cout << this->getCeldaPos(0,0,0)->contarVecinos() << std::endl;
	return 0;
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