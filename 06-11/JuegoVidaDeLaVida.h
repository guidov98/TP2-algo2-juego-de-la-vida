#include "tablero.h"
#include "Visualizador.h"

class JuegoDeLaVida{

private:
    Tablero* tablero;
    Visualizador* graficos;

public:
    /*
     * pre:
     * post:
     */
    JuegoDeLaVida();

    /*
    * pre: Juego de la Vida inicializado
    * post: Elimina Juego de la Vida
     */
    virtual ~JuegoDeLaVida();

    /*
    * pre: n, m, l deben estar en rango
    * post: inicia el tablero en la configuracion 1 ya preestablecido
    */
    void iniciarConfiguracionUno();

    /*
    * pre: n, m, l deben estar en rango
    * post: inicia el tablero en la configuracion 2 ya preestablecido
    */
    void iniciarConfiguracionDos();

    /*
    * pre: n, m, l deben estar en rango
    * post: inicia el tablero en la configuracion 3 ya preestablecido
    */
    void iniciarConfiguracionTres();

    /*
	 * pre: ---
	 * post: Exporta el tablero en imagenes bmp para visualizar.
	 */
    void mostrarTablero();

}
