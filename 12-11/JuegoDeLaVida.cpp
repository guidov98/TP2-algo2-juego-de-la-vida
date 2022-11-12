#include <iostream>
#include "Tablero.h"
#include "Lista.h"
using namespace std;

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
	tipoDeTransmicion tipoTransmicion;
	int n, m, l;
	int x1, x2, x3;
	cout << "Ingrese los valores del tamanio del tablero (N, M, L):" << endl;
	cout << "N: ";
	cin >> n;

	cout << "M: ";
	cin >> m;

	cout << "L: ";
	cin >> l;

	cout << endl << endl;

	cout << "Ingrese la cantidad de celulas que debe haber alrededor" << endl;
	cout << "de una celula muerta para que nazca (1-26): ";
	x1 = pedirInput(MINIMOS_VECINOS, MAXIMOS_VECINOS);
	cout << endl << endl;

	cout << "Ingrese la cantidad MINIMA de celulas que debe haber" << endl;
	cout << "alrededor de una celula viva para que siga viva (1-26): ";
	x2 = pedirInput(MINIMOS_VECINOS, MAXIMOS_VECINOS);
	cout << endl << endl;

	cout << "Ingrese la cantidad MAXIMA de celulas que debe haber" << endl;
	cout << "alrededor de una celula viva para que siga viva (" << x2 << "-26): ";
	x3 = pedirInput(x2, MAXIMOS_VECINOS);
	cout << endl << endl;

	Tablero tablerin(n,m,l,tipoTransmicion);
	///tablerin.imprimirTablero();
	return 0;
}