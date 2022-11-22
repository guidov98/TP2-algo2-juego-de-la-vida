#include "JuegoDeLaVida.h"
#include "Funciones.h"
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    Funciones::bienvenida();

	Configuraciones configuracion = (Configuraciones)0;//(Configuraciones)Funciones::elegirConfiguracion();

	//JuegoDeLaVida juego(configuracion);
    Decision decision = Continuar;
    JuegoDeLaVida *juego= new JuegoDeLaVida(configuracion);

    cout << "El tablero inicial es el siguiente: " << endl;
    juego->mostrarTablero();

    int n,m,l;
    cout << "1"<<endl;
    cin>>n;
    juego->actualizarJuego();
    juego->mostrarTablero();
    cout << "2"<<endl;
    cin>>m;
    juego->actualizarJuego();
    juego->mostrarTablero();
    cout << "3"<<endl;
    cin>>l;
    juego->actualizarJuego();
    juego->mostrarTablero();
    /*
    while(decision != Salir){
        decision =  juego->pedirDecision();

        if(decision == Continuar){
            int cantidadDeTurnos = juego->preguntarCantidadDeTurnos();
            for(int i = 0; i < cantidadDeTurnos; i++){
                juego->getTablero()->actualizarTablero(juego->getX1(), juego->getX2(), juego->getX3());
                juego->mostrarTablero();
            }
        }
        
        else if(decision == Reiniciar){
            //reiniciar juego de la vida 
        }
        
    }
    */
    delete juego;
    return 0;
}