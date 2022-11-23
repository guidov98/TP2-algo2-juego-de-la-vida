#include "JuegoDeLaVida.h"
#include "Funciones.h"
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    Funciones::bienvenida();
	Configuraciones configuracion = (Configuraciones)Funciones::elegirConfiguracion();

    Decision decision = Continuar;
    JuegoDeLaVida *juego= new JuegoDeLaVida(configuracion);

    cout << "El tablero inicial es el siguiente: " << endl;
    juego->mostrarTablero();

    while(decision != Salir){
        decision =  juego->pedirDecision();
        if(decision == Continuar){
            int cantidadDeTurnos = juego->preguntarCantidadDeTurnos();
            for(int i = 0; i < cantidadDeTurnos; i++){
                juego->ejecutarTurno();
            }
        }
        
        else if(decision == Reiniciar){
            //reiniciar juego de la vida 
        }
        
    }
    
    delete juego;
    return 0;
}