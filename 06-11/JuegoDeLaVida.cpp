#include <iostream>
///#include "Tablero.h"
#include "Lista.h"
using namespace std;

JuegoDeLaVida::JuegoDeLaVida(){
    this->tablero = new Tablero(int n, int m, int l);
    this->graficos = new Visualizador();
}

JuegoDeLaVida::JuegoDeLaVida(){
    delete this->tablero;
    delete this->graficos;
}

void JuegoDeLaVida::iniciarConfiguracionUno(){
}

void JuegoDeLaVida::iniciarConfiguracionDos(){ 
}

void JuegoDeLaVida::iniciarConfiguracionTres(){   
}

void BatallaCampal::mostrarTablero(){

    //Aca va un for
        this->graficos->exportarImagen();

}

int main(){
	/*Lista<int> list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);
	for (int i = 0; i<6;i++){
		cout << list[i] << endl;
	}*/

	Lista<Lista<int>>list;
	Lista<int>temp;

	for (int i=1; i<5;i++){
		for (int j=1; j<5;j++){
			cout << "i:" << i << " j:" << j << " i+j;" << i+j<<endl;
			temp.add(i+j);
		}
		list.add(temp);
	}

	for (int i=0; i<5;i++){
		for (int j=0; j<5;j++){
			cout << ((list[i])[j]) << endl;
		}
	}
	
	return 0;
}
