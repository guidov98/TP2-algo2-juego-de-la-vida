#include "Tablero.h"
#include <iostream>

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
	        	Celda * temp3 = new Celda;
				temp3->getCelula()->getGen1()->setCargaGentica((i*50));
				temp3->getCelula()->getGen2()->setCargaGentica((j*50));
				temp3->getCelula()->getGen3()->setCargaGentica((k*25));
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
				//cout << "\x1b[38;2;255;100;0m■\x1b[0m\n";
				int color1 = (temp3->getCelula()->getGen1()->getCargaGentica());
				int color2 = (temp3->getCelula()->getGen2()->getCargaGentica());
				int color3 = (temp3->getCelula()->getGen3()->getCargaGentica());
				std::cout << "\x1b[38;2;"<<color1<<";"<<color2<<";"<<color3<<"m█\x1b[0m";
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


