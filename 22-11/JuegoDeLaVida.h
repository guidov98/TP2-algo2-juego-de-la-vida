#ifndef JUEGODELAVIDA_H_
#define JUEGODELAVIDA_H_
#include "Visualizador.h"

enum Configuraciones{
    Configuracion1,
    Configuracion2,
    Configuracion3,
    ConfiguracionManual
};

enum Decision{
    Continuar,
    Reinciar,
    Salir
};

class JuegoDeLaVida{

private:
    Tablero* tablero;
    Visualizador* graficos;
    tipoDeTransmicion transmicion;
    int x1;
    int x2;
    int x3;

    
    void iniciarConfiguracionUno();

    
    void iniciarConfiguracionDos();

    
    void iniciarConfiguracionTres();


    void iniciarConfiguracionManual();

public:
    /*
     * pre:
     * post:
     */
    JuegoDeLaVida(Configuraciones configuracion);

    void actualizarJuego();

    /*
    * pre: Juego de la Vida inicializado
    * post: Elimina Juego de la Vida
     */
    virtual ~JuegoDeLaVida();

    
    void elegirConfiguracion(int n);
    /*
    * pre: n, m, l deben estar en rango
    * post: 
    */
    void iniciarManual();
    /*
	 * pre: ---
	 * post: Exporta el tablero en imagenes bmp para visualiza  r.
	 */
    void mostrarTablero();

    int getX1();
    int getX2();
    int getX3();

    void elegirCelulasIniciales();

    Decision pedirDecision();
    
    int preguntarCantidadDeTurnos();
   
    Tablero *getTablero();

};

#endif