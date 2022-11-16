#include <iostream>
#include "Tablero.h"
#include "Lista.h"
using namespace std;

/*
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

}*/

const int MAXIMOS_VECINOS = 26;
const int MINIMOS_VECINOS = 1;

int pedirInput(int minimo, int maximo){
	int output = 0;
	cin >> output;
	while(output<minimo || output>maximo){
		cout << endl;
		cout << "Ingrese un valor entre " << minimo << " y " << maximo << ": ";
		cin >> output;
	}
	return output;
}


int main(){
	/*
	
	int respuestaUsuario;

    cout << "Bienvenidos al Juego de la Vida V2.0!!!" << endl;

    //Inicializacion de Tablero:
	cout << "Se arma el campo de juego, elija que configuracion quiere jugar (Entre 1 y 3): " << endl;
    cin >> respuestaUsuario;

    switch(respuestaUsuario){
	case 1:
	  juegoDeLaVida->iniciarConfiguracionUno();
	  break;
	case 2:
	  juegoDeLaVida->iniciarConfiguracionDos();
	  break;
	case 3:
	  juegoDeLaVida->iniciarConfiguracionTres();
	  break;
	default:
	  break;
	}
	
	*/

	/*
	
	tipoDeTransmicion tipoTransmicion = Promedios;
	int n, m, l;
	int x1, x2, x3;
	cout << "Ingrese los valores del tamanio del tablero (entre 3 y 50):" << endl;
	cout << "N: ";
	n = 4;//pedirInput(3,50);

	cout << "M: ";
	m = 4;//pedirInput(3,50);

	cout << "L: ";
	l = 3;//pedirInput(3,50);

	cout << endl << endl;

	cout << "Ingrese la cantidad de celulas que debe haber alrededor" << endl;
	cout << "de una celula muerta para que nazca (1-26): ";
	x1 = 8;//pedirInput(MINIMOS_VECINOS, MAXIMOS_VECINOS);
	cout << endl << endl;

	cout << "Ingrese la cantidad MINIMA de celulas que debe haber" << endl;
	cout << "alrededor de una celula viva para que siga viva (1-26): ";
	x2 = 10;//pedirInput(MINIMOS_VECINOS, MAXIMOS_VECINOS);
	cout << endl << endl;

	cout << "Ingrese la cantidad MAXIMA de celulas que debe haber" << endl;
	cout << "alrededor de una celula viva para que siga viva (" << x2 << "-26): ";
	x3 = 13;//pedirInput(x2, MAXIMOS_VECINOS);
	cout << endl << endl;

	Tablero tablerin(n,m,l,tipoTransmicion);
	tablerin.imprimirTablero();
	cout << "LOL1" << endl;
	tablerin.actualizarTablero(x1,x2,x3);
	cout << "LOL2" << endl;
	tablerin.imprimirTablero();
	cout << "LOL3" << endl;

	*/
	return 0;
}