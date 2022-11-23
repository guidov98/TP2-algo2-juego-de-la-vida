#ifndef JUEGODELAVIDA_H_
#define JUEGODELAVIDA_H_
#include "Visualizador.h"

enum Configuraciones{
    Configuracion1,
    Configuracion2,
    Configuracion3,
    ConfiguracionManual
};


class JuegoDeLaVida{

private:
    Tablero * tablero;
    Visualizador * graficos;
    tipoDeTransmicion transmicion;
    int x1;
    int x2;
    int x3;
    int nacimientosTotales;
    int muertesTotales;
    int turnoActual;

    
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

    int getTurnoActual();
    int getNacimientosTotales();
    int getMuertesTotales();
    int getCelulasVivas();

    void setNacimientosTotales(int);
    void setMuertesTotales(int);
    void setCelulasVivas(int);

    void elegirCelulasIniciales();
    void ejecutarTurno();
};

#endif