#include "JuegoDeLaVida.h"
#include "Funciones.h"
#include <ctime>
#include <cstdio>

using namespace std;

int main(){
    srand(time(NULL));
    clear();
    Funciones::espaciado();
    Funciones::bienvenida();
    Funciones::espaciado();
    Decision decision = Continuar;

    while (decision!=Salir){
        Funciones::eliminarArchivos();
        Configuraciones configuracion = (Configuraciones)Funciones::elegirConfiguracion();
        JuegoDeLaVida *juego= new JuegoDeLaVida(configuracion);

        int cantidadDeTurnos = Funciones::preguntarCantidadDeTurnos();
        bool tieneTurnos = juego->getTurnoActual()<=cantidadDeTurnos;
        clear();
        Funciones::espaciado();
        cout << "Se crearon las imagenes Tablero_Imagen_X.bmp," << endl;
        cout << "donde podra seguir el juego." << endl << endl;
	    Funciones::mostrarInformacion(1,juego->getCantidadCelulasVivas(),0,juego->getCantidadCelulasVivas(),0, false);
        juego->mostrarTablero();

        decision = Funciones::pedirDecision(tieneTurnos);
        while (decision==Continuar && tieneTurnos){
            clear();
            juego->ejecutarTurno();

            Funciones::espaciado();
            tieneTurnos = juego->getTurnoActual()<=cantidadDeTurnos;
            decision = Funciones::pedirDecision(tieneTurnos);
        }
        delete juego;
        clear();
    }
    Funciones::despedida();
    return 0;
}