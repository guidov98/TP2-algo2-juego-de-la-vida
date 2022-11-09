#include "Tablero.h"
#include <iostream>


void Tablero::setVecinosCelda(int x, int y, int z){
    Celda **** vectorVecinos = new Celda***[3];
    for (int i=0; i<3; i++){
        vectorVecinos[i]=new Celda**[3];
        for (int j=0; j<3; j++){
            vectorVecinos[i][j]=new Celda*[3];
            for (int k=0; k<3; k++){
                vectorVecinos[i][j][k]=NULL;
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
	this->N=n;
	this->M=m;
	this->L=l;
	this->tablero = new Lista<Lista<Lista<Celda*>*> *>;

	for(int i = 0; i < l; i++){
	    Lista<Lista<Celda *> *>* temp = new Lista<Lista<Celda*>*>;
	    for(int j = 0; j < m; j++){
	        Lista<Celda *> * temp2 = new Lista<Celda*>;
	        for(int k = 0; k < n; k++){
				Celda * temp3;
				temp3 = new Celda(new Celula);
				temp3->getCelula()->setGens(i*25,j*25,k*25);
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
	return ((*(*(*(this->tablero))[x])[y])[z]);
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
				}
			}
			std::cout << std::endl;
	    }
		std::cout << std::endl;
	}
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


