#include "JuegoDeLaVida.h"
#include "Funciones.h"



JuegoDeLaVida::JuegoDeLaVida(Configuraciones configuracion){

	switch(configuracion){
        case(Configuracion1):
            iniciarConfiguracionUno();
            break;
        case(Configuracion2):
            iniciarConfiguracionDos();
            break;
        case(Configuracion3):
            iniciarConfiguracionTres();
            break;
        case(ConfiguracionManual):
            iniciarConfiguracionManual();
            break;
    }

	this->muertesTotales = 0;
	this->turnoActual = 1;
    this->graficos = new Visualizador(this->tablero->getN(), this->tablero->getM());
}

JuegoDeLaVida::~JuegoDeLaVida(){
    delete this->tablero;
    delete this->graficos;
}

void JuegoDeLaVida::iniciarConfiguracionUno(){
	this->tablero = new Tablero(5,5,5, InvertirProgenitores);
	this->transmicion = PromediosCuadrados;
	this->x1 = 2;
	this->x2 = 5;
	this->x3 = MAXIMOS_VECINOS;

	//x=5,y=3,z=7, gen1=x*25, gen2=y*25
	for (int i = 0; i < 5; i++){
		this->tablero->revivirCelulaPos(i,i,1,i*50,i*50,1*50);
    }
	this->nacimientosTotales = 5;
	
}

void JuegoDeLaVida::iniciarConfiguracionDos(){
	this->tablero = new Tablero(5,5,5, PromediosCuadrados);
	this->transmicion = InvertirProgenitores;
	this->x1 = 3;
	this->x2 = 2;
	this->x3 = 4;

	this->tablero->revivirCelulaPos(1,3,1,250,250,0);
	this->tablero->revivirCelulaPos(2,3,1,250,210,40);
	this->tablero->revivirCelulaPos(3,3,1,250,170,80);
	this->tablero->revivirCelulaPos(3,2,1,250,130,120);
	this->tablero->revivirCelulaPos(2,1,1,250,90,160);
	this->nacimientosTotales = 5;
	
}

void JuegoDeLaVida::iniciarConfiguracionTres(){
	this->tablero = new Tablero(5,7,4, Minimos);
	this->transmicion = Minimos;
	this->x1 = 4;
	this->x2 = 8;
	this->x3 = 13;
	for (int i=0; i<5; i++){
		for (int j=0; j<2; j++){
			this->tablero->revivirCelulaPos(i,	0,	j*3,	50,	100,25);
			this->tablero->revivirCelulaPos(i,	6,	j*3,	200,5,	150);
			this->tablero->revivirCelulaPos(0,	i+1,j*3,	5,	5,	150);
			this->tablero->revivirCelulaPos(4,	i+1,j*3,	5,	5,	5);
		}
	}
	for (int i=1; i<3; i++){
		this->tablero->revivirCelulaPos(0,0,i,0,0,0);
		this->tablero->revivirCelulaPos(4,0,i,0,0,0);
		this->tablero->revivirCelulaPos(0,6,i,0,0,0);
		this->tablero->revivirCelulaPos(4,6,i,0,0,0);
	}
	this->nacimientosTotales = 7;
	
}

void JuegoDeLaVida::iniciarConfiguracionManual(){
    tipoDeTransmicion tipoTransmicion;
	int n, m, l;
	int x1user, x2user, x3user;

	std::cout << "Ingrese los valores del tamanio del tablero (entre 3 y 50):" << std::endl;
	std::cout << "N: ";
	n = Funciones::pedirInput(3,50);
	std::cout << "M: ";
	m = Funciones::pedirInput(3,50);
	std::cout << "L: ";
	l = Funciones::pedirInput(3,50);

	std::cout << "Que tipo de transmicion quiere?" << std::endl;
	std::cout << "1- Promedios" << std::endl;
	std::cout << "2- Promedios Cuadraticos" << std::endl;
	std::cout << "3- Minimos" << std::endl;
	tipoTransmicion = (tipoDeTransmicion)Funciones::pedirInput(1,3);
	std::cout << std::endl << std::endl;

	std::cout << "Ingrese la cantidad de celulas que debe haber alrededor" << std::endl;
	std::cout << "de una celula muerta para que nazca (0-26): ";
	x1user = Funciones::pedirInput(MINIMOS_VECINOS, MAXIMOS_VECINOS);
	std::cout << std::endl << std::endl;

	std::cout << "Ingrese la cantidad MINIMA de celulas que debe haber" << std::endl;
	std::cout << "alrededor de una celula viva para que siga viva (0-26): ";
	x2user = Funciones::pedirInput(MINIMOS_VECINOS, MAXIMOS_VECINOS);
	std::cout << std::endl << std::endl;

	std::cout << "Ingrese la cantidad MAXIMA de celulas que debe haber" << std::endl;
	std::cout << "alrededor de una celula viva para que siga viva (" << x2 << "-26): ";
	x3user = Funciones::pedirInput(x2, MAXIMOS_VECINOS);
	std::cout << std::endl << std::endl;
    
    this->x1 = x1user;
    this->x2 = x2user;
    this->x3 = x3user;

    this->tablero = new Tablero(n, m, l,tipoTransmicion);
    
    elegirCelulasIniciales();
}

int JuegoDeLaVida::getX1(){
    return this->x1;
}
int JuegoDeLaVida::getX2(){
    return this->x2;
}
int JuegoDeLaVida::getX3(){
    return this->x3;
}

int JuegoDeLaVida::getTurnoActual(){
	return this->turnoActual;
}

//tablero->getCeldaPos(1,1,1)->nacerCelula();
void JuegoDeLaVida::elegirCelulasIniciales(){
	int cantidadCelulas = 0;
    std::cout << "Ingrese la cantidad de celulas iniciales: ";
    std::cin >> cantidadCelulas;
    std::cout << std::endl;

    int celulaPosicion[3];
	int celulaGen[3];

    for (int i = 0; i < cantidadCelulas; i++){
        std::cout << "Ingrese la coordenada x de la celula a nacer: ";
        celulaPosicion[0] = Funciones::pedirInput(1,this->tablero->getL());
		std::cout << std::endl;
            
        std::cout << "Ingrese la coordenada y de la celula a nacer: ";
        celulaPosicion[1] = Funciones::pedirInput(1,this->tablero->getL());
        std::cout << std::endl;

        std::cout << "Ingrese la coordenada z de la celula a nacer: ";
        celulaPosicion[2] = Funciones::pedirInput(1,this->tablero->getN());
        std::cout << std::endl;


        std::cout << "Ingrese el gen1 de la celula a nacer: ";
        celulaGen[0] = Funciones::pedirInput(0,255);
		std::cout << std::endl;
            
        std::cout << "Ingrese el gen2 de la celula a nacer: ";
        celulaGen[1] = Funciones::pedirInput(0,255);
        std::cout << std::endl;

        std::cout << "Ingrese el gen3 de la celula a nacer: ";
        celulaGen[2] = Funciones::pedirInput(0,255);
        std::cout << std::endl;
		//revivirCelulaPos(int x, int y, int z, int gen1, int gen2, int gen3)
		this->tablero->revivirCelulaPos(celulaPosicion[0]-1, celulaPosicion[1]-1,celulaPosicion[2]-1,celulaGen[0],celulaGen[1],celulaGen[2]);
    }
	this->nacimientosTotales = cantidadCelulas;
	
}


void JuegoDeLaVida::actualizarJuego(){
	this->tablero->actualizarTablero(this->x1, this->x2, this->x3);
}

void JuegoDeLaVida::mostrarTablero(){
	int altura = this->tablero->getL();

	for(int i=0; i<altura; i++){
		this->graficos->dibujarCapa(this->tablero, i);
		this->graficos->exportarImagen(i);
	}

}

int JuegoDeLaVida::getNacimientosTotales(){
	return this->nacimientosTotales;
}

int JuegoDeLaVida::getMuertesTotales(){
	return this->muertesTotales;
}


void JuegoDeLaVida::setNacimientosTotales(int cantidad){
	this->nacimientosTotales = cantidad;
}

void JuegoDeLaVida::setMuertesTotales(int cantidad){
	this->muertesTotales = cantidad;
}

void mostrarInformacion(int turno, int celulasNacidas, int celulasFallecidas, float promedioNacimientos, float promedioMuertes){
	std::cout << "╔═════════════════════════════════≡" << std::endl;
	std::cout << "║ Turno:                      " << turno << std::endl;
	std::cout << "║ Nacimientos en este turno:  " << celulasNacidas << std::endl;
	std::cout << "║ Fallecidas en este turno:   " << celulasFallecidas << std::endl;
	std::cout << "║ Promedio de nacimientos a:  " << promedioNacimientos << std::endl;
	std::cout << "║ Promedio de muertes:        " << promedioMuertes << std::endl;
	std::cout << "╚═════════════════════════════════≡" << std::endl;
}

void JuegoDeLaVida::ejecutarTurno(){
	int celulasNacidas = 0;
    int celulasFallecidas = 0;

	int celulasPrevias = this->tablero->getCantidadCelulas();
	celulasNacidas = this->tablero->actualizarTablero(this->getX1(), this->getX2(), this->getX3());
	int celulasActuales = this->tablero->getCantidadCelulas();
	celulasFallecidas= celulasNacidas - (celulasActuales - celulasPrevias); 
	
	this->nacimientosTotales += celulasNacidas;
	this->muertesTotales += celulasFallecidas;
	this->turnoActual++;
	float promedioNacimientos = this->nacimientosTotales / this->turnoActual;
	float promedioMuertes = this->muertesTotales / this->turnoActual;
	this->mostrarTablero();
	mostrarInformacion(this->turnoActual, celulasNacidas, celulasFallecidas, promedioNacimientos, promedioMuertes);
}

