#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <cstdio>
#include <sstream>

#define clear() cout<<"\033[H\033[J"

enum Decision{
    Continuar,
    Reiniciar,
    Salir
};

class Funciones{
	public:
	static void espaciado(){
		std::cout << std::endl << std::endl;
	}

	static void bienvenida(){
		std::cout << "╔══════════════════════╗" << std::endl;
		std::cout << "║ JUEGO DE LA VIDA 2.0 ║" << std::endl;
		std::cout << "╚══════════════════════╝" << std::endl;
		std::cout << "╔═════════════════════════════════════════╗" << std::endl;
		std::cout << "║ Grupo: Modularizando                    ║" << std::endl;
		std::cout << "║                                         ║" << std::endl;
		std::cout << "║ Participantes:                          ║" << std::endl;
		std::cout << "║      - Guido Agustin Verde       104866 ║" << std::endl;
		std::cout << "║      - Cristian Julian Milidoni  107647 ║" << std::endl;
		std::cout << "║      - Ramiro Mantero            107162 ║" << std::endl;
		std::cout << "║      - Martin Ledesma            108068 ║" << std::endl;
		std::cout << "║      - Maximiliano Prantera      106888 ║" << std::endl;
		std::cout << "║      - Iara Jolodovsky           109385 ║" << std::endl;
		std::cout << "╚═════════════════════════════════════════╝" << std::endl;
	}

	static void despedida(){
		std::cout << "╔════════════════════╗" << std::endl;
		std::cout << "║ GRACIAS POR JUGAR! ║" << std::endl;
		std::cout << "╚════════════════════╝" << std::endl;
	}

	static std::string textoCongelado(bool estaCongelado){
		if (estaCongelado){
			return "Congelado";
		}
		return "Activo";
	}

	static void mostrarInformacion(int turno, int celulasNacidas, int celulasFallecidas, float promedioNacimientos, float promedioMuertes, bool estaCongelado){
		std::cout << "╔═══════════════════════════════════════≡" << std::endl;
		std::cout << "║ Turno:                      " << turno << std::endl;
		std::cout << "║ Nacimientos en este turno:  " << celulasNacidas << std::endl;
		std::cout << "║ Fallecidas en este turno:   " << celulasFallecidas << std::endl;
		std::cout << "║ Promedio de nacimientos:    " << promedioNacimientos << std::endl;
		std::cout << "║ Promedio de muertes:        " << promedioMuertes << std::endl;
		std::cout << "║ Estado:                     " << textoCongelado(estaCongelado) << std::endl;
		std::cout << "╚═══════════════════════════════════════≡" << std::endl;
	}

	static int pedirInput(int minimo){
		int output = 0;
		std::cin >> output;
		while(output<minimo){
			std::cout << std::endl;
			std::cout << "Ingrese un valor mayor a" << minimo << ": ";
			std::cin >> output;
		}
		return output;
	}
	static int pedirInput(int minimo, int maximo){
		int output = 0;
		std::cin >> output;
		while(output<minimo || output>maximo){
			std::cout << std::endl;
			std::cout << "Ingrese un valor entre " << minimo << " y " << maximo << ": ";
			std::cin >> output;
		}
		return output;
	}

	static Decision pedirDecision(bool conTurno){
		int respuesta;
		std::cout << "Que desea hacer?" << std::endl;
		if (conTurno){
			std::cout << "1 - Ejecutar un turno" << std::endl;
		}
		else{
			std::cout << "X - █▄▄▄▄▄▄▄ ▄▄ ▄▄▄▄▄" << std::endl;
		}
		
		std::cout << "2 - Reiniciar juego" << std::endl;
		std::cout << "3 - Salir del juego" << std::endl;
		if (conTurno){
			respuesta = Funciones::pedirInput(1,3);
		}
		else{
			respuesta = Funciones::pedirInput(2,3);
		}
		return (Decision)(respuesta-1);
	}

	static int preguntarCantidadDeTurnos(){
		int cantidadDeTurnos;
		std::cout<< "Ingrese la cantidad de turnos que quiere ejecutar: ";
		cantidadDeTurnos = Funciones::pedirInput(1);

		return cantidadDeTurnos;
	}

	static int elegirConfiguracion(){
		std::cout << "Quiere elegir una configuracion o prefiere elegir manualmente las celulas?" << std::endl;
		std::cout << "1- Configuracion 1" << std::endl;
		std::cout << "2- Configuracion 2" << std::endl;
		std::cout << "3- Configuracion 3" << std::endl;
		std::cout << "4- Configurar manualmente" << std::endl;
		return (pedirInput(1,4)-1);
	}

	static void eliminarArchivos(){
		for (int i=0; i<50; i++){
			std::stringstream alturaStr;
			alturaStr << i;
			std::string nombreArchivo = NOMBRE_ARCHIVO + alturaStr.str() + ".bmp";
			remove(nombreArchivo.c_str());
		}
	}

};





#endif