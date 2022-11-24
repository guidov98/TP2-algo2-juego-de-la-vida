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

/*	Pre: -
	Post: Setea el JuegoDeLaVida con una configuracion preestablecida */
    void iniciarConfiguracionUno();

/*	Pre: -
	Post: Setea el JuegoDeLaVida con una configuracion preestablecida */
    void iniciarConfiguracionDos();

/*	Pre: -
	Post: Setea el JuegoDeLaVida con una configuracion preestablecida */
    void iniciarConfiguracionTres();

/*	Pre: -
	Post: Setea el JuegoDeLaVida con la configuracion elegida por el usuario */
    void iniciarConfiguracionManual();


public:

    /*
     * pre:
     * post: Crea el JuegoDeLaVida con la configuracion indicada
     */
    JuegoDeLaVida(Configuraciones configuracion);

    void actualizarJuego();

    /*
    * pre: Juego de la Vida inicializado
    * post: Elimina Juego de la Vida
     */
    virtual ~JuegoDeLaVida();

/*	Pre: n debe estar entre 1 y 3
	Post: Setea la configuracion con el numero de configuracion indicado*/
    void elegirConfiguracion(int n);

    /*
	 * pre: ---
	 * post: Exporta el tablero en imagenes bmp para visualiza  r.
	 */
    void mostrarTablero();

/*	Pre: -
	Post: Devuelve el x1 del JuegoDeLaVida*/
    int getX1();

/*	Pre: -
	Post: Devuelve el x2 del JuegoDeLaVida*/
    int getX2();

/*	Pre: -
	Post: Devuelve el x3 del JuegoDeLaVida*/
    int getX3();

/*	Pre: -
	Post: Devuelve la cantidad de celulas vivas del Tablero*/
    int getCantidadCelulasVivas();

/*	Pre: -
	Post: Devuelve el numero de turno actual del JuegoDeLaVida*/
    int getTurnoActual();

/*	Pre: -
	Post: Devuelve la cantidad de nacimientos totales del JuegoDeLaVida*/
    int getNacimientosTotales();

/*	Pre: -
	Post: Devuelve la cantidad de muertes totales del JuegoDeLaVida*/
    int getMuertesTotales();

/*	Pre: -
	Post: Setea la cantidad de nacimientos totales del JuegoDeLaVida*/
    void setNacimientosTotales(int);

/*	Pre: -
	Post: Setea la cantidad de muertes totales del JuegoDeLaVida*/
    void setMuertesTotales(int);

/*	Pre: -
	Post: Setea la cantidad de Celulas vivas del JuegoDeLaVida*/
    void setCelulasVivas(int);

/*	Pre: -
	Post: Setea las Celulas vivas iniciales del JuegoDeLaVida*/
    void elegirCelulasIniciales();

/*	Pre: -
	Post: Ejecuta un turno del JuegoDeLaVida*/
    void ejecutarTurno();
};

#endif