/*
 * Tablero.cpp
 *
 *  Created on: 30 oct. 2022
 *      Author: guido
 */
#include "Tablero.h"
Tablero::Tablero(int n, int m, int l){
	this->N=n;
	this->M=m;
	this->L=l;
	this->tablero = new Lista<Lista<Lista<Celda*>*> *> *;

	    for(int i = 0; i < n; i++){
	        Lista<Lista<Celda *> *>* temp = new Lista<Lista<Celda*>*>*;
	        tablero->agregar(temp);
	        for(int j = 0; j < m; j++){
	            Lista<Celda *> * temp2 = new Lista<Celda*>*;
	            for(int k = 0; k < l; k++){
	            	Celda * temp3 = new Celda*;
	            	temp2->agregar(temp3);
	            }
	            temp->agregar(temp2);
	        }

	    }
	}
}



